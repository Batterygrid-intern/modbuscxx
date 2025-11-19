# modbusRtu

A C++ wrapper library for libmodbus communication.

## Features
- Modbus RTU support
- Future: Modbus TCP/IP support (planned)

## Dependencies
- libmodbus
- CMake (build tool)

### Installing libmodbus

**Ubuntu/Debian:**
```bash
sudo apt-get install libmodbus-dev
```

**Fedora/RHEL:**
```bash
sudo dnf install libmodbus-devel
```

**macOS:**
```bash
brew install libmodbus
```

## Building

### Static library (default)
```bash
cmake -B build
cmake --build build
```

### Shared library
```bash
cmake -B build -DBUILD_SHARED_LIBS=ON
cmake --build build
```

## Using with CMake FetchContent

Add this to your `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    modbuscxx
    GIT_REPOSITORY https://github.com/Batterygrid-intern/modbusRTU.git
    GIT_TAG main  # or specify a tag/commit
)

FetchContent_MakeAvailable(modbuscxx)

# Link to your target
target_link_libraries(your_target PRIVATE modbuscxx::modbusRtu)
```

### Building as Shared Library with FetchContent

```cmake
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(modbuscxx)
```

## Library Components

### Modbus RTU
Currently available for serial RTU communication.

**Include in your code:**
```cpp
#include <modbuscxx/modbusRtu.hpp>
```

### Modbus TCP/IP
Coming soon - TCP/IP communication support will be added in future releases.

**Future include:**
```cpp
#include <modbuscxx/modbusTcp.hpp>
```
