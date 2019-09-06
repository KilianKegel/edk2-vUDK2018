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
@file NasmVerChk.c

@brief check build system, if NASM v2.13 is installed and available

@details check build system, if NASM v2.13 is installed and available


@todo
@mainpage
    NasmVerChk support tool
@section intro_sec Introduction
    NasmVerChk checks the installed NASM version to support "submodule"

@subsection Parm_sec Command line parameters
    1. unarchive file1 file2 dir1 dir2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int nRet = 0;
    int nMajor, nMinor,t;
    int iVerbose = 0, iHelp = 0, i;
    
    do {
        
        for (i = 1; i < argc; i++) {
            if (0 == strcmp(argv[i], "-h")      ||
                0 == strcmp(argv[i], "/h")      ||
                0 == strcmp(argv[i], "--h")     ||
                0 == strcmp(argv[i], "--help")
                )iHelp = i;

            if (0 == strcmp(argv[i], "-verbose"))
                iVerbose = i;
        }

        if (argc > 1){
            if (iHelp) {
                printf("NasmVerChk - Nasm version check\nusage: nasmverchk (w/o parameter) -- version check\n       nasmverchk -h -- help screen\n       nasmverchk -verbose -- verbose mode, print version match message\n");
                break;
            }
        }
        if (argc > 1 && 0 == strcmp(argv[1], "2831DEBC-DB3B-43D2-9635-E6464933C898")) {

            t = scanf("NASM version %d.%d", &nMajor, &nMinor);

            if (!(t == 2 && nMajor == 2 && nMinor == 13)) {
                fprintf(stderr, "WARNING: NASM v2.13 shall be used.\n    https://www.nasm.us/pub/nasm/releasebuilds/2.13/win64/nasm-2.13-installer-x64.exe\n");
                nRet = 1;
            }
        } else {

            nRet = system("nasm -v | nasmverchk.exe 2831DEBC-DB3B-43D2-9635-E6464933C898");
        }
    } while (0);
    
    if (nRet != 0/*keep the messages on screen for a moment in case of error*/) {
        system("ping 127.0.0.0 > nul");
    }
    else if (0 != iVerbose)
        printf("NASM version accepted.\n");

    return nRet;
}