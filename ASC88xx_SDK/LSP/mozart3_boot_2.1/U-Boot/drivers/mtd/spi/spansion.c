/*
 * Copyright (C) 2009 Freescale Semiconductor, Inc.
 *
 * Author: Mingkai Hu (Mingkai.hu@freescale.com)
 * Based on stmicro.c by Wolfgang Denk (wd@denx.de),
 * TsiChung Liew (Tsi-Chung.Liew@freescale.com),
 * and  Jason McMullan (mcmullan@netapp.com)
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <malloc.h>
#include <asm/sizes.h>
#include <spi_flash.h>

#include "spi_flash_internal.h"

/* S25FLxx-specific commands */
#define CMD_S25FLXX_READ	0x03	/* Read Data Bytes */
#define CMD_S25FLXX_FAST_READ	0x0b	/* Read Data Bytes at Higher Speed */
#define CMD_S25FLXX_READID	0x90	/* Read Manufacture ID and Device ID */
#define CMD_S25FLXX_WREN	0x06	/* Write Enable */
#define CMD_S25FLXX_WRDI	0x04	/* Write Disable */
#define CMD_S25FLXX_RDSR	0x05	/* Read Status Register */
#define CMD_S25FLXX_WRSR	0x01	/* Write Status Register */
#define CMD_S25FLXX_PP		0x02	/* Page Program */
#define CMD_S25FLXX_SE		0xd8	/* Sector Erase */
#define CMD_S25FLXX_BE		0xc7	/* Bulk Erase */
#define CMD_S25FLXX_DP		0xb9	/* Deep Power-down */
#define CMD_S25FLXX_RES		0xab	/* Release from DP, and Read Signature */

#define CMD_S25FLXX_BRRD		0x16
#define CMD_S25FLXX_BRWR		0x17
	
#define SPSN_ID_S25FL008A	0x0213
#define SPSN_ID_S25FL016A	0x0214
#define SPSN_ID_S25FL032A	0x0215
#define SPSN_ID_S25FL064A	0x0216
#define SPSN_ID_S25FL128P	0x2018
#define SPSN_ID_S25FL256S	0x0219
#define SPSN_EXT_ID_S25FL128P_256KB	0x0300
#define SPSN_EXT_ID_S25FL128P_64KB	0x0301
#define SPSN_EXT_ID_S25FL256S_256KB	0x4d01

#define SPANSION_SR_WIP		(1 << 0)	/* Write-in-Progress */
#define SPANSION_BR_EXTADD 0x80

struct spansion_spi_flash_params {
	u16 idcode1;
	u16 idcode2;
	u16 page_size;
	u16 pages_per_sector;
	u16 nr_sectors;
	const char *name;
};

struct spansion_spi_flash {
	struct spi_flash flash;
	uint32_t flags;
	const struct spansion_spi_flash_params *params;
};

static inline struct spansion_spi_flash *to_spansion_spi_flash(struct spi_flash
							     *flash)
{
	return container_of(flash, struct spansion_spi_flash, flash);
}

static const struct spansion_spi_flash_params spansion_spi_flash_table[] = {
	{
		.idcode1 = SPSN_ID_S25FL008A,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 16,
		.name = "S25FL008A",
	},
	{
		.idcode1 = SPSN_ID_S25FL016A,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 32,
		.name = "S25FL016A",
	},
	{
		.idcode1 = SPSN_ID_S25FL032A,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 64,
		.name = "S25FL032A",
	},
	{
		.idcode1 = SPSN_ID_S25FL064A,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 128,
		.name = "S25FL064A",
	},
	{
		.idcode1 = SPSN_ID_S25FL128P,
		.idcode2 = SPSN_EXT_ID_S25FL128P_64KB,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 256,
		.name = "S25FL128P_64K",
	},
	{
		.idcode1 = SPSN_ID_S25FL128P,
		.idcode2 = SPSN_EXT_ID_S25FL128P_256KB,
		.page_size = 256,
		.pages_per_sector = 1024,
		.nr_sectors = 64,
		.name = "S25FL128P_256K",
	},
	{
		.idcode1 = SPSN_ID_S25FL256S,
		.idcode2 = SPSN_EXT_ID_S25FL256S_256KB,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 512,
		.name = "S25FL256S_64K",
	},
};


/*
 * enter_4_byte_mode()
 * Return: 0, 3 byte address
 *         1, 4 byte address
 *         else, error
 */
