#include "modbusRtu.hpp"
//@params  will be passed to modbus_t opaque structure that will contain the information needed to setup a rtu connection
//@throw runtime_error if modbus_new_rtu fails
modbusRtu::modbusRtu(const char* device, int baud,char parity,int data_bit,int stop_bit){
    //setup your parameters to the modbus_t struct
    ctx_ = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    if(ctx_ == nullptr){
        throw std::runtime_error("failed to create modbus rtu context");
    }
}

modbusRtu::~modbusRtu(){
}
//connect to modbus slave over rtu
bool modbusRtu::connect(){
    return false;
}


