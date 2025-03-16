@echo off
setlocal enabledelayedexpansion

REM Compile the Java solution.
javac Main.java UserCode.java

REM For each input file (*.in) in the current directory,
REM run the solution using the PowerShell timeout script.
for /f "delims=" %%f in ('dir /b /on *.in') do (
    set "filename=%%~nf"
    echo Running test case: %%f
    REM Calling the PowerShell script and passing:
    REM - InputFile: current .in file
    REM - ExpectedFile: corresponding .out file
    REM - ActualFile: where the solution will write its output (.actual)
    REM - Timeout: 10 seconds
    REM - Command: "java Main" (which runs the test harness)
    powershell -ExecutionPolicy Bypass -File run_with_timeout.ps1 -InputFile "%%f" -ExpectedFile "!filename!.out" -ActualFile "!filename!.actual" -Timeout 1 -Command "java Main"
)

pause
