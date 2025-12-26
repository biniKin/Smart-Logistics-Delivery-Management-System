@echo off
echo ========================================
echo   Smart Logistics Management System
echo ========================================
echo.

if not exist main_fixed.exe (
    echo ERROR: main_fixed.exe not found!
    echo.
    echo Please compile first by running: compile.bat
    echo.
    pause
    exit /b 1
)

echo Starting program...
echo.
echo ========================================
echo.

REM Run the program
main_fixed.exe

echo.
echo ========================================
echo   Program Ended
echo ========================================
pause
