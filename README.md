# 📂 Project Layout (recap)

```
cpp-from-scratch/
│
├── CMakeLists.txt          # main build script
├── include/                # headers
│   ├── vector.hpp
│   └── ...
├── src/                    # implementations
│   ├── vector.cpp
│   └── ...
├── main.cpp                # demo entrypoint
└── tests/                  # unit tests
    ├── test_vector.cpp
    └── CMakeLists.txt
```

---

# 🔹 Build & Run

From the root folder:

```bash
# 1. Generate build files
cmake -S . -B build

# 2. Build the project
cmake --build build

# 3. Run the main program
./build/main

# 4. Run tests
cd build
ctest --output-on-failure
```

---

# ⚙️ Explanation

- `include/` → all public headers (`.hpp`)
- `src/` → `.cpp` implementations (compiled into both `main` and tests)
- `main.cpp` → entrypoint for demo
- `tests/` → unit tests, each `.cpp` is compiled as its own test program
- `CMakeLists.txt` at root → configures the whole project
- `tests/CMakeLists.txt` → automatically builds all test files

👉 You can keep adding `.hpp` + `.cpp` pairs in `include/` and `src/`, and both `main` and `tests` will automatically use them.
