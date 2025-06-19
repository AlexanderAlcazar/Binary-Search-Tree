# Binary Search Tree

This repository contains an implementation of a generic Binary Search Tree (BST) in C++. The project was developed as part of a Data Structures and Algorithms class.

## Overview

- **Language:** C++ (with some C and CMake for build configuration)
- **Key File Implemented:** `bst.h`
- **Project Focus:** Implementation of templated classes and recursive algorithms

## Description

The core of this project is the `bst.h` file, which defines a templated Binary Search Tree supporting typical BST operations. Templating allows the BST to store any data type that supports comparison operations. Most of the logic relies on recursive methods for operations such as insertion, search, and traversal.

All other files and build configurations were provided as part of the course framework. This repository primarily demonstrates understanding and application of abstract data types, recursion, and template programming in C++.

## Features

- **Templated Classes:** Store any comparable data type
- **Recursive Algorithms:** For insertion, deletion, searching, and traversals
- **Educational Purpose:** Developed for a Data Structures and Algorithms class assignment

## Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/AlexanderAlcazar/Binary-Search-Tree.git
   ```
2. **Build with CMake:**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. **Run the executable** (details depend on provided files).

## File Structure

- `bst.h` — Main BST implementation (templated, recursive)
- Other files — Provided starter code and build configuration

## License

This project is for educational purposes.
