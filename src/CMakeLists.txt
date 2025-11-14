add_library(modbusRtu modbusrtu.cpp)

target_include_directories(modbusRtu
	PUBLIC
	    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(modbusRtu
	PUBLIC
	    modbus
) 

