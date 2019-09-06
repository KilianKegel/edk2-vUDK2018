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
@file IaslVerChk.c

@brief check build system, if c:\asl\IASL.EXE version 20160527-32 is installed and available

@details check build system, if c:\asl\IASL.EXE version 20160527-32 is installed and available


@todo
@mainpage
    IaslVerChk support tool
@section intro_sec Introduction
    IaslVerChk checks the installed IASL version to support "submodule"

@subsection Parm_sec Command line parameters
    1. unarchive file1 file2 dir1 dir2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int nRet = 0;
    int nMajor, t;
    int iVerbose = 0, iHelp = 0, i,c;
    char buffer[256];
    
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
                printf("IaslVerChk - Iasl version check\nusage: iaslverchk (w/o parameter) -- version check\n       iaslverchk -h -- help screen\n       iaslverchk -verbose -- verbose mode, print version match message\n");
                break;
            }
        }
        if (argc > 1 && 0 == strcmp(argv[1], "2831DEBC-DB3B-43D2-9635-E6464933C898")) {
            char* versionstrings[]={ {"Intel"},{"ACPI"},{"Component"},{"Architecture"},{"ASL+"},{"Optimizing"},{"Compiler"},{"version"},{"20160527-32"} };

            for (i = 0; i < sizeof(versionstrings) / sizeof(versionstrings[0]); i++) {
                scanf("%s", buffer);

                if (0 != strcmp(versionstrings[i], buffer)) {
                    //printf("DIFF\n");
                    nRet = 1000;
                    break;
                }
            }

            if (1000 == nRet) {
                fprintf(stderr, "WARNING: IASL v20160527 shall be used.\n    https://acpica.org/sites/acpica/files/iasl-win-20160527.zip\n");
                nRet = 1;
            }
        } else {

            nRet = system("c:\\asl\\iasl.exe -v | iaslverchk.exe 2831DEBC-DB3B-43D2-9635-E6464933C898");
        }
    } while (0);
    
    if (nRet != 0/*keep the messages on screen for a moment in case of error*/) {
        system("ping 127.0.0.0 > nul");
    }
    else if (0 != iVerbose)
        printf("IASL version accepted.\n");

    return nRet;
}