@echo off
echo ========================================
echo   Quick Test - Smart Logistics System
echo ========================================
echo.
echo This will run the Integrated Test (Option 6)
echo.
pause

REM Create input file for automated testing
echo 6> test_input.txt
echo 0>> test_input.txt

echo Running test...
echo.

REM Run with input redirection
main_fixed.exe < test_input.txt

echo.
echo ========================================
echo   Test Complete!
echo ========================================
echo.
echo If you saw all the test outputs above, the program is working correctly!
echo.

REM Cleanup
del test_input.txt

pause
