#include "modbusRtu.hpp"
//@params  will be passed to modbus_t opaque structure that will contain the information needed to setup a rtu connection
modbusRtu::modbusRtu(const char* device, int baud,char parity,int data_bit,int stop_bit){
    ctx_ = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    if(ctx_ == nullptr){
        throw std::runtime_error("failed to create modbus rtu context");
    }
}
modbusRtu::~modbusRtu(){
}
bool modbusRtu::connect(){
    return false;
}



