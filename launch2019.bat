@echo off
set path=%path%;"c:\NASM"
set PYTHON_HOME=C:\Python27
if exist conf rd /s /q Conf

if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" (
	echo #####################################################################################
	echo ######################## Visual Studio 2019 is not installed ########################
	echo #####################################################################################
	ping -n 10 127.0.0.0 > NUL
	goto EOF
) else (
	call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
        %~d0
        cd %~p0
	call edksetup.bat Rebuild
	call edksetup --nt32
)
echo %~d0
%~d0
echo ####################################################################
echo ### enter "BUILD -t VS2019" to build the EDK2 for emulation mode ###
echo ### enter "rd /s /q build" to clean previous build               ###
echo ### enter "start DBG" to start the UEFI BIOS EMULATION           ###
echo #####################################################################
cmd.exe
