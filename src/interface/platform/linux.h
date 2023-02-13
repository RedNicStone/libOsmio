//
// Created by nic on 21/11/22.
//

#pragma once

#ifndef LIBOSMIO_LINUX_H
#define LIBOSMIO_LINUX_H

#include "../protocol/I2C.h"

#ifdef linux

template<IsI2C Protocol>
class Interface<Protocol> : public InterfaceBase<Protocol> {
  private:
    int fileDevice;

  public:
    explicit Interface(const char* device);

    bool sendBytes(const char *data, size_t data_length, unsigned char address);
};

template<IsI2C Protocol>
Interface<Protocol>::Interface(const char *device) {
    fileDevice = open
}

#endif // linux

#endif //LIBOSMIO_LINUX_H
