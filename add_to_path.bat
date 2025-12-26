@echo off
echo ========================================
echo   Add MinGW to System PATH
echo ========================================
echo.
echo This will permanently add C:\msys64\mingw64\bin to your PATH
echo so you can use g++ from any command prompt.
echo.
echo NOTE: This requires Administrator privileges!
echo.
pause

REM Check for admin rights
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: This script must be run as Administrator!
    echo.
    echo Right-click this file and select "Run as administrator"
    echo.
    pause
    exit /b 1
)

echo Adding to PATH...
setx /M PATH "%PATH%;C:\msys64\mingw64\bin"

if %errorlevel% equ 0 (
    echo.
    echo ========================================
    echo   SUCCESS!
    echo ========================================
    echo.
    echo MinGW has been added to your system PATH.
    echo.
    echo IMPORTANT: You need to:
    echo   1. Close this command prompt
    echo   2. Open a NEW command prompt
    echo   3. Test by running: g++ --version
    echo.
) else (
    echo.
    echo ========================================
    echo   FAILED!
    echo ========================================
    echo.
    echo Could not add to PATH. Please add manually:
    echo   1. Open System Properties
    echo   2. Click "Environment Variables"
    echo   3. Edit "Path" under System variables
    echo   4. Add: C:\msys64\mingw64\bin
    echo.
)

pause
