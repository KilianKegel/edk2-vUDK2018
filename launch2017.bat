set path=%path%;"c:\NASM"
set PYTHON_HOME=C:\Python27
call edksetup.bat Rebuild
call edksetup --nt32
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
echo ##############################################################
echo ### enter "BUILD -t VS2017" to build the EDK2              ###
echo ### enter "rd /s /q build" to clean previous build         ###
echo ### enter "DBG" to start the UEFI BIOS EMULATION           ###
echo ##############################################################
cmd.exe
