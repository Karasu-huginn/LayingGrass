<div align="center">

# Laying Grass

A competitive terminal-based tile-placement strategy game where players battle to claim the largest territory on a shared board.

[![C++](https://img.shields.io/badge/C++-11+-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D4?style=flat-square&logo=windows&logoColor=white)](#prerequisites)
[![Players](https://img.shields.io/badge/Players-1--9-green?style=flat-square)](#how-to-play)

</div>

## Overview

**Laying Grass** is a turn-based strategy game played entirely in the terminal. Each player takes turns placing polyomino tiles (think Tetris-shaped pieces) onto a shared grid, trying to build the largest connected territory. With 96 unique tile shapes, bonus mechanics like tile robbery and stone obstacles, and support for up to 9 players, every match plays out differently.

```
        A B C D E F G H I J K L M N O P Q R S T

A       . . . . . . . . . . . E . . . . . . . .
B       . . . . . . . . . . . . . . . . . . . .
C       . . a a . . . . . . . . . . . . . . . .
D       . . . a . . . . . . . . . R . . . . . .
E       . . . a a . . . . . . . . . . . . . . .
F       . . . . . . . . . . . . . . . . . . . .
G       . . . . . . . . . . . . . . . . . . E .
```

## Features

- **Polyomino tile placement** -- 96 unique tiles loaded from JSON, each fitting a 6x6 grid with distinct shapes
- **Territory control** -- place tiles adjacent to your existing territory to expand your turf
- **Tile manipulation** -- rotate and flip tiles before placing them to find the perfect fit
- **Bonus system** -- capture bonus cells on the board to earn exchange coupons, place stone obstacles, or rob enemy tiles
- **Dynamic board size** -- 20x20 grid for 1-4 players, 30x30 for 5-9 players
- **Colorized output** -- each player's territory is rendered in a distinct ANSI color

## Prerequisites

- **Windows** (uses `windows.h` for terminal control)
- **GCC** (MinGW or similar)
- `Tileslist.json` -- tile definitions file placed in the same directory as the executable

## Build

**With Code::Blocks:**

Open `LayingGrass.cbp` and build the project (Ctrl+F9).

**From the command line:**

```bash
g++ -Wall -O2 -o LayingGrass.exe main.cpp Game.cpp Board.cpp Player.cpp Tile.cpp Color.cpp
```

## How to Play

### 1. Setup

Run the executable and enter the number of players (1-9). Each player then chooses a name and places their starting base tile on the board.

### 2. Turns

Each round, players pick from these actions:

| Action | Description |
|--------|-------------|
| **Exchange tile** | Swap your current tile with one from the queue (costs an exchange coupon) |
| **Place tile** | Set the current tile on the board adjacent to your territory |
| **Rotate tile** | Rotate the tile 90 degrees counter-clockwise |
| **Flip tile** | Mirror the tile horizontally or vertically |
| **End turn** | Skip placing and pass to the next player |

You can see your current tile and the next 5 tiles in the queue at all times.

### 3. Bonuses

The board contains randomly placed bonus cells. Surround a bonus cell with your tiles to activate it:

- **Exchange (E)** -- earn an extra tile exchange coupon
- **Stone (S)** -- place a stone obstacle to block opponents
- **Robbery (R)** -- convert an enemy tile to your color

### 4. End Game

When all turns are exhausted, players can spend remaining exchange coupons to buy 1x1 grass tiles for last-minute territory grabs. The player with the **largest connected territory** wins. Ties are broken by total tile count.

## Project Structure

```
LayingGrass/
  main.cpp / main.h         # Entry point
  Game.cpp / Game.h          # Game loop, turn management, tile queue
  Board.cpp / Board.h        # Board state, placement rules, victory check
  Tile.cpp / Tile.h          # Tile shapes and transformations
  Player.cpp / Player.h      # Player state and bonus tracking
  Color.cpp / Color.h        # ANSI color output
  nlohmann/                  # JSON parsing library (header-only)
  Tileslist.json             # Tile definitions (96 tiles)
```

## Dependencies

| Dependency | Purpose |
|------------|---------|
| [nlohmann/json](https://github.com/nlohmann/json) | Header-only JSON library used to parse tile definitions |

All other dependencies are from the C++ standard library.
