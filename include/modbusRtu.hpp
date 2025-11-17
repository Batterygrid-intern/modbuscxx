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

        //read values stored store in vector (for floating point numbers data will be stored in 2 following registers) 
        std::vector<uint16_t> read_values(int site_id, int start_r,int num_of_r);
        std::vector<float> transform_to_floats(std::vector<uint16_t> data, int start_index, int last_index);
    private:
        modbus_t *ctx_;
};
