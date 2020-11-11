/* EDK2 platform.h for EK */
/** @file
  The platform.h definitions for embedded Kermit v1.6 for use under Uefi as a
  Shell application.

Uefi Portions Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

Portions Copyright (C) 1995, 2011, 
  Trustees of Columbia University in the City of New York.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of Columbia University nor the names of its contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

**/

#ifndef NULL
#define NULL  ((VOID *) 0)
#endif


#ifndef __KERMIT_PLATFORM_H__
#define __KERMIT_PLATFORM_H__

#include <Base.h>
#include <Uefi.h>
#include <Library/UefiLib.h>

#include <Library/PcdLib.h>
#include <Library/PrintLib.h>

#include <Protocol/SerialIo.h>

EFI_SERIAL_IO_PROTOCOL *mSerialIOProto;

/* needed because kermit.c seems to compile various for loops into memcpy() calls 
   also needed is a /GL- compiler option */ 
#include <Library/BaseMemoryLib.h>
GLOBAL_REMOVE_IF_UNREFERENCED 
void * memcpy (void *, const void *, unsigned int);  //needed because kermit.c 
GLOBAL_REMOVE_IF_UNREFERENCED 
void * memset (void *, UINTN, UINT8);
/* end workaround */

/*inline UINT32 min(UINT32 a, UINT32 b) {
    if (a > b)
        return b;
    return a;
} */

//#/define MAXBUFLEN(b) min( PcdGet32(PcdUefiLibMaxPrintBufferSize)*sizeof(CHAR16), b )
//#define MAXBUFLEN(b) MIN( (PcdGet32(PcdUefiLibMaxPrintBufferSize)*sizeof(CHAR16)), b )

#ifndef IBUFLEN
#define IBUFLEN  4096			/* File input buffer size */
//#define IBUFLEN 180
//#/define IBUFLEN  (PcdGet32(PcdUefiLibMaxPrintBufferSize)*sizeof(CHAR16))
//#define IBUFLEN MAXBUFLEN(4096)
#endif /* IBUFLEN */

//#/define HAVE_UCHAR 1
#define UCHAR CHAR8 
//typedef UINT8 UCHAR;
//#/define HAVE_ULONG 1
#define ULONG UINT32
//typedef UINT32 ULONG;
//#/define HAVE_USHORT 1
#define USHORT UINT16    
//typedef UINT8 USHORT; 

#ifndef INT32
#define INT32 int
#endif

//#/define NO_CRC 1 
//#/define NO_LP 1
//#/define NO_AT 1
//#/define NO_SSW 1
//#/define NO_SCAN 1

//#/include <Library/FileExplorer.h>
#define FN_MAX (20*sizeof(CHAR16)) /*MAX_FILE_NAME_LEN*/

#ifndef RSIZE_MAX
#define RSIZE_MAX 16*FN_MAX
#endif
#ifndef ASCII_RSIZE_MAX 
#define ASCII_RSIZE_MAX 8*FN_MAX
#endif

#ifndef OBUFLEN
//#define OBUFLEN  8192                   /* File output buffer size */
//#define OBUFLEN RSIZE_MAX+10
#define OBUFLEN 1024 /*438 768*/
//#define OBUFLEN 180
//#/define OBUFLEN  (PcdGet32(PcdUefiLibMaxPrintBufferSize)*sizeof(CHAR16))
//#define OBUFLEN MAXBUFLEN(8192)
#endif /* OBUFLEN */     

//#/define P_PKTLEN 128
//#/define P_WSLOTS 1
//#define P_PKTLEN 1024
#define P_PKTLEN OBUFLEN-70
#define P_WSLOTS 1

#define MAXRPKTLEN 63

#endif //__KERMIT_PLATFORM_H__