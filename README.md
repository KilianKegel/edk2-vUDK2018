# edk2-UDK2018

## Goal
Get the MinnowBoard running with UDK2018.

NOTE: Visual Studio is here only used for editing the project.
The build process is still pure EDK!

## HowTo/install
1. install the build machine according to: https://github.com/MinnowWare/HowTo-setup-an-UEFI-Development-PC#howto-setup-an-uefi-development-pc

2. select: "Desktop development with C++"
	![component selection](VS2017-components.png)	

## HowTo/edit
1. after installation is finished, open _edk2-vUDK2018.sln_

## HowTo/build
1. run LAUNCH2017.BAT from the project root
2. enter "BUILD -t VS2017" to build the EDK2
3. enter "rd /s /q build" to clean previous build
4. enter "DBG" to start the UEFI BIOS EMULATION

## Revision history
### 20190824/1
* add latest C Development Environment Packages (**CdePkg**, CdeSrcPkg** and **CdeValidationPkg**)

### 20190217/1
* prevent VS2017 to start a build process

### 20190216/4 - bugfix, update
