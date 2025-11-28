@echo off
echo Configuring CMake project with Visual Studio 2022...

cmake -B build -G "Visual Studio 17 2022" -A x64

if %errorlevel% equ 0 (
    echo Configuration successful!
    echo Build files generated in 'build' directory
) else (
    echo Configuration failed!
    pause
)