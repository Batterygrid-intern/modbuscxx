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

## Usage Example

### Basic Modbus RTU Usage

```cpp
#include <modbuscxx/modbusRtu.hpp>
#include <iostream>
#include <vector>

int main() {
    try {
        // Create Modbus RTU connection
        // Parameters: device, baud_rate, parity, data_bits, stop_bits
        modbusRtu modbus("/dev/ttyUSB0", 9600, 'N', 8, 1);
        
        // Connect to the device
        if (!modbus.connect()) {
            std::cerr << "Failed to connect" << std::endl;
            return 1;
        }
        
        // Read holding registers
        int slave_id = 1;        // Modbus slave/site ID
        int start_addr = 0;      // Starting register address
        int num_registers = 10;  // Number of registers to read
        
        uint16_t buffer[10];
        modbus.read_values(slave_id, start_addr, num_registers, buffer);
        
        // Print raw register values
        std::cout << "Register values: ";
        for (int i = 0; i < num_registers; i++) {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
        
        // Convert two consecutive registers to float (if needed)
        float value = modbus.transform_to_float(buffer, 0);
        std::cout << "Float value from registers 0-1: " << value << std::endl;
        
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

### Common Serial Devices

- **Linux:** `/dev/ttyUSB0`, `/dev/ttyS0`, `/dev/ttyAMA0`
- **macOS:** `/dev/tty.usbserial-*`, `/dev/cu.usbserial-*`
- **Windows:** `COM1`, `COM2`, etc.

### Parity Options

- `'N'` - No parity
- `'E'` - Even parity
- `'O'` - Odd parity

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
