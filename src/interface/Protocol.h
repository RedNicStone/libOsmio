//
// Created by nic on 25/10/22.
//

#pragma once

#ifndef LIBOSMIO_PROTOCOL_H
#define LIBOSMIO_PROTOCOL_H

#include <type_traits>


class ProtocolType {};
class ProtocolAddressable : ProtocolType {};
class ProtocolMultiDevice : ProtocolAddressable {};
class ProtocolMultiMaster : ProtocolAddressable {};
class ProtocolMultiDeviceMaster : ProtocolMultiDevice, ProtocolMultiMaster {};
class ProtocolSerial : ProtocolType {};
class ProtocolParallel : ProtocolType {};
class ProtocolSynchronous : ProtocolType {};
class ProtocolAsynchronous : ProtocolType {};
class ProtocolSimplex : ProtocolType {};
class ProtocolHalfDuplex : ProtocolType {};
class ProtocolFullDuplex : ProtocolType {};

template<class Protocol>
concept IsProtocol =                                           std::is_base_of_v<ProtocolType, Protocol>;
template<class Protocol>
concept IsAddressable =             IsProtocol<Protocol>    && std::is_base_of_v<ProtocolAddressable, Protocol>;
template<class Protocol>
concept IsMultiDevice =             IsAddressable<Protocol> && std::is_base_of_v<ProtocolMultiDevice, Protocol>;
template<class Protocol>
concept IsMultiMaster =             IsAddressable<Protocol> && std::is_base_of_v<ProtocolMultiMaster, Protocol>;
template<class Protocol>
concept IsMultiDeviceMaster =       IsMultiMaster<Protocol> && IsMultiDevice<Protocol>
                                                            && std::is_base_of_v<ProtocolMultiDeviceMaster, Protocol>;
template<class Protocol>
concept IsSerial =                  IsProtocol<Protocol>    && std::is_base_of_v<ProtocolSerial, Protocol>;
template<class Protocol>
concept IsParallel =                IsProtocol<Protocol>    && std::is_base_of_v<ProtocolParallel, Protocol>;
template<class Protocol>
concept IsSynchronous =             IsProtocol<Protocol>    && std::is_base_of_v<ProtocolSynchronous, Protocol>;
template<class Protocol>
concept IsAsynchronous =            IsProtocol<Protocol>    && std::is_base_of_v<ProtocolAsynchronous, Protocol>;
template<class Protocol>
concept IsSimplex =                 IsProtocol<Protocol>    && std::is_base_of_v<ProtocolSimplex, Protocol>;
template<class Protocol>
concept IsHalfDuplex =              IsProtocol<Protocol>    && std::is_base_of_v<ProtocolHalfDuplex, Protocol>;
template<class Protocol>
concept IsFullDuplex =              IsProtocol<Protocol>    && std::is_base_of_v<ProtocolFullDuplex, Protocol>;

template<class Protocol>
concept IsNotProtocol =             !IsProtocol<Protocol>;
template<class Protocol>
concept IsNotAddressable =          !IsAddressable<Protocol>;
template<class Protocol>
concept IsNotMultiDevice =          !IsMultiDevice<Protocol>;
template<class Protocol>
concept IsNotMultiMaster =          !IsMultiMaster<Protocol>;
template<class Protocol>
concept IsNotMultiDeviceMaster =    !IsMultiDeviceMaster<Protocol>;
template<class Protocol>
concept IsNotSerial =               !IsSerial<Protocol>;
template<class Protocol>
concept IsNotParallel =             !IsParallel<Protocol>;
template<class Protocol>
concept IsNotSynchronous =          !IsSynchronous<Protocol>;
template<class Protocol>
concept IsNotAsynchronous =         !IsAsynchronous<Protocol>;
template<class Protocol>
concept IsNotSimplex =              !IsSimplex<Protocol>;
template<class Protocol>
concept IsNotHalfDuplex =           !IsHalfDuplex<Protocol>;
template<class Protocol>
concept IsNotFullDuplex =           !IsFullDuplex<Protocol>;

#endif //LIBOSMIO_PROTOCOL_H
