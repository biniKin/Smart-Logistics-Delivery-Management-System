@echo off
echo ========================================
echo   Verifying Bug Fixes
echo ========================================
echo.

echo Test 1: Checking package-management.h...
findstr /C:"#ifndef PACKAGE_MANAGEMENT_H" include\package-management.h > nul
if %errorlevel%==0 (
    echo   [PASS] Header file exists
) else (
    echo   [FAIL] Header file issue
)

echo.
echo Test 2: Checking package-sorter.cpp...
findstr /C:"PackageSorter" src\package-sorter.cpp > nul
if %errorlevel%==0 (
    echo   [PASS] PackageSorter implementation found
) else (
    echo   [FAIL] PackageSorter implementation missing
)

echo.
echo Test 3: Checking main.cpp includes...
findstr /C:"city_management.h" main.cpp > nul
if %errorlevel%==0 (
    echo   [PASS] Correct include found
) else (
    echo   [FAIL] Wrong include path
)

echo.
echo Test 4: Checking file structure...
if exist main.cpp echo   [OK] main.cpp
if exist include\city_management.h echo   [OK] city_management.h
if exist include\delivery_exe_and_history.h echo   [OK] delivery_exe_and_history.h
if exist include\package-management.h echo   [OK] package-management.h
if exist include\package-sorter.h echo   [OK] package-sorter.h
if exist include\Vehicle-management.h echo   [OK] Vehicle-management.h
if exist src\city_graph.cpp echo   [OK] city_graph.cpp
if exist src\delivery_execution_and_history.cpp echo   [OK] delivery_execution_and_history.cpp
if exist src\package-management.cpp echo   [OK] package-management.cpp
if exist src\package-sorter.cpp echo   [OK] package-sorter.cpp
if exist src\vehicle-management.cpp echo   [OK] vehicle-management.cpp

echo.
echo ========================================
echo   Verification Complete
echo ========================================
echo.
echo To compile and run:
echo   1. Install MinGW or Visual Studio
echo   2. Run: g++ -o main.exe main.cpp src/*.cpp -I.
echo   3. Run: main.exe
echo.
echo See HOW_TO_COMPILE_AND_RUN.md for details
echo.
pause
