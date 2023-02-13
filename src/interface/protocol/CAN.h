//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_CAN_H
#define LIBOSMIO_CAN_H

#include "../Protocol.h"


class ProtocolCAN : ProtocolMultiMaster, ProtocolSynchronous, ProtocolHalfDuplex {};

template<class Protocol>
concept IsCAN =                     std::is_base_of_v<ProtocolCAN, Protocol>;

#endif //LIBOSMIO_CAN_H
