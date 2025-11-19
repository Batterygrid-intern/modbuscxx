# Find libmodbus
find_package(PkgConfig REQUIRED)
pkg_check_modules(MODBUS REQUIRED libmodbus)

if(NOT MODBUS_FOUND)
    message(FATAL_ERROR "libmodbus not found. Please install libmodbus-dev (Debian/Ubuntu) or libmodbus-devel (Fedora/RHEL)")
endif()

# Create library (static or shared based on BUILD_SHARED_LIBS)
add_library(modbusRtu modbusRtu.cpp)
add_library(modbuscxx::modbusRtu ALIAS modbusRtu)

# Set include directories
target_include_directories(modbusRtu
	PUBLIC
	    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	    $<INSTALL_INTERFACE:include>
	PRIVATE
	    ${MODBUS_INCLUDE_DIRS}
)

# Link dependencies
target_link_libraries(modbusRtu
	PUBLIC
	    ${MODBUS_LIBRARIES}
)

# Set C++ standard
target_compile_features(modbusRtu PUBLIC cxx_std_17) 

