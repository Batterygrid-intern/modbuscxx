#include <modbus/modbus.h>
#include <stdexcept>
#include <iostream>

class modbusRtu {
    public:
        //parameter to create  set parameters to ctx(context structure object)
        modbusRtu(const char *device, int baud, char parity, int data_bit, int stop_bit );
        ~modbusRtu();

        bool connect();

    private:
        modbus_t *ctx_;
};
