@echo off
set path=%path%;"c:\NASM";%~dp0openssl-1.0.2r-x64_86-win64
set PYTHON_HOME=C:\Python27
if exist conf rd /s /q Conf

if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat" (
	echo #####################################################################################
	echo ######################## Visual Studio 2017 is not installed ########################
	echo #####################################################################################
	ping -n 10 127.0.0.0 > NUL
	goto EOF
) else (
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
        %~d0
        cd %~p0
	call edksetup.bat Rebuild
	call edksetup --nt32
)
echo %~d0
%~d0
cd %~p0
set VSVERSION=2017
echo ###################################################################################
echo ###                                                                             ###
echo ###                             -=[ VS2017 ]=-                                  ###
echo ###                                                                             ###
echo ### To build the EmulationBuild (Nt32Pkg) for Release or Debug invoke:          ###
echo ###     bldREL.bat                                                              ###
echo ###        or                                                                   ###
echo ###     bldDEB.bat                                                              ###
echo ###                                                                             ###
echo ### enter "rd /s /q build" to clean previous build                              ###
echo ### enter "start DBG" to start the UEFI BIOS EMULATION                          ###
echo ###################################################################################
cmd.exe
