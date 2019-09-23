@echo off
if "%1" == "" (
   echo parameter missing: RELEASE or DEBUG
   goto EOF
)

for /F %%a in ('dir /s /b secmain.exe ^| find "%1_" /i') do (
    cd %%~pa
    secmain.exe /debug
)
:EOF