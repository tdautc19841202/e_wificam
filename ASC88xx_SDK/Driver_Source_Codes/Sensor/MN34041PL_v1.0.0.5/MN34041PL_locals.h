/*
 *
 * Copyright (C) 2010  VN Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __MN34041PL_LOCALS_H__
#define __MN34041PL_LOCALS_H__
#endif
#ifndef __KERNEL__
#define __KERNEL__
#endif

#ifndef MODULE
#define MODULE
#endif

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <asm/arch/irq.h>
#include <asm/arch/platform.h>
#include <linux/mutex.h> // spinlock
#include "vivo_codec.h"
#include "video_error.h"

/* ============================================================================*/
#define MN34041PL_VER		0x3000

//#define MN34041PL_TBL_SIZE		263
#define MN34041PL_SERIAL_TBL_SIZE		382

#define MN34041PL_DEFAULT_OUTPUT_WIDTH	1920
#define MN34041PL_DEFAULT_OUTPUT_HEIGHT	1080

/* Version 1.0.0.3 modification, 2012.08.06 */
#define MN34041PL_MAX_GAIN 32000
/* ========================== */

#define MN34041PL_PIXEL_CLOCK_30FPS		81000000
#define MN34041PL_PIXEL_CLOCK_30FPS_M	(MN34041PL_PIXEL_CLOCK_30FPS/1000000)

#define MN34041PL_PIXEL_CLOCK_60FPS		162000000
#define MN34041PL_PIXEL_CLOCK_60FPS_M	(MN34041PL_PIXEL_CLOCK_60FPS/1000000)

#define MN34041PL_HSYNC_1920x1080_60FPS	2400
/* Version 1.0.0.2 modification, 2011.11.09 */
#define MN34041PL_HSYNC_1920x1080_50FPS	2400

#define MN34041PL_VSYNC_1920x1080_60FPS	1125
#define MN34041PL_VSYNC_1920x1080_50FPS	1350
/* ========================== */