static int _enter_4_byte_mode(struct spi_flash *flash)
{
	int ret;
	u8 cmd = CMD_S25FLXX_BRWR;
	u8 br = SPANSION_BR_EXTADD;

#if 1
	ret = spi_flash_cmd_write(flash->spi, &cmd, 1, &br, 1);
	if (ret) {
		debug("SF: Failed to send command %02x: %d\n", CMD_S25FLXX_BRWR, ret);
		return -1;
	}

	cmd = CMD_S25FLXX_BRRD;
	ret = spi_flash_read_common(flash, &cmd, 1, &br, 1);
	if (ret) {
		debug("SF: Failed to send command %02x: %d\n", br, ret);
		return -1;
	}

	debug("status bit of 4-byte mode: %lu\n", br & BIT_MASK(7));
	return (br & BIT_MASK(7)) != 0;
#else
	return 0;
#endif

}

static int enter_4_byte_mode(struct spi_flash *flash)
{
	struct spansion_spi_flash *spsn = to_spansion_spi_flash(flash);
	int ret = 0;

	if ((spsn->flags & (ADDR_4_BYTE_SUPPORT|ADDR_4_BYTE_ENTERED))
		== ADDR_4_BYTE_SUPPORT)
	{
		ret = _enter_4_byte_mode(flash);
		if (ret == 1)
			spsn->flags |= ADDR_4_BYTE_ENTERED;
	}

	debug("%s 4-byte address mode\n", (spsn->flags & ADDR_4_BYTE_ENTERED) ? "is" : "not");
	return (spsn->flags & ADDR_4_BYTE_ENTERED) == ADDR_4_BYTE_ENTERED;
}

static int spansion_wait_ready(struct spi_flash *flash, unsigned long timeout)
{
	struct spi_slave *spi = flash->spi;
	unsigned long timebase;
	int ret;
	u8 status;
	
	timebase = get_timer(0);
	do {
		
		ret = spi_flash_cmd(spi, CMD_S25FLXX_RDSR, &status, sizeof(status));
		
		if (ret)
			return -1;

		if ((status & SPANSION_SR_WIP) == 0)
			break;

	} while (get_timer(timebase) < timeout);

	if ((status & SPANSION_SR_WIP) == 0)
		return 0;

	/* Timed out */
	return -1;
}

static int spansion_read_fast(struct spi_flash *flash,
			     u32 offset, size_t len, void *buf, int quiet)
{
	struct spansion_spi_flash *spsn = to_spansion_spi_flash(flash);
	unsigned long page_addr;
	unsigned long page_size;
	u8 cmd[6], i= 1, ret= 0;
	int addr_4byte = 0;

	addr_4byte = enter_4_byte_mode(flash);
	if (addr_4byte < 0)
		return addr_4byte;

	page_size = spsn->params->page_size;
	page_addr = offset / page_size;

	cmd[0] = CMD_READ_ARRAY_FAST;
	if (addr_4byte)
		cmd[i++] = page_addr >> 16;
	cmd[i++] = page_addr >> 8;
	cmd[i++] = page_addr;
	cmd[i++] = offset % page_size;
	cmd[i++] = 0x00;

	debug
		("READ: 0x%x => cmd = { 0x%02x 0x%02x%02x%02x%02x } len = 0x%x, page_size:0x%x\n",
		 offset, cmd[0], cmd[1], cmd[2], cmd[3], cmd[4], len, page_size);
		 
	ret = spi_flash_read_common(flash, cmd, i, buf, len); 
		
	return ret;
}

static int spansion_write(struct spi_flash *flash,
			 u32 offset, size_t len, const void *buf, int quiet)
{
	struct spansion_spi_flash *spsn = to_spansion_spi_flash(flash);
	unsigned long page_addr;
	unsigned long byte_addr;
	unsigned long page_size;
	size_t chunk_len;
	size_t actual;
	int ret;
	u8 cmd[6], i= 1;
	int addr_4byte = 0;

	addr_4byte = enter_4_byte_mode(flash);
	if (addr_4byte < 0)
		return addr_4byte;

	page_size = spsn->params->page_size;
	page_addr = offset / page_size;
	byte_addr = offset % page_size;

		
	ret = spi_claim_bus(flash->spi);
	if (ret) {
		debug("SF: Unable to claim SPI bus\n");
		return ret;
	}

	ret = 0;
	for (actual = 0; actual < len; actual += chunk_len) {
		chunk_len = min(len - actual, page_size - byte_addr);

		cmd[0] = CMD_S25FLXX_PP;
		i = 1;
		if (addr_4byte)
			cmd[i++] = offset >> 24;
		cmd[i++] = offset >> 16;
		cmd[i++] = offset >> 8;
		cmd[i++] = offset;

		debug
		    ("PP: 0x%p  chunk_len = %d offset = %d => cmd = { 0x%02x 0x%02x%02x%02x",
		     buf + actual, chunk_len, offset, cmd[0], cmd[1], cmd[2], cmd[3]);
		if (addr_4byte) debug("%02x", cmd[4]);
		debug(" }\n");

		ret = spi_flash_cmd(flash->spi, CMD_S25FLXX_WREN, NULL, 0);
		if (ret < 0) {
			debug("SF: Enabling Write failed\n");
			break;
		}

		ret = spi_flash_cmd_write(flash->spi, cmd, i,
					  buf + actual, chunk_len);
		if (ret < 0) {
			debug("SF: SPANSION Page Program failed\n");
			break;
		}

		ret = spansion_wait_ready(flash, SPI_FLASH_PROG_TIMEOUT);
		if (ret < 0) {
			debug("SF: SPANSION page programming timed out\n");
			break;
		}

		byte_addr = 0;
		offset += chunk_len;
	}

	debug("SF: SPANSION: Successfully programmed %u bytes @ 0x%x\n",
	      len, offset);

	spi_release_bus(flash->spi);
	return ret;
}

