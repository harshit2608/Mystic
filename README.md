# Mystic

Mystic is a 3D game engine.
Its currently in WIP.

## Supported Platforms

- [x] Macosx
- [ ] Windows
- [ ] Linux

## Getting Started

Start by cloning the repository with

_For Users:_

```shell
git clone --recursive --depth=1 https://github.com/harshit2608/Mystic.git
```

_For Developers:_

```shell
git clone --recursive https://github.com/harshit2608/Mystic.git
```

If the repository was cloned non-recursively previously, use

```shell
git submodule update --init
```

to clone the necessary submodules.

<b>After cloning the repository.</b>

- Download premake and place it inside `vendor\premake\bin`
- Run project generation script frojm `scripts\{Your-Platform}-GenProjects`
- Build the project
