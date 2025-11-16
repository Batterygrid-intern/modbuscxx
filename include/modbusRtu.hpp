#include <modbus/modbus.h>
#include <stdexcept>
#include <iostream>
#include <vector>
class modbusRtu {
    public:
        //parameter to create  set parameters to ctx(context structure object)
        modbusRtu(const char *device, int baud, char parity, int data_bit, int stop_bit);
        ~modbusRtu();

        bool connect();
        //read floats
        
       std::vector<uint16_t> read_float(int site_id,int register);


    private:
        modbus_t *ctx_;
};
