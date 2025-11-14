#include <modbus/modbus.h>


class modbusRtu {
    public:
        //parameter to create  set parameters to ctx(context structure object)
        modbusRtu(const char *device, int baud, char parity, int data_bit, int stop_bit );
        ~modbusRtu();

        bool modbusRtuConn(modbus_t *ctx);

    private:
        modbus_t *ctx_;
};
