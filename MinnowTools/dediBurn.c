/*!
@copyright
    Copyright (c) 2019, MinnowWare. All rights reserved.
    This program and the accompanying materials are licensed and made
    available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license
    may be found at
    http://opensource.org/licenses/bsd-license.php
    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
@file GitVerChk.c

@brief dediBurn - dediProg burn bios image

@details dediBurn - dediProg burn image or presence check 


@todo
@mainpage
    dediBurn support tool
@section intro_sec Introduction
    dediBurn internally is based on DediProgs dpcmd.exe prgram, usually located
    in the "C:\Program Files (x86)\DediProg\SF100" directory.
    The PATH environment variable must be set accordingly.

@subsection Parm_sec Command line parameters
    1. dediBurn /file biosfilename
    2. dediBurn /detectonly /quiet
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int nRet = 32,i;
    int nMajor, nMinor,t;
    char* pCommand = malloc(4096);
    char* pszError = NULL;
    int iQuiet = 0,iDetect = 0, iFile = 0;

    do {
        //
        // command line test / filename available / quiet mode / detect only
        //
        for (i = 1; i < argc; i++) {
            if (0 == strcmp("/file", argv[i]))
                iFile = (1 + i < argc ? 1 + i : 0);
            if (0 == strcmp("/detectonly", argv[i]))
                iDetect  = i;
            if (0 == strcmp("/quiet", argv[i]))
                iQuiet = i;
        }

        if (0 == iDetect && 0 == iFile) {
            if (!iQuiet)fprintf(stderr, "Error: Missing BIOS filename parameter\n");
            break;//exit code 32
        }

        if (0 == iDetect && 0 != iFile && NULL == fopen(argv[iFile], "r")) {
            if (!iQuiet)fprintf(stderr, "Error: Missing BIOS file \"%s\"\n", argv[iFile]);
            break;//exit code 32
        }
        //
        // connection test
        //
        nRet = system("dpcmd.exe -d > nul");
        
        //printf("nRet = %d\n", nRet);
        switch (nRet) 
        {
            case  0: pszError = "Success: SF100 is connected to target and host\n"; break;
            case  1: pszError = "Error: DediProg SF100 not installed\n"; break;
            case  8: pszError = "Error: Chip not identified.\n"; break;
            case 99: pszError = "Error: DediProg SF100 not connected.\n"; break;
            default: pszError = "unknown error\n"; break;
        };

        if(!iQuiet)fprintf(stderr, pszError);
        
        if (nRet != 0 || iDetect)// retrurn code is 0 in case SF100 is connected to host and target
            break;
        
        strcpy(pCommand, "dpcmd.exe -d -e -p ");
        strcat(pCommand, argv[iFile]);
        //printf("%s\n", pCommand);
        nRet = system(pCommand);

    } while (0);

    //printf("nRet == %d\n", nRet);
    return nRet;
}