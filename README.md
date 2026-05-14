# litmath

Simple C++ math library for integers with:
- overflow checking
- unit tests
- clang-format
- clang-tidy
- CMake build system

## Features

- add
- subtract
- multiply
- divide
- pow
- factorial

## Requirements

- CMake 3.15+
- Ninja
- Clang 21
- GCC/Clang compiler

## Build

```bash
cd litmath
cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
```

## Run tests
```bash
ctest --test-dir build
```

## Run clang-format-check
```bash
cmake --build build --target format-check
```

## Run clang-format-fix
```bash
cmake --build build --target format-fix
```

## Run clang-tidy
```bash
cmake --build build --target tidy
```
