@echo off
echo Building Maze Runner...
echo.

REM Try to find g++ in common locations
where g++ >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Using GCC compiler...
    g++ -std=c++11 -Wall -Wextra -o maze_runner.exe app.cpp
    if %ERRORLEVEL% EQU 0 (
        echo.
        echo Build successful! Run maze_runner.exe to play.
    ) else (
        echo.
        echo Build failed!
    )
) else (
    echo GCC not found. Please install MinGW or add it to your PATH.
    echo.
    echo Alternatively, you can compile manually:
    echo   g++ -std=c++11 -o maze_runner.exe app.cpp
    pause
)

