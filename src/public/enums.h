//
// Created by nic on 23/03/23.
//

#ifndef LIBOSMIO_ENUMS_H
#define LIBOSMIO_ENUMS_H


// ------------ //
// Enumerations //
// ------------ //


typedef enum OsStructureType {

} OsStructureType;

typedef enum OsResult {
    OS_RESULT_SUCCESS = 0,
    OS_RESULT_GENERIC_ERROR = 1,
    OS_RESULT_INTERNAL_ERROR = 2,
} OsResult;

typedef enum OsBufferUsage {
    OS_BUFFER_USAGE_NATIVE = 0b01,
    OS_BUFFER_USAGE_DMA = 0b10,
} OsBufferUsage;

typedef enum OsBufferType {
    OS_BUFFER_TYPE_SINGLE = 0,
    OS_BUFFER_TYPE_DOUBLE = 1,
    OS_BUFFER_TYPE_TRIPLE = 2,
    OS_BUFFER_TYPE_CIRCULAR = 3,
} OsBufferType;

typedef enum OsBufferBehaviour {
    OS_BUFFER_BEHAVIOUR_STATIC = 0,
    OS_BUFFER_BEHAVIOUR_GROWING = 0,
} OsBufferBehaviour;

typedef enum OsAddressFormat {
    OS_ADDRESS_FORMAT_NONE = 0,
    OS_ADDRESS_FORMAT_FIXED_LENGTH = 1,
    OS_ADDRESS_FORMAT_NULL_TERMINATED = 2,
    OS_ADDRESS_FORMAT_SIZE_PREFIX = 3,
} OsAddressFormat;

#endif //LIBOSMIO_ENUMS_H
