//
// Created by nic on 25/10/22.
//

#pragma once

#ifndef LIBOSMIO_INTERFACE_H
#define LIBOSMIO_INTERFACE_H

#include <bits/stdc++.h>
#include "Device.h"
#include "Protocol.h"


template<class Protocol>
class DeviceBase;

struct InterfaceFoundation {
    bool sendBytes(const char* data, size_t size) { return false; }
};

template<IsProtocol Protocol>
class InterfaceBase : public InterfaceFoundation {
  private:
    DeviceBase<Protocol>* attachedDevice = nullptr;

  public:
    bool attachDevice(DeviceBase<Protocol>* device) {
        if (attachedDevice)
            return true;

        attachedDevice = device;
    }

    bool freeDevice(DeviceBase<Protocol>* device) {
        if (attachedDevice != device)
            return false;

        attachedDevice = 0;
    }
};

template<IsMultiDevice Protocol>
class InterfaceBase<Protocol> : public InterfaceFoundation {
  private:
    std::vector<DeviceBase<Protocol>*> attachedDevices;

  public:
    bool attachDevice(DeviceBase<Protocol>* device) {
        attachedDevices.push_back(device);
        return false;
    }

    bool freeDevice(DeviceBase<Protocol>* device) {
        std::remove_if(attachedDevices.begin(), attachedDevices.end(),
                       [=](DeviceBase<Protocol>* v){ return device == v; });
        return false;
    }
};

template<class Protocol>
class Interface : public InterfaceBase<Protocol> {};

#endif //LIBOSMIO_INTERFACE_H
