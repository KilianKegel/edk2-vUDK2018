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

@brief check build system, if GIT v2.23 is installed and available

@details check build system, if GIT v2.23 is installed and available


@todo
@mainpage
    GitVerChk support tool
@section intro_sec Introduction
    GitVerChk checks the installed GIT version to support "submodule"

@subsection Parm_sec Command line parameters
    1. unarchive file1 file2 dir1 dir2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int nRet = 0;
    int nMajor, nMinor,t;

    do {
        
        if (argc > 1 && 0 == strcmp(argv[1], "2831DEBC-DB3B-43D2-9635-E6464933C898")) {

            t = scanf("git version %d.%d", &nMajor, &nMinor);

            if (!(t == 2 && nMajor >= 2 && nMinor >= 23)) {
                fprintf(stderr, "WARNING: Use GIT v2.23 or higher. Previous versions have a submodule issue\n    https://git-scm.com/download/win\n");
                nRet = 1;
            }
        } else {

            nRet = system("git --version | gitverchk.exe 2831DEBC-DB3B-43D2-9635-E6464933C898");
        }
    } while (0);
    
    if (nRet != 0/*keep the messages on screen for a moment in case of error*/) {
        system("ping 127.0.0.0 > nul");
    }

    return nRet;
}