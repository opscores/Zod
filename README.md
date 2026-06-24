# The Zod Engine

A real-time strategy game remake of the original "Z" by The Bitmap Brothers.

- **Website:** http://zod.sourceforge.net
- **Contact:** freaknigh@hotmail.com

---

## Table of Contents

1. [Installation](#installation)
2. [Project Structure](#project-structure)
3. [Compilation](#compilation)
4. [Running the Game](#running-the-game)
5. [Command-Line Reference](#command-line-reference)
6. [Gameplay](#gameplay)
   - [Controls](#controls)
   - [Production Window](#production-window)
   - [Chat and Commands](#chat-and-commands)
7. [Dedicated Server](#dedicated-server)
8. [Troubleshooting](#troubleshooting)

---

## Installation

### Dependencies

| Library | Required | Notes |
|---------|----------|-------|
| SDL | Yes | |
| SDL_ttf | Yes | Font rendering |
| SDL_mixer | Yes | Audio |
| SDL_image | Yes | Image loading |
| libmysqlclient | No | Can compile without MySQL support |
| wxWidgets | Only for launcher | Not needed for engine or server |

### Ubuntu / Debian

```sh
sudo apt-get install build-essential
sudo apt-get install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev \
  libsdl-image1.2-dev libmysqlclient-dev libwxgtk3.2-dev
```

---

## Project Structure

- `maps/` — game map files (.map)
- `zod_engine/` — engine source code + makefile
  - **Known limitation:** ANIMAL_OBJECT (birds, ID=6 in enum) has graphics (`assets/other/birds/*`) and sounds (`assets/sounds/*BIRD*.wav`), but no handler exists to load/render them from `.map` files. The type is defined but never instantiated via `zclient.cpp::CreateObject()`.
- `zod_launcher/` — launcher source code + makefile
- `zod_mapeditor/` — map editor source code + makefile
  - `blank_maps/` — empty map templates for editing
- `default_settings.cfg` — game balance parameters
- `zod_launcher_settings.cfg` — launcher GUI settings
- `map_list.cfg` — map rotation list (planet 2)
- `mp3_map_list.cfg` — map rotation list (planet 3)
- `mp4_map_list.cfg` — map rotation list (planet 4)
- `README.md`

> **Note:** Map files (`.map`) are stored in `maps/`. The game uses XDG Base
> Directory paths: search order is CWD → `$XDG_DATA_HOME/zod/`
> (`~/.local/share/zod/`) → `$XDG_DATA_DIRS/zod/` → `DATA_DIR` (compile-time,
> default `/usr/share/games/zod/`). Configuration files are searched in CWD →
> `$XDG_CONFIG_HOME/zod/` (`~/.config/zod/`) → `$XDG_CONFIG_DIRS/zod/`
> (`/etc/xdg/zod/`). See `-A` flag to override data root.

---

## Compilation

The project consists of three independent programs:

### Engine

```sh
cd zod_engine
make
```

Output: `zod`

### Launcher

```sh
cd zod_launcher
make
```

Output: `zod_launcher`

### Map Editor

```sh
cd zod_mapeditor
make
```

Outputs: `zod_map_editor`, `tile_info_editor`, `map_merger`

### Build Options

| Variable | Default | Description |
|----------|---------|-------------|
| `OPENGL` | `0` | Set to `1` to enable OpenGL rendering |
| `JOBS` | `nproc` | Parallel build jobs |
| `DATA_DIR` | `/usr/share/games/zod` | System data root for installed packages |

> **Important:** Run `make clean` when switching `OPENGL` between `0` and `1`.
> Stale object files will cause linker errors.

---

## Running the Game

### Quick Start (Launcher)

```sh
./zod_launcher
```

The launcher provides a GUI for:
- **Local Game** — starts a server with bots and connects a player
- **Nighsoft Server** — connects to the official multiplayer server

### Manual (Direct)

```sh
# Local game with a bot opponent
./zod -m p02_bb_orig01.map -b red -n player1 -r 800x600 -w

# Connect to a remote server
./zod -c hestia.nighsoft.net -n player1 -t red -r 800x600 -w -o

# Run a dedicated server
./zod -d -l map_list.cfg -z default_settings.cfg
```

---

## Command-Line Reference

### Global Options

| Flag | Argument | Description |
|------|----------|-------------|
| `-c` | `ip_address` | Connect to a remote server |
| `-n` | `name` | Player name |
| `-t` | `team` | Team (`red`, `blue`, `green`, `yellow`) |
| `-r` | `WxH` | Screen resolution (e.g. `800x600`) |
| `-w` | — | Windowed mode |
| `-o` | — | Disable OpenGL |
| `-s` | — | Disable sound |
| `-u` | — | Disable music |
| `-k` | — | Use bland cursor (faster performance) |
| `-A` | `path` | Custom data root (overrides XDG data dir search; must contain `assets/` and `maps/`) |
| `-v` | — | Display version |
| `-h` | — | Display help |

### Server Options

| Flag | Argument | Description |
|------|----------|-------------|
| `-d` | — | Dedicated server (no graphics) |
| `-m` | `filename` | Single map to load |
| `-l` | `filename` | Map list file for rotation |
| `-z` | `filename` | Settings file |
| `-e` | `filename` | Perpetual server settings |
| `-b` | `team` | Add a bot to the specified team |

### Login Options

| Flag | Argument | Description |
|------|----------|-------------|
| `-g` | `name` | Login name |
| `-i` | `password` | Login password |

---

## Gameplay

### Controls

#### Mouse

| Action | Input |
|--------|-------|
| Select units | Left click |
| Move / attack | Right click |
| Control group | `Ctrl` + `0`–`9` |
| Waypoints | Hold `Shift` while giving orders |
| Ignore-move | Hold `Alt` while giving orders |
| Attack-move | Hold `Ctrl` while giving orders |
| Single-unit order | Hold `Z` — nearest unit obeys and leaves group |
| Rally point | Right-click while viewing a factory (no units selected) |
| Camera | Arrow keys, mouse at screen edge, click minimap, or hold middle mouse button |

#### Keyboard

| Key | Action |
|-----|--------|
| `H` | Toggle chat history |
| `P` | Show online player list |
| `M` | Toggle mouse capture (windowed mode) |
| `R` | Cycle robots |
| `G` | Cycle vehicles |
| `V` | Cycle all units |
| `B` | Open factory list |
| `/` | Start chat with `/` |
| `Enter` | Start chat |
| `Alt` + `V` | Change volume |
| `Ctrl` + `R` | Select all robots |
| `Ctrl` + `V` | Select all vehicles |
| `Ctrl` + `A` | Select all robots and vehicles |
| `Space` | Jump to last event |

#### R / G / V / B Buttons

Cycle through your units by type (robots, vehicles, all). The cycle starts with
the nearest unit to the cursor and resets after 7 seconds of inactivity.
The **B** button opens a scrollable list of all your factories.

### Production Window

Click a unit's portrait to open the production queue. Features:
- **Scroll wheel** — cycle through available unit types
- **[+]** — expand the queue panel
- **Last unit repeats** — the final entry in the queue loops indefinitely
- **Click a queued unit** — remove it from the list

### Chat and Commands

- Press `Enter` to chat
- Type `/help` for a list of server commands (start/stop bots, change maps, vote, etc.)

---

## Dedicated Server

Run a headless server with `-d`. No graphics, sound, or input libraries are
needed. Suitable for VPS or remote machines.

```sh
./zod -d -l map_list.cfg -z default_settings.cfg -b red -b blue
```

### Server Features

- Map rotation and voting
- AI bots for any team
- MySQL user registration and stats
- Online history tracking
- Player commands (via in-game chat `/`)

### Online Play / Activation

To control units on the official server, your account must be activated:

https://www.nighsoft.com/index.php?page=zod_activate

---

## Troubleshooting

If the game fails to start, try:

1. **Windowed mode:** `-w`
2. **Disable OpenGL:** `-o`
3. **Bland cursor:** `-k` (reduces GPU load)
4. **Verify all dependencies** are installed (see [Installation](#installation))
5. **Run from the engine directory** — the game expects `assets/` and `maps/`
   in the current working directory. Use `-A <path>` or install data to a
   standard XDG path (see [Command-Line Reference](#command-line-reference)).

For further help, visit: http://zod.sourceforge.net

---

*Builds: [CI pipeline](.github/workflows/ci.yml) produces Linux binaries on every push.*
