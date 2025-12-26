@echo off
echo ========================================
echo Testing Smart Logistics Management System
echo ========================================
echo.
echo NOTE: This will test the existing main.exe
echo The exe was compiled BEFORE the fixes were applied.
echo To test the fixed version, you need to recompile with a C++ compiler.
echo.
echo Recommended compilers:
echo 1. MinGW-w64: https://www.mingw-w64.org/
echo 2. MSYS2: https://www.msys2.org/
echo 3. Visual Studio (includes MSVC compiler)
echo.
echo After installing a compiler, run:
echo    g++ -o main.exe main.cpp src/*.cpp -I.
echo.
echo ========================================
echo Running existing main.exe...
echo ========================================
echo.

REM Run the program (it will wait for user input)
main.exe

echo.
echo ========================================
echo Test completed!
echo ========================================
pause
