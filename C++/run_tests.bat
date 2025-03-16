@echo off
setlocal enabledelayedexpansion

REM Compile the project automatically.
g++ main.cpp user_code.cpp -o solution.exe

REM For each input file (.in) in the current directory,
REM run the solution with corresponding expected (.out) and actual output (.actual) files using a timeout.
for /f "delims=" %%f in ('dir /b /on *.in') do (
    set "filename=%%~nf"
    echo Running test case: %%f
    REM Call the PowerShell script with:
    REM -InputFile: current .in file
    REM -ExpectedFile: corresponding .out file
    REM -ActualFile: where the solution will write its output (.actual)
    REM -Timeout: in seconds (here 2 seconds)
    powershell -ExecutionPolicy Bypass -File run_with_timeout.ps1 -InputFile "%%f" -ExpectedFile "!filename!.out" -ActualFile "!filename!.actual" -Timeout 10
)

pause
