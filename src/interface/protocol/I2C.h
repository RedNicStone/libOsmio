//
// Created by nic on 26/10/22.
//

#pragma once

#ifndef LIBOSMIO_I2C_H
#define LIBOSMIO_I2C_H

#include "../Protocol.h"
#include "../Device.h"
#include "../Protocol.h"


class ProtocolI2C : ProtocolMultiDeviceMaster, ProtocolSynchronous, ProtocolHalfDuplex {};

template<class Protocol>
concept IsI2C = std::is_base_of_v<ProtocolI2C, Protocol>;


template<IsI2C Protocol>
class Device<Protocol> : public DeviceBase<Protocol> {
  private:
    unsigned char address{};

    bool internalSendBytes(const char *data, size_t data_length);

  public:
    explicit Device(Interface<Protocol>& interface, unsigned char address) :
        DeviceBase<Protocol>(interface), address(address) { }
};

template<IsI2C Protocol>
bool Device<Protocol>::internalSendBytes(const char *data, size_t data_length) {
    return DeviceBase<Protocol>::interface->sendBytes(data, data_length, address);
}

#endif //LIBOSMIO_I2C_H
