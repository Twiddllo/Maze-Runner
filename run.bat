@echo off
if exist maze_runner.exe (
    maze_runner.exe
) else (
    echo maze_runner.exe not found!
    echo Please build the project first using build.bat
    pause
)

