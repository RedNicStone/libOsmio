//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_USB_H
#define LIBOSMIO_USB_H

#include "../Protocol.h"


class ProtocolUSB : ProtocolMultiDevice, ProtocolSynchronous, ProtocolHalfDuplex {};
class ProtocolUSBSS : ProtocolMultiDevice, ProtocolSynchronous, ProtocolFullDuplex {};

template<class Protocol>
concept IsUSB =                     std::is_base_of_v<ProtocolUSB, Protocol>;
template<class Protocol>
concept IsUSBSS =                     std::is_base_of_v<ProtocolUSBSS, Protocol>;

#endif //LIBOSMIO_USB_H
