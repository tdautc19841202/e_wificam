/*
 * $Header: /rd_2/project/Rossini/Linux_Libraries/JPEGEnc/JPEGEnc_Lib/typedef.h 32    13/12/17 1:58p Andy.tsao $
 *
 * Driver for EDMC.
 *
 * Copyright 2008 ______ Inc. 
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
 * Description:
 *
 * $History: typedef.h $
 * 
 * *****************  Version 32  *****************
 * User: Andy.tsao    Date: 13/12/17   Time: 1:58p
 * Updated in $/rd_2/project/Rossini/Linux_Libraries/JPEGEnc/JPEGEnc_Lib
 * 
 * *****************  Version 28  *****************
 * User: Frank.yang   Date: 13/03/22   Time: 11:35a
 * Updated in $/rd_common/common_header
 * * Adopt Morgan's suggestion for kernel-mode compilations.
 * 
 * *****************  Version 27  *****************
 * User: Frank.yang   Date: 13/03/13   Time: 10:14a
 * Updated in $/rd_2/project/SoC/Templates/Code_Gen
 * BUG: A very rough fix for modern 64-bit Linux (3.8.1). Note that this
 * fix itself may be buggy for other versions of Linux.
 * 
 * *****************  Version 26  *****************
 * User: Jon.lin      Date: 11/12/09   Time: 17:46
 * Updated in $/rd_2/project/SoC/Components/EDMC/Device_Driver/EDMC
 * add GPL header
 * 
 * *****************  Version 25  *****************
 * User: Bernard      Date: 10/12/01   Time: 4:46p
 * Updated in $/rd_2/project/SoC/Components/H4DE/Device_Driver/H4DE
 * FEATURE: Synchronous with gcc 4.0 - Done.
 *
 * *****************  Version 21  *****************
 * User: Albert.shen  Date: 09/01/10   Time: 11:12a
 * Updated in $/rd_2/Peripherals/ICX098/ICX098_Lib
 *
 * *****************  Version 20  *****************
 * User: Alan         Date: 08/04/12   Time: 12:29a
 * Updated in $/rd_2/misc/PBENGINE/C/PBEngine/PBEngine_Lib
 * Add typedef of QWORD and SQWORD when defined __TCS__ (TriMedia).
 *
 * *****************  Version 19  *****************
 * User: Alan         Date: 08/01/23   Time: 2:01p
 * Updated in $/rd_2/project/SoC/Linux_Libraries/VideoDisp/VideoDisp_Lib
 *
 * *****************  Version 18  *****************
 * User: Alan         Date: 08/01/21   Time: 10:34p
 * Updated in $/rd_2/Peripherals/TW2815/TW2815_Lib
 *
 * *****************  Version 17  *****************
 * User: Alan         Date: 08/01/21   Time: 10:28p
 * Updated in $/rd_2/Peripherals/TW2815/TW2815_Lib
 *
 * *****************  Version 16  *****************
 * User: Rey          Date: 07/12/17   Time: 9:51p
 * Updated in $/rd_common/common_header
 * Add SOCKET type definition
 *
 * *****************  Version 15  *****************
 * User: Jaja         Date: 07/08/10   Time: 4:33p
 * Updated in $/rd_common/common_header
 *
 * *****************  Version 14  *****************
 * User: Jaja         Date: 07/08/10   Time: 3:17p
 * Updated in $/rd_2/project/SoC/Simulation_Models/H264Enc_C_Simulation/H264Enc_Lib
 *
 * *****************  Version 13  *****************
 * User: Ycchang      Date: 07/08/06   Time: 2:34p
 * Updated in $/rd_2/project/SoC/Components/F2BE/Device_Driver/F2BE
 * Add support for Linux 2.6 with LINUX_VERSION_CODE - DONE
 *
 * *****************  Version 12  *****************
 * User: Aren         Date: 06/07/27   Time: 11:00a
 * Updated in $/rd_2/project/Vivaldi/Standalone/FLASH/EVM_Lib/Include
 * MODIFICATION: for ADS armcc to avoid warning while in DWORD
 *
 * *****************  Version 11  *****************
 * User: Cchuang      Date: 05/09/29   Time: 17:06
 * Updated in $/rd_common/common_header
 * Add #include <limits.h>
 * Change the typedef of SDWORD to int or long by considering INT_MAX and
 * LONG_MAX to fix the bug that long is 64-64 on a 64-bit linux machine.
 * Change the typedef of DWORD in the same reason.
 *
 * *****************  Version 10  *****************
 * User: Sor          Date: 04/09/01   Time: 5:10p
 * Updated in $/rd_2/image/JPEG/C/Decoder/JPEGDec/JPEGDec_Lib
 *
 * *****************  Version 8  *****************
 * User: Cchuang      Date: 04/03/10   Time: 23:05
 * Updated in $/rd_2/video/MPEG4/ARM/Decoder/Mp4VDec/GBEngine_Lib
 * Add "typedef signed char SCHAR", some compiler will treat char as
 * unsigned.
 *
 * *****************  Version 7  *****************
 * User: Cchuang      Date: 03/09/02   Time: 1:13p
 * Updated in $/rd_2/misc/PBENGINE/C/PBEngine/PBEngine_Lib
 * Add typedef of QWORD and SQWORD when defined __GNUC__
 *
 * *****************  Version 6  *****************
 * User: Cchuang      Date: 03/06/27   Time: 4:02p
 * Updated in $/rd_2/audio/AAC/C/Encoder/AAC4Enc/PBEngine_Lib
 * Add typedef of QWORD and SQWORD when defined __arm
 *
 * *****************  Version 5  *****************
 * User: Joe          Date: 03/03/12   Time: 1:48p
 * Updated in $/rd_common/common_header
 * Undefine _DOUBLE_PRECISION
 *
 * *****************  Version 4  *****************
 * User: Sor          Date: 03/01/15   Time: 1:55p
 * Updated in $/rd_2/video/MPEG4/C/Decoder/MP4VDEC/Mp4VDec_Lib
 * Change to fit the VNDP requirement.
 *
 * *****************  Version 1  *****************
 * User: Joe          Date: 03/01/13   Time: 3:56p
 * Created in $/rd_common/common_header
 * first add typedef.h to common_header folder
 *
 * *****************  Version 3  *****************
 * User: Joe          Date: 02/12/25   Time: 4:29p
 * Updated in $/rd_1/System/FIRMWARE/common/src
 * Update some naming rules
 *
 * *****************  Version 2  *****************
 * User: Joe          Date: 02/12/19   Time: 2:09p
 * Updated in $/rd_1/System/FIRMWARE/common/src
 * change SCODE definition
 *
 * *****************  Version 1  *****************
 * User: Joe          Date: 02/11/06   Time: 2:54p
 * Created in $/rd_1/System/FIRMWARE/common/src
 *
 *******************************************************************************
 */

