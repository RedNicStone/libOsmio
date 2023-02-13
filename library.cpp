#include "library.h"

#include <iostream>
#include "src/interface/protocol/I2C.h"


void hello() {
    Interface<ProtocolI2C> interface{};
    Device<ProtocolI2C> protocol(interface, 0x0);
    DeviceWrapper wrapper(protocol);
    std::cout << "Hello, World!" << std::endl;
}
