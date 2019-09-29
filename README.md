# **edk2-vUDK2018** / [**CdePkg**](https://github.com/KilianKegel/CdePkg#cdepkg)
* [Introduction](https://github.com/KilianKegel/edk2-vUDK2018#introduction)
* [Goal](https://github.com/KilianKegel/edk2-vUDK2018#goal)
* [HowTo/install/build](https://github.com/KilianKegel/edk2-vUDK2018#howtoinstallbuildedit)
	* [Installation](https://github.com/KilianKegel/edk2-vUDK2018#installation)
	* [Directory structure](https://github.com/KilianKegel/edk2-vUDK2018#directory-structure)
	* [Build](https://github.com/KilianKegel/edk2-vUDK2018#build)
	* [Edit](https://github.com/KilianKegel/edk2-vUDK2018#edit)
* [Known Bugs](https://github.com/KilianKegel/edk2-vUDK2018#known-bugs)
* [Related Projects](https://github.com/KilianKegel/edk2-vUDK2018#related-projects)
* [Revision History](https://github.com/KilianKegel/edk2-vUDK2018#revision-history)


![pci1](https://minnowboard.org/wp-content/uploads/2017/10/MBTurbot-quad-core-Top-0001-171002-1-555x370.png)

https://minnowboard.org/

## Introduction
**This **edk2-vUDK2018** introduces the [**_CdePkg_**](https://github.com/KilianKegel/CdePkg#cdepkg) and
the [**_CdeValidationPkg_**](https://github.com/KilianKegel/CdeValidationPkg#cdevalidationpkg) to the
UEFI/Tianocore open source community.**

**edk2-vUDK2018** is the Git-*Subproject* in the [UDK2018-MinnowBoard](https://github.com/KilianKegel/UDK2018-MinnowBoard) project to build the MinnowBoard UEFI BIOS,
but can also be used stand alone in Emulation Mode (Nt32Pkg) (NOTE: In emulation mode timing calulation assumes to run a 1GHz platform).


The MinnowBoard familiy is an *open source* Personal Computer hardware originally created by a company called
*ADI Engineering*, that belongs now to [Silicom](https://www.silicom-usa.com/)

Intel provides [binary modules](https://firmware.intel.com/projects/minnowboard-max) and maintains the [build environment](https://github.com/tianocore/edk2-platforms/blob/master/Platform/Intel/Vlv2TbltDevicePkg/Readme.md)
to get the MinnowBoard running with the open source [UEFI BIOS Tianocore\EDK2](https://github.com/tianocore/edk2.git)


## Goal
1. 	**The main aspect is, to introduce the [**_CdePkg_**](https://github.com/KilianKegel/CdePkg#cdepkg) and
	the [**_CdeValidationPkg_**](https://github.com/KilianKegel/CdeValidationPkg#cdevalidationpkg) to the
	UEFI/Tianocore open source community.**

2. get the MinnowBoard and the EDK2 Emulation (Nt32Pkg) running with the latest released UDK2018 and the latest Visual Studio VS2019 buildenvironment
3. use OpenSSL_1_1_0-stable in the component CryptoPkg\Library\OpensslLib


It is considered an improvement over traditional UEFI BIOS development, since it introduces
* stable, precise, chipset (ACPI timer) independent C library conform [`clock()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/clock?view=vs-2019) for POST and UEFI Shell in millisecond resolution
* unlimited (buffer less) [`printf()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l?view=vs-2019)-family and [`scanf()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l?view=vs-2019)-family implementation
* Standard C conform format specifiers for [`printf()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l?view=vs-2019)-family and [`scanf()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l?view=vs-2019)-family
* a library, which satisfies all the Microsoft C compiler intrinsic requirements with one and the same library (C++ not supported)
* *Hosted Environment* instead of *Freestanding Environment* for POST driver

This improvements shall enable UEFI and [modernFW](https://github.com/intel/ModernFW#modernfw-project)
to provide a Standard C interface for any "C"-(open)source-based extention.

NOTE: Visual Studio is here only used for editing the project. The build process is still pure EDK!
      (the startup error message of VS2017/VS2019 can be ignored)

## HowTo install/build/Edit
### Installation
1. install a build machine according to https://github.com/KilianKegel/HowTo-setup-an-UEFI-Development-PC#howto-setup-an-uefi-development-pc

2. clone the UDK2018-MinnowBoard project `--recursive`<br>
	i.  git.exe clone --progress --recursive -v "https://github.com/KilianKegel/UDK2018-MinnowBoard.git" "A:\UDK2018-MinnowBoard"<br>
	or<br>
	ii. right click to open the context menu -> Git clone<br>
![cloneimage2](clonedest.png)
### Directory structure
The given MinnowBoard SourceCode tree is extended by files and directories shown below:

![dirarch](https://github.com/KilianKegel/pictures/blob/master/directory.png)

|  root    | subdir        | subsubdir|annotation|
|:-|:-|:-|:-|
|**`  <DIR>  UDK2018-MinnowBoard`** |**`..`**|               |[@link](https://github.com/KilianKegel/UDK2018-MinnowBoard)|
|          |**`bldDBG.bat`**               |       |batch to build the MinnowBoard BIOS in DEBUG mode [@link](https://github.com/KilianKegel/UDK2018-MinnowBoard/blob/master/bldDBG.BAT)|
|          |**`bldREL.bat`**               |       |batch to build the MinnowBoard BIOS in RELEASE mode [@link](https://github.com/KilianKegel/UDK2018-MinnowBoard/blob/master/bldREL.BAT)|
|          |**`launch2019.bat`**               |       |start the VS2019 MinnowBoard build environment[@link](https://github.com/KilianKegel/UDK2018-MinnowBoard/blob/master/launch2019.bat)|
|          |**`launch2017.bat`**               |       |start the VS2019 MinnowBoard build environment[@link](https://github.com/KilianKegel/UDK2018-MinnowBoard/blob/master/launch2017.bat)|
|          |**`UDK2018-MinnowBoard.sln`**  |       |Visual Studio Solution to *edit only* the entire source tree [@link](https://github.com/KilianKegel/UDK2018-MinnowBoard/blob/master/UDK2018-Minnowboard.sln)|
|          |**`  <DIR>  edk2`** |**`..`**       | GIT-subproject [@link](https://github.com/KilianKegel/edk2-vUDK2018)|
|          |               |**`bldDBG.bat`**       | batch to build the EDK2 emulation (Nt32Pkg) BIOS in DEBUG mode [@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/bldDBG.BAT)|
|          |               |**`CdePkg.sln`**       | Visual Studio solution to edit/build **`CdePkg`** [@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/CdePkg.sln)|
|          |               |**`CdeValidationPkg.sln`**       | Visual Studio solution to edit/build **`CdeValidationPkg`** [@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/CdeValidationPkg.sln)|
|          |               |**`edk2-vUDK2018.sln`**       |Visual Studio solution to edit/only **`CdeValidationPkg`** [@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/edk2-vUDK2018.sln)|
|          |               |**`launch2019.bat`**               |start the VS2019 EDK2 emulation (Nt32Pkg) build environment[@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/launch2019.bat)|
|          |               |**`launch2017.bat`**               |start the VS2017 EDK2 emulation (Nt32Pkg) build environment[@link](https://github.com/KilianKegel/edk2-vUDK2018/blob/master/launch2017.bat)|
|          |               |**`  <DIR>  CdePkg`**              |**CdePkg** C Development Environment Package[@link](https://github.com/KilianKegel/CdePkg)|
|          |               |**`  <DIR>  CdeValidationPkg`**              |**CdeValidationPkg** C Development Environment Package[@link](https://github.com/KilianKegel/CdeValidationPkg)|


### Build
3. To build the EDK emulation:<br>
`edk2\launch2019.bat` to setup EDK2 / emulation (Nt32Pkg) build environment<br>
`rd /s /q build` in the `edk2`directory to clean previous EDK2 / emulation build<br>
`bldDBG.BAT` (Debug) <del> or `bldREL.BAT` (Release)</del> to start the build process in the EDK2 directory<br>
`start DBG` to start the UEFI BIOS EMULATION<br>

4. To build the MinnowBoard:<br>
`.\launch2019.bat` to setup MinnowBoard (`Vlv2TbltDevicePkg`) build environment<br>
`rd /s /q build` in the `.\`directory to clean previous `Vlv2TbltDevicePkg` build<br>
`bldREL.BAT` (Release) or `bldDBG.BAT` (Debug) to start the build process in the `.\`directory<br>
If a DediProg is connected to the system, the BIOS is automatically updated in the target system MinnowBoard<br>

**NOTE: EDKEmulation build and MinnowBoard build CAN NOT be used alternating in the
      same command box.**

### Edit

UDK2018-MinnowBoard is the Git-[Superproject **UDK2018-MinnowBoard**](https://github.com/KilianKegel/UDK2018-MinnowBoard) to build the MinnowBoard UEFI BIOS.

It includes the *edk2* which is the Git-[Subproject **edk2-vUDK2018**](https://github.com/KilianKegel/edk2-vUDK2018), that in turn
includes the *Cde*-directories as GIT-[Subproject **CdePkg**](https://github.com/KilianKegel/CdePkg) and 
GIT-[Subproject **CdeValidationPkg**](https://github.com/KilianKegel/CdeValidationPkg).

# Related Projects
| related project|annotation|
|:-|:-|
|[Torito C Library](https://github.com/JoaquinConoBolillo/torito-C-Library#torito-c-library)|C Library for UEFI Shell only. All projects below are built on or derived from *Torito C Library*|
|[Visual ANSI C for UEFI Shell](https://github.com/JoaquinConoBolillo/Visual-ANSI-C-for-UEFI-Shell#visual-ansi-c-for-uefi-shell)|Visual Studio for UEFI Shell for beginners.|
|[Visual DOS Tools for UEFI Shell](https://github.com/JoaquinConoBolillo/Visual-DOS-Tools-for-UEFI-Shell#visual-dos-tools-for-uefi-shell)|more command implementation|
|[Visual HWTools for UEFI Shell](https://github.com/KilianKegel/Visual-HWTools-for-UEFI-Shell#visual-hwtools-for-uefi-shell)|HWTools: PCI- and GPIOSpy for Baytrail. MemSpy for all.|
|[UDK2018-Minnowboard](https://github.com/KilianKegel/UDK2018-MinnowBoard#udk2018-minnowboard--cdepkg)|Gets the MinnowBoard running with the latest released EDK sourcecode and demonstrates *CdePkg* on real hardware|
|[edk2-UDK2018](https://github.com/KilianKegel/edk2-vUDK2018#edk2-udk2018--cdepkg)|Gets the Emulation (Nt32Pkg) running with the latest released EDK sourcecode and demonstrates *CdePkg* on the Windows Desktop|
|[CdePkg](https://github.com/KilianKegel/CdePkg#cdepkg)|*Torito C Library* redone for UEFI POST usage|
|[CdeValidationPkg](https://github.com/KilianKegel/CdeValidationPkg#cdevalidationpkg)|Unit tests for *CdePkg*|

## Revision history
### 20190906/improve tool chain check
* add IASL version check
* add PYTHON version check
* add NASM version check

### 20190901/tool chain check
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
