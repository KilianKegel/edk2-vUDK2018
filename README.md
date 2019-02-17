# edk2-UDK2018

## Goal
Get the MinnowBoard running with UDK2018.

NOTE: Visual Studio is here only used for editing the project.
The build process is still pure EDK!

## HowTo/install
1. download and install https://www.python.org/ftp/python/2.7/python-2.7.amd64.msi
   at c:\Python27
2. download and install https://www.nasm.us/pub/nasm/releasebuilds/2.13/win64/nasm-2.13-installer-x64.exe
   at c:\NASM
3. download VS12017 from here: https://visualstudio.microsoft.com/downloads/
4. select: "Desktop development with C++"
	![component selection](VS2017-components.png)	

## HowTo/edit
1. after installation is finished, open _edk2-vUDK2018.sln_

## HowTo/build
1. run LAUNCH2017.BAT from the project root
2. enter "BUILD -t VS2017" to build the EDK2
3. enter "rd /s /q build" to clean previous build
4. enter "DBG" to start the UEFI BIOS EMULATION

## Revision history
### 20190217/1
* prevent VS2017 to start a build process

### 20190216/4 - bugfix, update