/*!
 *******************************************************************************
 * Copyright 2008 ______ Inc. All rights reserved.
 *
 * \file
 * typedef.h
 *
 * \brief
 * Define some useful types, this file should include after OS related include
 * files, such as windows.h, psos.h. currently support windows & psos only
 *
 * \date
 * 2002/07/03
 *
 * \author
 * Joe Wu
 *
 *
 *******************************************************************************
 */

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#if defined(_WIN32)
	#include <limits.h>
#else //_WIN32
	#include <linux/version.h>

	#ifdef __KERNEL__
		#include <linux/kernel.h>
	#else
		#include <limits.h>
	#endif
#endif //_WIN32

// to avoid confliction if including "windows.h"
#ifndef _WINDOWS_
// the following types are already define in windows.h

#ifndef __TYPES_H__		// for psos
// the following types are already define in psos.h

#ifndef UCHAR	// uc
typedef unsigned char   UCHAR;
#endif

#ifndef ULONG	// ul
typedef unsigned long   ULONG;
#endif

#ifndef USHORT	// us
typedef unsigned short  USHORT;
#endif

#ifndef UINT	// ui
typedef unsigned int    UINT;
#endif

#endif	// end of __TYPES_H__	// for psos

//  1 byte
#ifndef CHAR	// c
typedef char            CHAR;
#endif

#ifndef PCHAR	// pc
typedef char            *PCHAR;
#endif

#ifndef PUCHAR	// puc
typedef unsigned char   *PUCHAR;
#endif

#ifndef BYTE	// by
typedef unsigned char   BYTE;
#endif

#ifndef PBYTE	// pby
typedef BYTE*           PBYTE;
#endif

//  2 bytes
#ifndef short	// s
typedef short           SHORT;
#endif

#ifndef PSHORT	// ps
typedef short           *PSHORT;
#endif

#ifndef PUSHORT	// pus
typedef unsigned short  *PUSHORT;
#endif

#ifndef WORD	// w
typedef unsigned short  WORD;
#endif

