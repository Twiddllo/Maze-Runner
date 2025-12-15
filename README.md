# 🎮 Maze Runner

A terminal-based maze game written in **C++** where you navigate through a large ASCII maze while being hunted by ghosts — now with **settings, smarter scoring, two ghost AI modes, and in-memory leaderboards**.

---

## 📖 About

**Maze Runner** is a console maze game developed as a university project for **Shahid Chamran University (SCU)**. Your goal is simple: survive, avoid ghosts, and reach the exit. The challenge comes from configurable ghost behavior, limited lives, and score pressure.

This version is a **major upgrade** over the previous one, focusing on:
- Better game control via settings
- Two different ghost movement models
- Improved UI inside the terminal
- Clean separation of gameplay logic

---

## ✨ Features

- 🧱 **Large ASCII Maze** (51×76)
- 👻 **Configurable Ghost Enemies** (1–10 ghosts)
- 🧠 **Two Ghost Movement Modes**
  - Movement-based (every N player moves)
  - Time-based (every X seconds)
- ❤️ **Custom Lives System** (1–10 hearts)
- 🏆 **Score System** with optional smart scoring
- 📊 **Top-20 In-Memory Leaderboard** (sorted)
- ⚙️ **Full Settings Menu** (change difficulty at runtime)
- 🕹️ **Real-Time Controls** using `conio.h`
- 🧪 **Hidden Cheat Modes** (intentional 👀)

---

## 🎮 Controls

| Key | Action |
|----|-------|
| `W` | Move Up |
| `S` | Move Down |
| `A` | Move Left |
| `D` | Move Right |
| `O` | Exit game (with confirmation) |

Controls are **case-insensitive**.

---

## 🛠️ Building & Running

### Prerequisites
- **Windows OS**
- C++ compiler (GCC / MinGW or MSVC)
- `conio.h` support (Windows-only)

### Compilation

**GCC / MinGW**
```bash
g++ app.cpp -o maze_runner
```

**MSVC**
```bash
cl app.cpp /Fe:maze_runner.exe
```

### Running
```bash
maze_runner.exe
```

---

## 📁 Project Structure

```
MAZE RUNNER/
├── app.cpp      # Entire game logic
└── README.md    # Documentation
```

> No external files are required. Game history is stored **in memory only** (per run).

---

## 🎯 Game Mechanics

### Player
- Starts at the **first empty space** in the maze
- Represented by `P`
- Has limited hearts (configurable)

### Ghosts
- Represented by `G`
- Spawn randomly on empty tiles
- Chase the player directly (greedy movement)
- Can move:
  - Every **N moves** (movement-based)
  - Every **X seconds** (time-based)

### Exit
- Represented by `O`
- Reaching it ends the game with bonus score

### Scoring
- +20 points for reaching the exit
- −5 points when caught by a ghost
- Optional **Smart Scoring**:
  - Rewards faster completion
  - Gives bonus for remaining lives

### Game Over
- Happens when lives reach **0**
- Score resets to 0 and is added to history

---

## ⚙️ Settings Menu

Accessible from the main menu.

You can modify:
- Number of ghosts (1–10)
- Ghost speed (1–20)
- Player hearts (1–10)
- Enable / disable smart scoring
- Switch ghost movement mode
- Adjust time interval (time-based mode only)

All changes apply **immediately**.

---

## 🧠 Ghost Movement Modes

### 1️⃣ Movement-Based
- Ghosts move every **N player actions**
- More predictable
- Easier to plan around

### 2️⃣ Time-Based
- Ghosts move **even if player does nothing**
- Uses `clock()` for timing
- More pressure, harder gameplay

---

## 📊 Leaderboard

- Stored in memory using `vector`
- Sorted automatically (highest score first)
- Displays **top 20 players** only
- Reset when program exits

---

## 🐛 Known Limitations

- Windows-only (`conio.h`, `system("cls")`)
- Ghost AI is direct and non-pathfinding
- No save/load between runs
- ASCII rendering depends on terminal width

---

## 🔮 Possible Future Improvements

- [ ] Cross-platform (remove `conio.h`)
- [ ] File-based persistent leaderboard
- [ ] Pathfinding ghosts (BFS / A*)
- [ ] Dynamic maze generation
- [ ] Difficulty presets
- [ ] Sound effects

---

## 👤 Author

**twiddllo**

---

## 🏫 Institution

**Shahid Chamran University (SCU)**

---

## 📄 License

Open-source, educational use only.

---

> This project prioritizes **clarity, control, and raw logic** over polish. If something feels hard — that’s intentional.
