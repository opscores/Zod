# Zod CI/CD Pipeline (Linux)

## Build Structure

The project consists of three independent components:

```
zod_engine/    — Core game engine (C++)
zod_launcher/  — GUI launcher (wxWidgets)
zod_mapeditor/ — Map editor (recompiles engine sources)
```

## Supported Platforms

| Platform | GitHub Actions Runner | Build Status | Notes |
|----------|----------------------|--------------|-------|
| **Ubuntu** ✅ | `ubuntu-latest` | Engine + Launcher + Map Editor | Primary platform, full toolchain |

## Workflow

### 1. CI Pipeline (`.github/workflows/ci.yml`)

Triggers:
- Push to `main` or `develop`
- Pull request
- Push tag `v*` (also triggers release)

#### Jobs (run in parallel):

| Job | Platform | Component | Artifact |
|-----|----------|-----------|----------|
| `lint` | Ubuntu | cppcheck | — (exit code) |
| `linux-engine-build` (×2) | Ubuntu | Engine (OPENGL=0/1) | `zod-engine-linux-opengl0`, `zod-engine-linux-opengl1` |
| `linux-launcher-build` | Ubuntu | Launcher (wxWidgets) | `zod-launcher-linux` |
| `linux-mapeditor-build` | Ubuntu | Map Editor tools | `zod-mapeditor-linux` |
| `release` | Ubuntu | All artifacts → .tar.gz + GitHub Release | Tags `v*` only |
| `dev-package` | Ubuntu | All artifacts → .tar.gz + prerelease | `develop` branch only |

### 2. Release Pipeline

On tag push `v*`:
1. All build jobs produce binaries
2. `release` job downloads artifacts, packs into `zod-<tag>-linux.tar.gz`
3. Creates a GitHub Release with the archive attached

### 3. Dev Build Pipeline

On push to `develop`:
1. Same build process as stable release
2. Deletes the previous `develop-latest` release
3. Creates a new prerelease `Development Build — <sha>`

## Build Artifacts

| Artifact | Contents | Platform |
|----------|----------|----------|
| `zod-engine-linux-opengl0` | Engine binary (OpenGL disabled) | Ubuntu |
| `zod-engine-linux-opengl1` | Engine binary (OpenGL enabled) | Ubuntu |
| `zod-launcher-linux` | Launcher binary | Ubuntu |
| `zod-mapeditor-linux` | `zod_map_editor`, `tile_info_editor`, `map_merger` | Ubuntu |

## Release Archive Layout

```
zod-v1.0.0-linux.tar.gz
└── Zod/
    ├── zod_engine/
    │   ├── zod           (OPENGL=0, default)
    │   └── zod-opengl    (OPENGL=1)
    ├── zod_launcher/
    │   └── zod_launcher
    ├── zod_mapeditor/
    │   ├── zod_map_editor
    │   ├── tile_info_editor
    │   └── map_merger
    ├── assets/
    │   └── fonts/, gfile.zg?, ...
    └── maps/
        └── *.map
```

## Building Locally

### Engine:
```bash
cd zod_engine && make clean && OPENGL=0 JOBS=$(nproc) make
cd zod_engine && make clean && OPENGL=1 JOBS=$(nproc) make
```

### Launcher:
```bash
cd zod_launcher
sudo apt-get install libwxgtk3.2-dev
make clean && make
./zod_launcher
```

### Map Editor:
```bash
cd zod_mapeditor
sudo apt-get install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev libsdl-image1.2-dev libmysqlclient-dev
make clean && make
```

Produces three tools: `zod_map_editor`, `tile_info_editor`, `map_merger`.
Recompiles engine sources from `../zod_engine/` — does not depend on pre-built engine artifacts.

## Debugging

### Dependency check:
```bash
dpkg -l libsdl1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev libwxgtk3.2-dev | grep "^ii"
```

### Verbose build:
```bash
cd zod_engine && make clean && OPENGL=0 JOBS=4 make 2>&1 | tee build.log
```

## Recommendations

1. **Do not commit `*.o` files** — they are ignored via `.gitignore`
2. **Test locally before pushing** — CI is fast (~1-2 min) but not unlimited
3. **Use `v*` tags for releases** — CI builds and packages automatically
4. **OPENGL=0** — default mode (software render); **OPENGL=1** — hardware acceleration
