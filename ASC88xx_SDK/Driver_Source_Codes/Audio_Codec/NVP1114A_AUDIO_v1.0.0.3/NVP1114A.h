/*
 * Mozart_Audio_NVP1114A
 * Driver for Mozart NVP1114A Audio Codec Driver
 *
 * Copyright (C) 2010  ______ Inc.
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
 */

#ifndef __NVP1114A_H__
#define __NVP1114A_H__

#define NVP1114A_CACHEREGNUM 	256
static const unsigned char tw2866_all_regs[NVP1114A_CACHEREGNUM] = {
      //        0x00  0x01 0x02  0x03 0x04  0x05 0x06 0x07  0x08 0x09 0x0A 0x0B 0x0C 0x0D 0x0E 0x0F
               0x00,0x00,0x00,0x00,0x00,0x10,0x32,0x10,0x32,0x10,0x32,0x10,0x32,0x00,0x00,0x00,
      /*1*/    0x00,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      /*2*/    0x60,0x00,0x00,0x02,0x9f,0x00,0x00,0x00,0x06,0x10,0x95,0x00,0x00,0x8A,0x40,0x04,
      /*3*/    0x60,0x00,0x00,0x02,0x9f,0x00,0x00,0x00,0x06,0x10,0x95,0x00,0x00,0x8A,0x40,0x14,
      /*4*/    0x60,0x00,0x00,0x02,0x9f,0x00,0x00,0x00,0x06,0x10,0x95,0x00,0x00,0x8A,0x40,0x25,
      /*5*/    0x60,0x00,0x00,0x02,0x9f,0x00,0x00,0x00,0x06,0x10,0x95,0x00,0x00,0x8A,0x40,0x35,
      /*6*/    0xd0,0x80,0x40,0x7c,0x9f,0x00,0x20,0x40,0x80,0x50,0x38,0x0f,0x0c,0x01,0x15,0x0a,
      /*7*/    0x80,0x23,0x88,0x04,0x2a,0xcc,0xf0,0x2F,0x57,0x43,0x10,0x88,0x82,0x63,0x01,0x00,
      /*8*/    0x80,0x00,0x00,0x81,0x01,0x00,0x00,0x00,0x00,0x20,0x04,0x2e,0x00,0x30,0xb8,0x01,
      /*9*/    0x06,0x06,0x11,0xb9,0xb2,0x05,0x00,0x28,0x50,0x51,0xb5,0x13,0x03,0x22,0xff,0x00,
      /*A*/    0x00,0x00,0x00,0x88,0x88,0x8C,0x35,0x10,0xff,0xff,0xff,0x32,0xff,0xff,0xff,0x8C,
      /*B*/    0x00,0x00,0x00,0x88,0x10,0x80,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xc9,0x0F,0x11,
      /*C*/    0x13,0x13,0x13,0x13,0x00,0x00,0x71,0x71,0x71,0x71,0x1c,0x1c,0x1c,0x1c,0x87,0x87,
      /*D*/    0x87,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x10,0x80,0x10,0x00,0x00,
      /*E*/    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x11,0x01,0x40,0x00,0x00,0x00,0x00,
      /*F*/    0x00,0x00,0xa0,0x04,0x00,0x00,0x80,0x00,0x69,0x20,0x0f,0x80,0x80,0x49,0x37,0x00
};

//static unsigned char tw2866_firsttime_regs[NVP1114A_CACHEREGNUM] = {0} ;

// There are total 256 regs for NVP1114A.
// But a lot of them are for Video purposes.
// Here we put Audio-Related-Regs together to prevent from accessing Video regs.
// !! They should be in a increasing order.
static const unsigned char tw2866_audio_regs_index[] = {
		0xA1,
		0xA2,
		0xA3,
		0xA4,
		0xA5,        
        0xA6,
        0xA7,
        0xA8,
        0xA9,
        0xAA,
        0xAB,
        0xAC,
        0xAD,
        0xAE,
        0xAF,
		0xB0,
		0xB1,
		0xB2,
		0xB3,
		0xB4,
		0xB5,
		0xB6,
		0xB7,		
		0xB8,
		0xBE,
		0xBF,
		0xF2		
} ;

#endif