typedef enum MN34041PL_registers
{
	_0000_	=	0x0000,
	_0001_	=	0x0001,
	_0002_	=	0x0002,
	_0003_	=	0x0003,
	_0004_	=	0x0004,
	_0005_	=	0x0005,
	_0006_	=	0x0006,
	_0020_	=	0x0020,
	_0021_	=	0x0021,
	_0022_	=	0x0022,
	_0023_	=	0x0023,
	_0024_	=	0x0024,
	_0025_	=	0x0025,
	_0026_	=	0x0026,
	_0027_	=	0x0027,
	_0028_	=	0x0028,
	_0030_	=	0x0030,
	_0031_	=	0x0031,
	_0032_	=	0x0032,
	_0033_	=	0x0033,
	_0034_	=	0x0034,
	_0035_	=	0x0035,
	_0036_	=	0x0036,
	_0037_	=	0x0037,
	_0038_	=	0x0038,
	_0039_	=	0x0039,
	_003A_	=	0x003A,
	_003B_	=	0x003B,
	_003F_	=	0x003F,
	_0040_	=	0x0040,
	_0041_	=	0x0041,
	_0042_	=	0x0042,
	_0043_	=	0x0043,
	_0044_	=	0x0044,
	_0045_	=	0x0045,
	_0046_	=	0x0046,
	_0047_	=	0x0047,
	_0048_	=	0x0048,
	_0049_	=	0x0049,
	_004A_	=	0x004A,
	_004B_	=	0x004B,
	_0056_	=	0x0056,
	_0057_	=	0x0057,
	_0058_	=	0x0058,
	_0059_	=	0x0059,
	_005A_	=	0x005A,
	_0070_	=	0x0070,
	_0071_	=	0x0071,
	_0072_	=	0x0072,
	_0073_	=	0x0073,
	_0074_	=	0x0074,
	_0075_	=	0x0075,
	_0076_	=	0x0076,
	_0077_	=	0x0077,
	_0078_	=	0x0078,
	_0079_	=	0x0079,
	_0080_	=	0x0080,
	_0081_	=	0x0081,
	_0082_	=	0x0082,
	_0083_	=	0x0083,
	_0084_	=	0x0084,
	_0085_	=	0x0085,
	_0086_	=	0x0086,
	_0087_	=	0x0087,
	_0088_	=	0x0088,
	_0089_	=	0x0089,
	_008A_	=	0x008A,
	_008B_	=	0x008B,
	_008C_	=	0x008C,
	_008D_	=	0x008D,
	_008E_	=	0x008E,
	_008F_	=	0x008F,
	_0090_	=	0x0090,
	_0091_	=	0x0091,
	_0092_	=	0x0092,
	_0093_	=	0x0093,
	_0094_	=	0x0094,
	_0095_	=	0x0095,
	_0096_	=	0x0096,
	_0097_	=	0x0097,
	_00A0_	=	0x00A0,
	_00A1_	=	0x00A1,
	_00A2_	=	0x00A2,
	_00A3_	=	0x00A3,
	_00A4_	=	0x00A4,
	_00A5_	=	0x00A5,
	_00A6_	=	0x00A6,
	_00A7_	=	0x00A7,
	_00A8_	=	0x00A8,
	_00A9_	=	0x00A9,
	_00C0_	=	0x00C0,
	_00C1_	=	0x00C1,
	_00C2_	=	0x00C2,
	_00C3_	=	0x00C3,
	_00C4_	=	0x00C4,
	_00C5_	=	0x00C5,
	_00C6_	=	0x00C6,
	_00C7_	=	0x00C7,
	_00CA_	=	0x00CA,
	_00CB_	=	0x00CB,
	_00CC_	=	0x00CC,
	_00CD_	=	0x00CD,
	_00CE_	=	0x00CE,
	_0100_	=	0x0100,
	_0101_	=	0x0101,
	_0102_	=	0x0102,
	_0103_	=	0x0103,
	_0104_	=	0x0104,
	_0105_	=	0x0105,
	_0106_	=	0x0106,
	_0108_	=	0x0108,
	_0109_	=	0x0109,
	_010A_	=	0x010A,
	_010B_	=	0x010B,
	_010C_	=	0x010C,
	_010D_	=	0x010D,
	_010E_	=	0x010E,
	_010F_	=	0x010F,
	_0110_	=	0x0110,
	_0111_	=	0x0111,
	_0112_	=	0x0112,
	_0113_	=	0x0113,
	_0114_	=	0x0114,
	_0115_	=	0x0115,
	_0116_	=	0x0116,
	_0117_	=	0x0117,
	_0118_	=	0x0118,
	_0119_	=	0x0119,
	_011A_	=	0x011A,
	_011B_	=	0x011B,
	_011C_	=	0x011C,
	_011D_	=	0x011D,
	_011E_	=	0x011E,
	_011F_	=	0x011F,
	_0120_	=	0x0120,
	_0121_	=	0x0121,
	_0122_	=	0x0122,
	_0123_	=	0x0123,
	_0124_	=	0x0124,
	_0125_	=	0x0125,
	_0126_	=	0x0126,
	_0127_	=	0x0127,
	_0128_	=	0x0128,
	_0129_	=	0x0129,
	_012A_	=	0x012A,
	_012B_	=	0x012B,
	_012C_	=	0x012C,
	_012D_	=	0x012D,
	_012E_	=	0x012E,
	_012F_	=	0x012F,
	_0130_	=	0x0130,
	_0131_	=	0x0131,
	_0132_	=	0x0132,
	_0133_	=	0x0133,
	_0134_	=	0x0134,
	_0135_	=	0x0135,
	_0136_	=	0x0136,
	_0137_	=	0x0137,
	_0138_	=	0x0138,
	_0139_	=	0x0139,
	_013A_	=	0x013A,
	_0140_	=	0x0140,
	_0141_	=	0x0141,
	_0142_	=	0x0142,
	_0143_	=	0x0143,
	_0144_	=	0x0144,
	_0145_	=	0x0145,
	_0146_	=	0x0146,
	_0150_	=	0x0150,
	_0151_	=	0x0151,
	_0152_	=	0x0152,
	_0153_	=	0x0153,
	_0154_	=	0x0154,
	_0155_	=	0x0155,
	_0156_	=	0x0156,
	_0157_	=	0x0157,
	_0158_	=	0x0158,
	_0159_	=	0x0159,
	_015A_	=	0x015A,
	_015B_	=	0x015B,
	_015C_	=	0x015C,
	_015D_	=	0x015D,
	_015E_	=	0x015E,
	_015F_	=	0x015F,
	_0160_	=	0x0160,
	_0161_	=	0x0161,
	_0162_	=	0x0162,
	_0163_	=	0x0163,
	_0164_	=	0x0164,
	_0165_	=	0x0165,
	_0166_	=	0x0166,
	_0167_	=	0x0167,
	_0168_	=	0x0168,
	_0169_	=	0x0169,
	_016A_	=	0x016A,
	_016B_	=	0x016B,
	_0170_	=	0x0170,
	_0171_	=	0x0171,
	_0172_	=	0x0172,
	_0173_	=	0x0173,
	_0174_	=	0x0174,
	_0175_	=	0x0175,
	_0176_	=	0x0176,
	_0177_	=	0x0177,
	_0178_	=	0x0178,
	_0179_	=	0x0179,
	_017A_	=	0x017A,
	_017B_	=	0x017B,
	_017C_	=	0x017C,
	_0180_	=	0x0180,
	_0181_	=	0x0181,
	_0182_	=	0x0182,
	_0183_	=	0x0183,
	_0184_	=	0x0184,
	_0185_	=	0x0185,
	_0186_	=	0x0186,
	_0187_	=	0x0187,
	_0188_	=	0x0188,
	_0189_	=	0x0189,
	_018A_	=	0x018A,
	_018B_	=	0x018B,
	_018C_	=	0x018C,
	_018D_	=	0x018D,
	_0190_	=	0x0190,
	_0191_	=	0x0191,
	_0192_	=	0x0192,
	_0193_	=	0x0193,
	_0194_	=	0x0194,
	_0195_	=	0x0195,
	_0196_	=	0x0196,
	_0197_	=	0x0197,
	_0198_	=	0x0198,
	_0199_	=	0x0199,
	_019A_	=	0x019A,
	_019B_	=	0x019B,
	_019C_	=	0x019C,
	_019D_	=	0x019D,
	_019E_	=	0x019E,
	_01A0_	=	0x01A0,
	_01A1_	=	0x01A1,
	_01A2_	=	0x01A2,
	_01A3_	=	0x01A3,
	_01A4_	=	0x01A4,
	_01A5_	=	0x01A5,
	_01A6_	=	0x01A6,
	_01A7_	=	0x01A7,
	_01A8_	=	0x01A8,
	_01A9_	=	0x01A9,
	_01AA_	=	0x01AA,
	_01AB_	=	0x01AB,
	_01AC_	=	0x01AC,
	_01AD_	=	0x01AD,
	_01AE_	=	0x01AE,
	_01AF_	=	0x01AF,
	_01B0_	=	0x01B0,
	_01B1_	=	0x01B1,
	_01B2_	=	0x01B2,
	_01B3_	=	0x01B3,
	_01B4_	=	0x01B4,
	_01B5_	=	0x01B5,
	_01B6_	=	0x01B6,
	_01B7_	=	0x01B7,
	_01B8_	=	0x01B8,
	_01B9_	=	0x01B9,
	_01BA_	=	0x01BA,
	_01BB_	=	0x01BB,
	_01BC_	=	0x01BC,
	_01BD_	=	0x01BD,
	_01BE_	=	0x01BE,
	_01C4_	=	0x01C4,
	_01C5_	=	0x01C5,
	_01C6_	=	0x01C6,
	_01D0_	=	0x01D0,
	_01D1_	=	0x01D1,
	_01D2_	=	0x01D2,
	_01D3_	=	0x01D3,
	_01D4_	=	0x01D4,
	_01D5_	=	0x01D5,
	_01D6_	=	0x01D6,
	_01D7_	=	0x01D7,
	_01D8_	=	0x01D8,
	_01D9_	=	0x01D9,
	_01DA_	=	0x01DA,
	_01DB_	=	0x01DB,
	_01DC_	=	0x01DC,
	_01DD_	=	0x01DD,
	_01DE_	=	0x01DE,
	_01DF_	=	0x01DF,
	_01E0_	=	0x01E0,
	_01E1_	=	0x01E1,
	_01E2_	=	0x01E2,
	_01E3_	=	0x01E3,
	_01E4_	=	0x01E4,
	_01E5_	=	0x01E5,
	_01E6_	=	0x01E6,
	_01E7_	=	0x01E7,
	_01E8_	=	0x01E8,
	_01E9_	=	0x01E9,
	_01EA_	=	0x01EA,
	_01EB_	=	0x01EB,
	_01EC_	=	0x01EC,
	_01ED_	=	0x01ED,
	_01EE_	=	0x01EE,
	_01EF_	=	0x01EF,
	_01F0_	=	0x01F0,
	_01F1_	=	0x01F1,
	_01F2_	=	0x01F2,
	_01F3_	=	0x01F3,
	_01F4_	=	0x01F4,
	_01F5_	=	0x01F5,
	_01F6_	=	0x01F6,
	_0200_	=	0x0200,
	_0201_	=	0x0201,
	_0202_	=	0x0202,
	_0203_	=	0x0203,
	_0204_	=	0x0204,
	_0205_	=	0x0205,
	_0206_	=	0x0206,
	_0270_	=	0x0270,
	_0271_	=	0x0271,
	_0272_	=	0x0272,
	_0273_	=	0x0273,
	_0274_	=	0x0274,
	_0275_	=	0x0275,
	_0276_	=	0x0276,
	_0277_	=	0x0277,
	_0278_	=	0x0278,
	_0279_	=	0x0279,
	_027A_	=	0x027A,
	_027B_	=	0x027B,
	_027C_	=	0x027C,
	_0290_	=	0x0290,
	_0291_	=	0x0291,
	_0292_	=	0x0292,
	_0293_	=	0x0293,
	_0294_	=	0x0294,
	_0295_	=	0x0295,
	_0296_	=	0x0296,
	_0297_	=	0x0297,
	_0298_	=	0x0298,
	_0299_	=	0x0299,
	_029A_	=	0x029A,
	_029B_	=	0x029B,
	_029C_	=	0x029C,
	_029D_	=	0x029D,
	_029E_	=	0x029E,
	_02A0_	=	0x02A0,
	_02A1_	=	0x02A1,
	_02A2_	=	0x02A2,
	_02A3_	=	0x02A3,
	_02A4_	=	0x02A4,
	_02A5_	=	0x02A5,
	_02A6_	=	0x02A6,
	_02A7_	=	0x02A7,
	_02A8_	=	0x02A8,
	_02A9_	=	0x02A9,
	_02AA_	=	0x02AA,
	_02AB_	=	0x02AB,
	_02AC_	=	0x02AC,
	_02AD_	=	0x02AD,
	_02AE_	=	0x02AE,
	_02AF_	=	0x02AF,
	_02B0_	=	0x02B0,
	_02B1_	=	0x02B1,
	_02B2_	=	0x02B2,
	_02B3_	=	0x02B3,
	_02B4_	=	0x02B4,
	_02B5_	=	0x02B5,
	_02B6_	=	0x02B6,
	_02B7_	=	0x02B7,
	_02B8_	=	0x02B8,
	_02B9_	=	0x02B9,
	_02BA_	=	0x02BA,
	_02BB_	=	0x02BB,
	_02BC_	=	0x02BC,
	_02BD_	=	0x02BD,
	_02BE_	=	0x02BE,
	_02C4_	=	0x02C4,
	_02C5_	=	0x02C5,
	_02C6_	=	0x02C6,
} EMN34041PLRegs;

typedef struct MN34041PL_reg_addr_data
{
    EMN34041PLRegs eRegAddr;
    DWORD dwData;
} TMN34041PLRegAddrData;

typedef struct MN34041PL_info
{
	DWORD dwDeviceAddr;
	DWORD dwFuncUserData;

	FOnWriteBuf pfnWriteBuf;
	FOnReadBuf pfnReadBuf;

	DWORD dwFreq;	
}TMN34041PLInfo;

