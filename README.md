# 🎮 Maze Runner

A terminal-based maze game written in C++ where you navigate through a maze while avoiding ghosts!

## 📖 About

Maze Runner is a classic maze navigation game developed for **Shahid Chamran University (SCU)**. Navigate through a complex maze, avoid the chasing ghosts, and reach the exit to win! The game features a scoring system, lives management, and a history tracker to keep track of your best scores.

## ✨ Features

- 🎯 **Classic Maze Gameplay**: Navigate through a carefully designed 51x76 maze
- 👻 **Ghost Enemies**: Three ghosts that chase you through the maze
- ❤️ **Lives System**: Start with 3 lives - lose them all and it's game over!
- 📊 **Score Tracking**: Earn points and compete for high scores
- 📜 **Game History**: View your previous game scores
- 🎮 **Simple Controls**: Easy-to-use WASD movement controls
- 🏆 **Win Condition**: Reach the exit (O) to win the game

## 🎮 How to Play

1. **Start the game** and select option `1` from the menu
2. **Enter your player name** (no spaces allowed)
3. **Navigate** using:
   - `W` - Move Up
   - `S` - Move Down
   - `A` - Move Left
   - `D` - Move Right
4. **Avoid ghosts** (G) - they will chase you!
5. **Reach the exit** (O) to win
6. **Press `O`** during gameplay to exit to menu

## 🛠️ Building & Running

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Windows OS (uses `conio.h` and `cls` command)

### Compilation

**Using GCC (MinGW on Windows):**
```bash
g++ -o maze_runner app.cpp
```

**Using MSVC (Visual Studio):**
```bash
cl app.cpp /Fe:maze_runner.exe
```

**Using Clang:**
```bash
clang++ -o maze_runner app.cpp
```

### Running
```bash
./maze_runner
# or on Windows:
maze_runner.exe
```

## 📁 Project Structure

```
MAZE RUNNER/
├── app.cpp          # Main game source code
├── history.txt      # Game history file (auto-generated)
└── README.md        # This file
```

## 🎯 Game Mechanics

- **Player (P)**: You start at the first empty space in the maze
- **Ghosts (G)**: Three ghosts spawn randomly and chase you every 10 moves
- **Exit (O)**: Reach this to win and earn 20 bonus points
- **Lives**: You have 3 lives. Getting caught by a ghost costs 1 life and 5 points
- **Score**: Earn points by surviving and reaching the exit
- **Walls**: Cannot pass through walls (represented by maze characters)

## 📝 Game History

The game automatically saves your scores to `history.txt`. View your game history from the main menu by selecting option `2`.

## 🎨 Game Map

The game features a custom-designed ASCII maze with walls, corridors, and an exit point. The maze is 51 rows by 76 columns, providing a challenging navigation experience.

## 🐛 Known Limitations

- Windows-specific (`conio.h` and `cls` command)
- Player name cannot contain spaces
- Ghosts move every 10 player moves (fixed interval)

## 🔮 Future Improvements

- [ ] Cross-platform support (Linux/Mac)
- [ ] Configurable ghost movement speed
- [ ] Time-based scoring system
- [ ] Multiple difficulty levels
- [ ] Random maze generation
- [ ] Power-ups and collectibles

## 👤 Author

**twiddllo**

## 🏫 Institution

**Shahid Chamran University (SCU)**

## 📄 License

This project is open source and available for educational purposes.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to fork this project and submit pull requests.

---

**Enjoy playing Maze Runner! 🎮✨**

