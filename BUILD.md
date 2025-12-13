# Building Maze Runner

This document provides detailed instructions for building Maze Runner on different platforms and compilers.

## Prerequisites

- A C++ compiler that supports C++11 or later
- Windows OS (current version is Windows-specific)

## Windows

### Using MinGW (GCC)

1. Install MinGW-w64 or use MSYS2
2. Open terminal in the project directory
3. Compile:
   ```bash
   g++ -std=c++11 -o maze_runner app.cpp
   ```
4. Run:
   ```bash
   ./maze_runner.exe
   ```

### Using Visual Studio (MSVC)

1. Open Developer Command Prompt for VS
2. Navigate to project directory
3. Compile:
   ```cmd
   cl /EHsc app.cpp /Fe:maze_runner.exe
   ```
4. Run:
   ```cmd
   maze_runner.exe
   ```

### Using Clang

1. Install LLVM/Clang for Windows
2. Compile:
   ```bash
   clang++ -std=c++11 -o maze_runner app.cpp
   ```
3. Run:
   ```bash
   ./maze_runner.exe
   ```

### Using Makefile

If you have Make installed (via MinGW or MSYS2):

```bash
make
make run
```

## Compiler Flags

Recommended flags for better code quality:

```bash
g++ -std=c++11 -Wall -Wextra -O2 -o maze_runner app.cpp
```

- `-std=c++11`: C++11 standard
- `-Wall`: Enable all warnings
- `-Wextra`: Extra warning flags
- `-O2`: Optimization level 2

## Troubleshooting

### Error: `conio.h: No such file or directory`
- This is a Windows-specific header. The current version only works on Windows.

### Error: `system("cls")` not working
- This is Windows-specific. On other platforms, you would need to use platform-specific screen clearing.

### Linker Errors
- Make sure you're using a complete C++ compiler installation
- Ensure all standard library headers are available

## Future: Cross-Platform Support

A future version may include:
- Linux support (using `ncurses` or similar)
- macOS support
- Cross-platform screen clearing
- Platform detection and conditional compilation

