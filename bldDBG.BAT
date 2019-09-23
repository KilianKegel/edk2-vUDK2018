@echo off
type conf\target.txt | find "=" | find /V "DEBUG" | find /V "RELEASE" > conf\target.tmp
echo TARGET = DEBUG >> conf\target.tmp
if exist conf\target.org del conf\target.org
ren conf\target.txt target.org
ren conf\target.tmp target.txt
echo EmulationBuild / Debug

if exist edk2\Build\NT32IA32\DEBUG_VS%VSVERSION%\IA32\SecMain.exe del edk2\Build\NT32IA32\DEBUG_VS%VSVERSION%\IA32\SecMain.exe
call build -t VS%VSVERSION%

if exist Build\NT32IA32\DEBUG_VS%VSVERSION%\IA32\SecMain.exe (
    echo ##############################################################################
    echo ### BUILD SUCCESS, run "start dbg DEBUG" to start debuggging #################
    echo ##############################################################################
    dir /s /b Build\NT32IA32\DEBUG_VS%VSVERSION%\IA32\SecMain.exe
) else (
    echo ##############################################################################
    echo #### BUILD FAIL ## BUILD FAIL ## BUILD FAIL ## BUILD FAIL ## BUILD FAIL ######
    echo ##############################################################################
)