#ifndef PWORD	// pw
typedef WORD*           PWORD;
#endif

//  4 bytes
#ifndef DWORD	// dw
	#if defined(_WIN32)
		#if defined(__arm)	// for ADS compiler -- armcc
			typedef unsigned long   DWORD;
		#elif UINT_MAX == 4294967295
			typedef unsigned int	DWORD;
		#elif ULONG_MAX == 4294967295
			typedef unsigned long   DWORD;
		#endif // ULONG_MAX == 4294967295
	#else
		#ifndef UINT_MAX
		#error UNIT_MAX is not defined!
		#endif

		#if UINT_MAX == 4294967295
			typedef unsigned int	DWORD;
		#elif ULONG_MAX == 4294967295
			typedef unsigned long   DWORD;
		#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 4, 0))
			typedef unsigned long   DWORD;
		#elif defined(__arm)	// for ADS compiler -- armcc
			typedef unsigned long   DWORD;
		#endif // ULONG_MAX == 4294967295
	#endif //_WIN32
#endif

#ifndef PDWORD	// pdw
typedef DWORD*          PDWORD;
#endif

#ifndef PUINT	// pui
typedef UINT*           PUINT;
#endif

#ifndef long	// l
typedef long            LONG;
#endif

#ifndef PLONG	// pl
typedef long            *PLONG;
#endif

#ifndef PULONG	// plu
typedef unsigned long   *PULONG;
#endif


#ifndef BOOLEAN	// b
typedef unsigned int    BOOLEAN;
#endif

#ifndef BOOL	// b
typedef BOOLEAN         BOOL;
#endif

// bool is keyword in C++
#if defined(_WIN32)
	#if !defined(bool) && !defined(__cplusplus)
	typedef BOOLEAN         bool;
	#endif
#else
	#if !defined(bool) && !defined(__cplusplus) && (LINUX_VERSION_CODE < KERNEL_VERSION(2, 4, 0))
	typedef BOOLEAN         bool;
	#endif
#endif //_WIN32

#ifndef PVOID	// pv
typedef void *          PVOID;
#endif

#ifndef HANDLE	// h
typedef void *          HANDLE;
#endif

#ifndef SOCKET  //sck
typedef int             SOCKET;
#endif

/* the new SCODE is defined in errordef.h
#ifndef SCODE	// sc
typedef signed int	SCODE;
#endif
*/
// --------- for floating point -------------
#ifndef FLOAT	// fl
#ifdef _DOUBLE_PRECISION
	typedef double FLOAT;
#else
	typedef float  FLOAT;
#endif

#endif

#endif

// non-window conflict types

#ifndef SCHAR   //c
typedef signed char     SCHAR;
#endif

#ifndef SWORD	// sw
typedef signed short    SWORD;
#endif

#ifndef SDWORD  // sdw
    #if defined(_WIN32)
        #if INT_MAX == 2147483647
            typedef signed int      SDWORD;
        #elif LONG_MAX == 2147483647
            typedef signed long     SDWORD;
        #endif // LONG_MAX == 2147483647
    #else
        #if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 4, 0))
            typedef signed int      SDWORD;
        #else
            #if INT_MAX == 2147483647
                typedef signed int      SDWORD;
            #elif LONG_MAX == 2147483647
                typedef signed long     SDWORD;
            #endif // LONG_MAX == 2147483647
        #endif
    #endif
#endif

#ifndef TASK
typedef void            TASK;
#endif

#if defined(_WIN32)
	typedef unsigned __int64 	QWORD;	// qw
	typedef __int64				SQWORD;	// sqw
#elif defined(_EQUATOR_X_) || defined(__arm)
	typedef unsigned long long	QWORD;	// qw
    typedef long long           SQWORD;	// sqw
#elif defined(__GNUC__) || defined(__TCS__)
	typedef unsigned long long int	QWORD;	// qw
    typedef long long int           SQWORD;	// sqw
#endif


// --------- for fix point -------------
typedef signed short     FIX16;
typedef unsigned short   UFIX16;
typedef signed long      FIX;
typedef unsigned long    UFIX;


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#define ON  1
#define OFF 0

#ifndef S_OK
#define S_OK 0
#endif

#ifndef S_FAIL
#define S_FAIL (SCODE)(-1)
#endif

#ifndef S_INVALID_VERSION
#define S_INVALID_VERSION (SCODE)(-2)
#endif

#endif // _TYPEDEF_H_
