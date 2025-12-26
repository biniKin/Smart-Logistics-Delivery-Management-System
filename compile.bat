@echo off
echo ========================================
echo   Compiling Smart Logistics System
echo ========================================
echo.

REM Add MinGW to PATH for this session
set PATH=C:\msys64\mingw64\bin;%PATH%

REM Check if compiler is available
g++ --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: g++ compiler not found!
    echo Please install MSYS2 or add it to your PATH
    pause
    exit /b 1
)

echo Compiler found: g++ (MSYS2)
echo.
echo Compiling...
echo.

REM Compile the project
g++ -o main_fixed.exe main.cpp src/city_graph.cpp src/delivery_execution_and_history.cpp src/package-management.cpp src/package-sorter.cpp src/vehicle-management.cpp -I.

if %errorlevel% equ 0 (
    echo.
    echo ========================================
    echo   Compilation Successful!
    echo ========================================
    echo.
    echo Output: main_fixed.exe
    echo.
    echo To run the program:
    echo   1. Double-click main_fixed.exe
    echo   2. Or run: run.bat
    echo.
) else (
    echo.
    echo ========================================
    echo   Compilation Failed!
    echo ========================================
    echo.
    echo Please check the error messages above.
    echo.
)

pause
