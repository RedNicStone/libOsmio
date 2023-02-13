//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_SPI_H
#define LIBOSMIO_SPI_H

#include "../Protocol.h"


class ProtocolSPI : ProtocolMultiDevice, ProtocolSynchronous, ProtocolFullDuplex {};
class ProtocolQSPI : ProtocolMultiDevice, ProtocolSynchronous, ProtocolFullDuplex {};
class ProtocolUWire : ProtocolMultiDevice, ProtocolSynchronous, ProtocolHalfDuplex {};
class ProtocolUWireP : ProtocolMultiDevice, ProtocolSynchronous, ProtocolFullDuplex {};

template<class Protocol>
concept IsSPI =                     std::is_base_of_v<ProtocolSPI, Protocol>;
template<class Protocol>
concept IsQSPI =                    std::is_base_of_v<ProtocolSPI, Protocol>;
template<class Protocol>
concept IsUWire =                   std::is_base_of_v<ProtocolSPI, Protocol>;
template<class Protocol>
concept IsUWireP =                  std::is_base_of_v<ProtocolSPI, Protocol>;

#endif //LIBOSMIO_SPI_H
