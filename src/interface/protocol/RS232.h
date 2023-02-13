//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_RS232_H
#define LIBOSMIO_RS232_H

#include "../Protocol.h"


class ProtocolRS232 : ProtocolAsynchronous, ProtocolSimplex {};

template<class Protocol>
concept IsRS232 =                     std::is_base_of_v<ProtocolRS232, Protocol>;

#endif //LIBOSMIO_RS232_H
