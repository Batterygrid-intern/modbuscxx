#pragma once
#include <modbus/modbus.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <cerrno>
class modbusRtu {
    public:
        //parameter to create  set parameters to ctx(context structure object)
        modbusRtu(const char *device, int baud, char parity, int data_bit, int stop_bit);
        ~modbusRtu();

        bool connect();

        //read values stored store in vector (for floating point numbers data will be stored in 2 following registers) 
        void read_values(int site_id, int start_r,int num_of_r,uint16_t *buffer);
        float transform_to_float(const uint16_t *readings_buf, int position);
    private:
        modbus_t *ctx_;
};
