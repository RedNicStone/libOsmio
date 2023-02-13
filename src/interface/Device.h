//
// Created by nic on 22/10/22.
//

#pragma once

#ifndef LIBOSMIO_DEVICE_H
#define LIBOSMIO_DEVICE_H

#include <cstddef>
#include <vector>
#include <cstring>
#include <memory>

#include "Interface.h"


template<class Protocol>
class DeviceBase {
  protected:
    std::vector<char> readBuffer;
    Interface<Protocol>* interface;
    DeviceBase() = default;

  public:
    explicit DeviceBase(Interface<Protocol>& interface) : interface(&interface) { interface.attachDevice(this); }

    bool sendByte(const char data) { return internalSendBytes(&data, 1); }
    bool sendBytes(const char* data) { return internalSendBytes(data, strlen(data)); }
    bool sendBytes(const char* data, size_t data_length) { return internalSendBytes(data, data_length); }

    bool readByte(char* data);
    bool readBytes(char** data);
    bool readBytes(char** data, size_t* data_length);
    bool readBytes(char** data, size_t data_length);

    size_t getReadBufferLength() { return readBuffer.size(); }

    ~DeviceBase() { interface->freeDevice(this); }

    class ExternalReadPrivilege {
        ExternalReadPrivilege() = default;
        friend Interface<Protocol>;
    };

    bool externalReadBytes(ExternalReadPrivilege, const char* data, size_t data_length);

  protected:
    bool internalSendBytes(const char* data, size_t data_length);
};

template<class Protocol>
class Device : public DeviceBase<Protocol> {};

template<class Protocol>
bool DeviceBase<Protocol>::readByte(char *data) {
    if (readBuffer.empty())
        return true;

    *data = readBuffer.back();
    readBuffer.pop_back();
    return false;
}

template<class Protocol>
bool DeviceBase<Protocol>::readBytes(char **data) {
    if (readBuffer.empty())
        return true;

    memcpy(data, readBuffer.data(), readBuffer.size());
    return false;
}

template<class Protocol>
bool DeviceBase<Protocol>::readBytes(char **data, size_t *data_length) {
    if (readBuffer.empty())
        return true;

    *data_length = readBuffer.size();
    memcpy(data, readBuffer.data(), readBuffer.size());
    return false;
}

template<class Protocol>
bool DeviceBase<Protocol>::readBytes(char **data, size_t data_length) {
    if (readBuffer.empty())
        return true;

    size_t size = readBuffer.size();
    memcpy(data, readBuffer.data(), std::max(data_length, size));
    return false;
}

template<class Protocol>
bool DeviceBase<Protocol>::externalReadBytes(DeviceBase::ExternalReadPrivilege, const char *data, size_t data_length) {
    readBuffer.insert(readBuffer.end(), data, data + data_length);
    return false;
}

template<class Protocol>
bool DeviceBase<Protocol>::internalSendBytes(const char *data, size_t data_length) {
    return interface->sendBytes(data, data_length);
}

class DeviceWrapper {
  private:
    struct DeviceFoundation {
        virtual bool sendByte(char data) = 0;
        virtual bool sendBytes(const char* data) = 0;
        virtual bool sendBytes(const char* data, size_t data_length) = 0;

        virtual bool readByte(char* data) = 0;
        virtual bool readBytes(char** data) = 0;
        virtual bool readBytes(char** data, size_t* data_length) = 0;
        virtual bool readBytes(char** data, size_t data_length) = 0;

        virtual size_t getReadBufferLength() = 0;

        virtual ~DeviceFoundation() = default;
    };

    template<IsProtocol Protocol>
    class DeviceBlanket : public DeviceFoundation {
      public:
        explicit DeviceBlanket(const Device<Protocol>& device) :  wrappedHandle(device) { }

        inline bool sendByte(const char data) override { return wrappedHandle.sendByte(data); }
        inline bool sendBytes(const char* data) override { return wrappedHandle.sendBytes(data); }
        inline bool sendBytes(const char* data, size_t data_length) override {
            return wrappedHandle.sendBytes(data, data_length); }

        inline bool readByte(char* data) override { return wrappedHandle.readByte(data); }
        inline bool readBytes(char** data) override { return wrappedHandle.readBytes(data); }
        inline bool readBytes(char** data, size_t* data_length) override {
            return wrappedHandle.readBytes(data, data_length); }
        inline bool readBytes(char** data, size_t data_length) override {
            return wrappedHandle.readBytes(data, data_length); }

        inline size_t getReadBufferLength() override { return wrappedHandle.getReadBufferLength(); }

      private:
        Device<Protocol> wrappedHandle;
    };

    std::shared_ptr<DeviceFoundation> wrappedObject;

  public:
    template <IsProtocol Protocol>
    explicit DeviceWrapper(Device<Protocol>& device) :
        wrappedObject(std::make_shared<DeviceBlanket<Protocol>>(device)) { }

    template <IsProtocol Protocol>
    explicit DeviceWrapper(Device<Protocol>&& device) :
        wrappedObject(std::make_shared<DeviceBlanket<Protocol>>(std::forward<DeviceBlanket<Protocol>>(device))) { }

    inline bool sendByte(const char data) { return wrappedObject->sendByte(data); }
    inline bool sendBytes(const char* data) { return wrappedObject->sendBytes(data); }
    inline bool sendBytes(const char* data, size_t data_length) {
        return wrappedObject->sendBytes(data, data_length); }

    inline bool readByte(char* data) { return wrappedObject->readByte(data); }
    inline bool readBytes(char** data) { return wrappedObject->readBytes(data); }
    inline bool readBytes(char** data, size_t* data_length) {
        return wrappedObject->readBytes(data, data_length); }
    inline bool readBytes(char** data, size_t data_length) {
        return wrappedObject->readBytes(data, data_length); }

    inline size_t getReadBufferLength() { return wrappedObject->getReadBufferLength(); }
};

#endif //LIBOSMIO_DEVICE_H
