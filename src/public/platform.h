//
// Created by nic on 09/03/23.
//

#ifndef LIBOSMIO_PLATFORM_H
#define LIBOSMIO_PLATFORM_H

#define OS_DEFINE_HANDLE(object) typedef struct object##_T* object;

#define CONCATENATE_HELPER(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_HELPER(x, y)

#define OS_FUNCTION_PTR *
#define OS_FUNCTION_PTR_PREFIX PFN_
#define OS_FUNCTION_PTR_ADD_PREFIX(name) CONCATENATE(OS_FUNCTION_PTR_PREFIX, name)

#define OS_DECLARE_FUNCTION(returnType, name, ...)                                      \
    typedef returnType (OS_FUNCTION_PTR OS_FUNCTION_PTR_ADD_PREFIX(name))(__VA_ARGS__); \
    returnType name(__VA_ARGS__);


#include <cstdint>

#endif //LIBOSMIO_PLATFORM_H
