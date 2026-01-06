CPP_CONSOLE_TASKLIST

A simple console-based task manager application.

## WORK IN PROGRESS

## Motivation

The goal is to build a simple console application that can serve
as a helper for future projects.

## Features

- View tasks
- Add tasks from console

## Windows (prebuilt)

Download the `.exe` from the Releases page and run it.

## Requirements

- CMake 3.10+
- C++17 compiler
    - Windows: Visual Studio 2019+ / MinGW-64
    - Linux: g++ 7+ / clang++ 6+
    - macOS: Xcode / clang++
- No additional libraries needed

## Build from source

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Planned featurs

- Mark completed tasks
- Save progress to file
- Load progress from file
