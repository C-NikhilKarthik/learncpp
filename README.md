# 📘 Project Overview

This repository is a **“C++ From Scratch” learning project** where we implement fundamental C++ data structures and concepts manually — instead of relying on the STL.

The goals are:

- Build **deep knowledge** of how STL containers and utilities work internally.
- Practice **manual memory management** (`malloc/free`, `new/delete`, placement new).
- Understand the **Rule of 3/5/0**, copy/move semantics, destructors, RAII.
- Learn how to structure a **professional C++ project** using `include/`, `src/`, `tests/`, and **CMake**.
- Gain experience writing **unit tests** and compiling/running them with CTest.

Examples of what will be implemented:

- `Vector<T>` (like `std::vector`)
- `String` (like `std::string`)
- `LinkedList`, `Stack`, `Queue`
- Smart pointers (`UniquePtr`, `SharedPtr`)
- Memory pool, thread pool, and more advanced features

---

# 📂 Project Layout

```
cpp-from-scratch/
│
├── CMakeLists.txt          # Main CMake build script
├── include/                # Public headers (declarations/interfaces)
│   ├── vector.hpp
│   └── ...
├── src/                    # Implementations (definitions)
│   ├── vector.cpp
│   └── ...
├── main.cpp                # Demo entrypoint (showcase usage)
└── tests/                  # Unit tests for each component
    ├── test_vector.cpp
    └── CMakeLists.txt
```

---

# 🔹 How It Works

- **include/**
  Contains all public headers (`.hpp`). Each class is declared here with its member variables and function signatures. Example: `vector.hpp` declares the `Vector<T>` class.

- **src/**
  Contains the actual function/method definitions (`.cpp`). Example: `vector.cpp` defines how `Vector<T>::push_back()` works, including dynamic memory resizing.

- **main.cpp**
  Acts as a **demo driver**. You can quickly test or showcase how your data structures are used (like inserting into `Vector`, printing values, etc.).

- **tests/**
  Contains **unit tests** for individual components. Each `.cpp` file inside `tests/` is compiled into its own executable and registered as a test via CMake/CTest. This lets you run automated tests (`ctest`) to validate everything works.

- **CMakeLists.txt**
  The main build script that:

  - Configures C++ standard
  - Finds all `.cpp` files in `src/`
  - Builds the `main` executable
  - Adds the `tests/` subdirectory and enables unit testing

- **tests/CMakeLists.txt**
  Automatically builds all test files inside `tests/`. Each file becomes its own executable and is registered with CTest so you can run them with one command.

---

# 🔹 Build & Run

From the root folder:

```bash
# 1. Generate build files
cmake -S . -B build

# 2. Build the project
cmake --build build

# 3. Run the main program (demo usage)
./build/main

# 4. Run all tests
cd build
ctest --output-on-failure
```

---

# 📈 Why This Structure?

- Mirrors **real-world C++ projects** (headers, implementations, tests).
- Allows **incremental growth** — add new headers/implementations without touching build scripts.
- Separates **library code** (`include/`, `src/`) from **application code** (`main.cpp`) and **tests** (`tests/`).
- Resume-friendly: shows familiarity with **CMake**, unit testing, and modular design.
