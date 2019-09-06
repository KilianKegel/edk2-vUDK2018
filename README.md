# edk2-UDK2018

## Goal
Get the MinnowBoard running with UDK2018.

NOTE: Visual Studio is here only used for editing the project.
The build process is still pure EDK!

## HowTo/install
Install the build machine according to: https://github.com/MinnowWare/HowTo-setup-an-UEFI-Development-PC#howto-setup-an-uefi-development-pc

## HowTo/edit
1. after installation is finished, open _edk2-vUDK2018.sln_

## HowTo/build
1. run LAUNCH2019.BAT from the project root
2. enter "bldREL.bat" or "bldDBG.bat" to build the EDK2
3. enter "rd /s /q build" to clean previous build
4. enter "start DBG" to start the UEFI BIOS EMULATION

## Revision history
### 20190901/C vs BAT MinnowTools
* GIT version check, since Git ver. 2.23 support submodules w/a error
* dediBurn, for auto updating the MinnowBoard BIOS

### 20190830/OpenSSL
* add OpenSSL_1_1_0-stable to CryptoPkg\Library\OpensslLib

### 20190829/build batches
* add bldDBG.bat and bldREL.bat

### 20190828/OpenSSL
* add OpenSSL_1_1_0g to CryptoPkg\Library\OpensslLib
* add openssl-1.0.2r-x64_86-win64 binary tools

### 20190824
* add latest C Development Environment Packages (**CdePkg**, **CdeSrcPkg** and **CdeValidationPkg**)

### 20190217/1
* prevent VS2017 to start a build process

### 20190216/4 - bugfix, update
