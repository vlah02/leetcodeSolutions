@echo off
REM This is a batch script to compile and run the specific .cpp file.

set FILENAME=problems/119_pascals-triangle-ii.cpp

echo Compiling %FILENAME%...

g++ %FILENAME% -o output_program
if %ERRORLEVEL% neq 0 (
    echo Compilation of %FILENAME% failed! Exiting...
    exit /b
)

echo Compilation of %FILENAME% successful! Running the program now...
output_program.exe

pause
