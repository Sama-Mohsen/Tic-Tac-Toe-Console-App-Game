# Tic-Tac-Toe-Console-App-Game
## X/O Game - Tic Tac Toe with Sound Effects

### Overview
This project is a **Tic Tac Toe (X/O) game** implemented in C++. It includes an interactive interface with **sound effects** for various game events, enhancing the gaming experience. The game allows for **player vs. player** and **player vs. bot** modes.

### Features
- **Single-player mode**: Play against a computer-controlled bot.
- **Multiplayer mode**: Compete against another player.
- **Sound effects**: Includes sounds for welcome, correct moves, errors, success, and game over.
- **Dynamic Interface**: Uses color and animation effects to enhance gameplay.

### Dependencies
- C++ Compiler (GCC, Clang, or MSVC)
- *canberra-gtk-play* for sound effects (pre-installed on most Linux systems)

### Installation & Usage
#### 1. Clone the Repository
```bash
git clone <repository_url>
cd <project_directory>
```

#### 2. Compile the Project
```bash
g++ main.cpp -o xo_game
```

#### 3. Run the Application
```bash
./xo_game
```

#### 4. Controls
- Enter numbers (1-9) to place your mark.
- The game automatically detects wins and draws.
- Sound effects play for different game events.

### Notes
- Sound effects are played using `canberra-gtk-play`, which must be installed for audio to work.
- If any issues occur, try running the game without sound by commenting out the system commands in the code.
