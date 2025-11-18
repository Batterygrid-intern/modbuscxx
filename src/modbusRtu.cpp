#include "modbusRtu.hpp"
//@params  will be passed to modbus_t opaque structure that will contain the information needed to setup a rtu connection
//@throw runtime_error if modbus_new_rtu fails
modbusRtu::modbusRtu(const char* device, int baud,char parity,int data_bit,int stop_bit){
    //setup your parameters to the modbus_t struct
    ctx_ = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    if(ctx_ == nullptr){
        std::string error_msg = std::string("failed to set modbus parameters: ") + modbus_strerror(errno);
        std::cerr << error_msg << std::endl;
        throw std::runtime_error(error_msg);
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
        std::string error_msg = std::string("failed to connect to modbus slave: ") + modbus_strerror(errno);
        std::cerr << error_msg << std::endl;
        throw std::runtime_error(error_msg);
        return false;
    }
    return true;
}
// när ska man allokera heap minne och när stack minne? 
void modbusRtu::read_values(int site_id, int start_r, int num_of_r,uint16_t *buffer ){
    if(modbus_set_slave(ctx_,site_id) == -1){
        std::string error_msg = std::string("failed to set slave_id: ") + modbus_strerror(errno);
        std::cerr << error_msg << std::endl;
        throw std::runtime_error(error_msg);    
    } 
    //read registers from until (is this code 0x03?)
    if(modbus_read_registers(ctx_,start_r,num_of_r,buffer) == -1){
        std::string error_msg = std::string("failed to read registers: ") + modbus_strerror(errno);
        std::cerr << error_msg << std::endl;
        throw std::runtime_error(error_msg);
    }
    //save all data read in vector 
}
//transform data to floats
std::vector<float> modbusRtu::transform_to_floats(const uint16_t *readings_buf, int start_index, int last_index){
    std::vector<float> value;
    for(int i = start_index; i <=last_index;i+=2){
       value.push_back(modbus_get_float_abcd(&readings_buf[i]));
    }
    return value;
}