int spansion_erase(struct spi_flash *flash, u32 offset, size_t len)
{
	struct spansion_spi_flash *spsn = to_spansion_spi_flash(flash);
	unsigned long sector_size;
	size_t actual;
	int ret;
	u8 cmd[4] = {0};
	int addr_4byte = 0;

	/*
	 * This function currently uses sector erase only.
	 * probably speed things up by using bulk erase
	 * when possible.
	 */

	sector_size = spsn->params->page_size * spsn->params->pages_per_sector;

	if (offset % sector_size || len % sector_size) {
		debug("SF: Erase offset/length not multiple of sector size\n");
		return -1;
	}
	
	addr_4byte = enter_4_byte_mode(flash);
	if (addr_4byte < 0)
		return addr_4byte;

	ret = spi_claim_bus(flash->spi);
	if (ret) {
		debug("SF: Unable to claim SPI bus\n");
		return ret;
	}

	ret = 0;
	cmd[0] = CMD_S25FLXX_SE;
	for (actual = 0; actual < len; actual += sector_size, offset += sector_size) {
		int i = 1;
		if (addr_4byte)
			cmd[i++] = offset >> 24;
		cmd[i++] = offset >> 16;
		cmd[i++] = offset >> 8;
		cmd[i++] = offset;
		
		debug
		    ("SE: 0x%p => cmd = { 0x%02x 0x%02x%02x%02x } \n",
		     offset, cmd[0], cmd[1], cmd[2], cmd[3]);
		     
		ret = spi_flash_cmd(flash->spi, CMD_S25FLXX_WREN, NULL, 0);
		if (ret < 0) {
			debug("SF: Enabling Write failed\n");
			break;
		}

		ret = spi_flash_cmd_write(flash->spi, cmd, i, NULL, 0);
		if (ret < 0) {
			debug("SF: SPANSION page erase failed\n");
			break;
		}
		/* Up to 2 seconds */
		ret = spansion_wait_ready(flash, SPI_FLASH_PAGE_ERASE_TIMEOUT);
		if (ret < 0) {
			debug("SF: SPANSION page erase timed out\n");
			break;
		}
	}

	debug("SF: SPANSION: Successfully erased %u bytes @ 0x%x\n",
	      len * sector_size, offset);

	spi_release_bus(flash->spi);
	return ret;
}

struct spi_flash *spi_flash_probe_spansion(struct spi_slave *spi, u8 *idcode)
{
	const struct spansion_spi_flash_params *params;
	struct spansion_spi_flash *spsn;
	unsigned int i;
	unsigned short jedec, ext_jedec;

	jedec = idcode[1] << 8 | idcode[2];
	ext_jedec = idcode[3] << 8 | idcode[4];

	for (i = 0; i < ARRAY_SIZE(spansion_spi_flash_table); i++) {
		params = &spansion_spi_flash_table[i];
		if (params->idcode1 == jedec) {
			if (params->idcode2 == ext_jedec)
				break;
		}
	}

	if (i == ARRAY_SIZE(spansion_spi_flash_table)) {
		debug("SF: Unsupported SPANSION ID %04x %04x\n", jedec, ext_jedec);
		return NULL;
	}

	spsn = malloc(sizeof(struct spansion_spi_flash));
	if (!spsn) {
		debug("SF: Failed to allocate memory\n");
		return NULL;
	}

	spsn->params = params;
	spsn->flash.spi = spi;
	spsn->flash.name = params->name;

	spsn->flash.write = spansion_write;
	spsn->flash.erase = spansion_erase;
	spsn->flash.read = spansion_read_fast;
	spsn->flash.size = params->page_size * params->pages_per_sector
	    * params->nr_sectors;
	spsn->flags = (spsn->flash.size > SZ_16M ? ADDR_4_BYTE_SUPPORT : 0);

	printf("SF: Detected %s with page size %u, total ",
	       params->name, params->page_size);
	print_size(spsn->flash.size, "\n");

	return &spsn->flash;
}
