# 🛠 CMake Structure — MathFunc

## 📌 Project Initialization

```cmake
cmake_minimum_required(VERSION 3.23)
project(MathFunc)
```

* **cmake_minimum_required** — minimal required CMake version
* **project** — defines project name

---

## ⚙ Build Configuration

```cmake
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
```

* `Debug` — no optimization, удобен для обучения
* `Release` — optimized fast version

```cmake
set(CMAKE_CXX_STANDARD 17)
```

* Sets C++17 standard

---

## 🚫 Debug Flags

```cmake
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
```

* `-O0` — disable optimizations
* `-Werror=return-type` — error if function has no return

---

## 📂 Output Directories

```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
```

| Type        | Folder    |
| ----------- | --------- |
| Executables | build/bin |
| Static libs | build/lib |
| Shared libs | build/lib |

---

## 📚 Library Creation

```cmake
add_library(str_modes_lib
    src/compressor.cpp
    src/decompressor.cpp
    src/decrypt-chesar.cpp
    src/encrypt-chesar.cpp
)
```

Creates static library **str_modes_lib**

```cmake
target_include_directories(str_modes_lib PUBLIC include)
```

* `PUBLIC` → headers are visible to everything that links this library

---

## ▶ Executable

```cmake
add_executable(program app/main.cpp)
target_link_libraries(program PRIVATE str_modes_lib)
```

* Creates executable **program**
* Links library privately

---

# 🧪 Tests (Optional)

Enable tests:

```bash
cmake -B build -DBUILD_TESTS=ON
```

---

## 🔄 Fetch Catch2

```cmake
FetchContent_Declare(...)
FetchContent_MakeAvailable(Catch2)
```

Downloads Catch2 automatically during build.

---

## 🧩 Test Executable

```cmake
add_executable(tests
    tests/compressor_tests.cpp
    tests/decompressor_tests.cpp
    tests/decrypt_chesar_tests.cpp
    tests/encrypt_chesar_tests.cpp
)
```

```cmake
target_link_libraries(tests PRIVATE str_modes_lib Catch2::Catch2WithMain)
```

---

## 🏃 Run Tests

```cmake
enable_testing()
add_test(NAME TestsStrModesFunction COMMAND tests)
```

Then:

```bash
cd build
ctest
```

---

# 📁 Project Structure

```
MathFunc/
│
├── include/          # headers
├── src/              # library source files
├── app/              # main.cpp
├── tests/            # unit tests
└── CMakeLists.txt
```

---

# 🧠 Architecture Idea

* Core logic → library
* Main program → uses library
* Tests → test library
