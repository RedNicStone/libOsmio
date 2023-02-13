//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_RS422_H
#define LIBOSMIO_RS422_H

#include "../Protocol.h"


class ProtocolRS422 : ProtocolMultiDevice, ProtocolAsynchronous, ProtocolFullDuplex {};

template<class Protocol>
concept IsRS422 =                     std::is_base_of_v<ProtocolRS422, Protocol>;

#endif //LIBOSMIO_RS422_H
