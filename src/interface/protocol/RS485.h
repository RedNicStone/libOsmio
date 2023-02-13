//
// Created by nic on 26/10/22.
//

#ifndef LIBOSMIO_RS485_H
#define LIBOSMIO_RS485_H

#include "../Protocol.h"


class ProtocolRS485H : ProtocolMultiDeviceMaster, ProtocolAsynchronous, ProtocolHalfDuplex {};
class ProtocolRS485F : ProtocolMultiDeviceMaster, ProtocolAsynchronous, ProtocolFullDuplex {};

template<class Protocol>
concept IsRS485H =                     std::is_base_of_v<ProtocolRS485H, Protocol>;
template<class Protocol>
concept IsRS485F =                     std::is_base_of_v<ProtocolRS485F, Protocol>;

#endif //LIBOSMIO_RS485_H
