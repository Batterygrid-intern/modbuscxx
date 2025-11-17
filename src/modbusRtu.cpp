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
    //free allocated memory for modbus_t context structure
    modbus_close(ctx_);
    modbus_free(ctx_);
}
// bool eller void? bygga sig flexibel?
bool modbusRtu::connect(){
    if(modbus_connect(ctx_) == -1){
        throw std::runtime_error("failed to connect to modbus slave");
        return false;
    }
    return true;
}

// när ska man allokera heap minne och när stack minne? 
std::vector<uint16_t> modbusRtu::read_values(int site_id, int start_r, int num_of_r ){
    std::vector<uint16_t> values;
    int MAX_SIZE = num_of_r*sizeof(uint16_t);
    uint16_t buffer[MAX_SIZE];
    //set slave id to read from
    if(modbus_set_slave(ctx_,site_id) == -1){
        throw std::runtime_error("invalid slave id");    
    }
    //read registers from until
    if(modbus_read_registers(ctx_,start_r,num_of_r,buffer) == -1){
        throw std::runtime_error("failed to read registers");
    }
    //save all data read in vector 
    for(int i = 0; i < num_of_r ; i) {
        values.push_back(buffer[i]);
    }
    return values;
}




