# PowerShell script to verify that all fixes are applied correctly

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Verifying Bug Fixes" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

$allPassed = $true

# Test 1: Check package-management.h for duplicates
Write-Host "Test 1: Checking package-management.h for duplicate content..." -ForegroundColor Yellow
$content = Get-Content "include/package-management.h" -Raw
$count = ([regex]::Matches($content, "#ifndef PACKAGE_MANAGEMENT_H")).Count
if ($count -eq 1) {
    Write-Host "  ✓ PASS: No duplicate header guards found" -ForegroundColor Green
} else {
    Write-Host "  ✗ FAIL: Found $count header guards (should be 1)" -ForegroundColor Red
    $allPassed = $false
}
Write-Host ""

# Test 2: Check package-sorter.cpp for correct implementation
Write-Host "Test 2: Checking package-sorter.cpp implementation..." -ForegroundColor Yellow
$content = Get-Content "src/package-sorter.cpp" -Raw
if ($content -match "PackageSorter::" -and $content -match "merge") {
    Write-Host "  ✓ PASS: PackageSorter implementation found" -ForegroundColor Green
} else {
    Write-Host "  ✗ FAIL: PackageSorter implementation missing" -ForegroundColor Red
    $allPassed = $false
}
if ($content -match "VehicleQueue") {
    Write-Host "  ✗ FAIL: Still contains Vehicle code (should be removed)" -ForegroundColor Red
    $allPassed = $false
} else {
    Write-Host "  ✓ PASS: No Vehicle code found" -ForegroundColor Green
}
Write-Host ""

# Test 3: Check main.cpp includes
Write-Host "Test 3: Checking main.cpp include statements..." -ForegroundColor Yellow
$content = Get-Content "main.cpp" -Raw
if ($content -match '#include "include/city_management\.h"') {
    Write-Host "  ✓ PASS: Correct include for city_management.h" -ForegroundColor Green
} else {
    Write-Host "  ✗ FAIL: Wrong include path for city management" -ForegroundColor Red
    $allPassed = $false
}
if ($content -match '#include "include/city_graph\.h"') {
    Write-Host "  ✗ FAIL: Still includes non-existent city_graph.h" -ForegroundColor Red
    $allPassed = $false
}
Write-Host ""

# Test 4: Check package-sorter.h includes
Write-Host "Test 4: Checking package-sorter.h include statements..." -ForegroundColor Yellow
$content = Get-Content "include/package-sorter.h" -Raw
if ($content -match '#include "package-management\.h"') {
    Write-Host "  ✓ PASS: Correct include for package-management.h" -ForegroundColor Green
} else {
    Write-Host "  ✗ FAIL: Wrong include path" -ForegroundColor Red
    $allPassed = $false
}
Write-Host ""

# Test 5: Check file structure
Write-Host "Test 5: Checking file structure..." -ForegroundColor Yellow
$requiredFiles = @(
    "main.cpp",
    "include/city_management.h",
    "include/delivery_exe_and_history.h",
    "include/package-management.h",
    "include/package-sorter.h",
    "include/Vehicle-management.h",
    "src/city_graph.cpp",
    "src/delivery_execution_and_history.cpp",
    "src/package-management.cpp",
    "src/package-sorter.cpp",
    "src/vehicle-management.cpp"
)

$missingFiles = @()
foreach ($file in $requiredFiles) {
    if (Test-Path $file) {
        Write-Host "  ✓ $file exists" -ForegroundColor Green
    } else {
        Write-Host "  ✗ $file MISSING" -ForegroundColor Red
        $missingFiles += $file
        $allPassed = $false
    }
}
Write-Host ""

# Summary
Write-Host "========================================" -ForegroundColor Cyan
if ($allPassed) {
    Write-Host "  ✓ ALL TESTS PASSED!" -ForegroundColor Green
    Write-Host "  The code is ready to compile." -ForegroundColor Green
    Write-Host ""
    Write-Host "Next steps:" -ForegroundColor Yellow
    Write-Host "  1. Install a C++ compiler (see HOW_TO_COMPILE_AND_RUN.md)" -ForegroundColor White
    Write-Host "  2. Compile: g++ -o main.exe main.cpp src/*.cpp -I." -ForegroundColor White
    Write-Host "  3. Run: .\main.exe" -ForegroundColor White
} else {
    Write-Host "  ✗ SOME TESTS FAILED" -ForegroundColor Red
    Write-Host "  Please review the errors above." -ForegroundColor Red
}
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check for compiler
Write-Host "Checking for C++ compiler..." -ForegroundColor Yellow
$compiler = Get-Command g++,gcc,cl -ErrorAction SilentlyContinue | Select-Object -First 1
if ($compiler) {
    Write-Host "  ✓ Compiler found: $($compiler.Name) at $($compiler.Source)" -ForegroundColor Green
    Write-Host "  You can compile the project now!" -ForegroundColor Green
} else {
    Write-Host "  ✗ No C++ compiler found" -ForegroundColor Red
    Write-Host "  Install MinGW, MSVC, or Clang to compile the project" -ForegroundColor Yellow
    Write-Host "  See HOW_TO_COMPILE_AND_RUN.md for instructions" -ForegroundColor Yellow
}
Write-Host ""
