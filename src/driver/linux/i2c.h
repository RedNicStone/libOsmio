//
// Created by nic on 21/11/22.
//

#pragma once

#ifndef LIBOSMIO_I2C_H
#define LIBOSMIO_I2C_H

#ifdef linux

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <csignal>
#include <unordered_map>


namespace {
  std::unordered_map<int, std::pair<void (*)(void* user_data), void*>> callback_lookup{};
  bool callback_registered = false;
}

void i2c_global_callback(int busID) {
    if (auto callback = callback_lookup.find(busID); callback != callback_lookup.end())
        callback->second.first(callback->second.second);
}

int configure_i2c() {
    if (callback_registered)
        return 0;

    struct sigaction saio{};
    saio.sa_handler = &i2c_global_callback;
    saio.sa_flags = 0;
    saio.sa_restorer = nullptr;
    int res = sigaction(SIGIO, &saio, nullptr);

    if (res == 0)
        callback_registered = true;
    return res;
}

int open_i2c_bus(const char* bus) {
    int fd = open(bus, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd >= 0) {
        fcntl(fd, F_SETFL, FNDELAY);
        fcntl(fd, F_SETOWN, getpid());
        fcntl(fd, F_SETFL, O_ASYNC);
        tcflush(fd, TCIFLUSH);
    }

    return fd;
}

int close_i2c_bus(int busID) {
    return close(busID);
}

termios get_i2c_bus_attr(int busID) {
    termios attributes{};
    tcgetattr(busID, &attributes);
    return attributes;
}

int set_i2c_bus_attr(int busID, const termios* attributes) {
    int res = tcsetattr(busID, TCSANOW, attributes);
    tcflush(busID, TCIFLUSH);
    return res;
}

int register_i2c_bus_callback(int busID, void (*callback)(void* user_data), void* user_data = nullptr) {
    callback_lookup.insert_or_assign(busID, std::pair(callback, user_data));
}

int deregister_i2c_bus_callback(int busID) {
    callback_lookup.erase(busID);
}

#endif //linux

#endif //LIBOSMIO_I2C_H
