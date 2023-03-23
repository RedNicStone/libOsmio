//
// Created by nic on 23/03/23.
//

#ifndef LIBOSMIO_FUNCTIONS_H
#define LIBOSMIO_FUNCTIONS_H

#include "structures.h"


// -------------------- //
// Function Definitions //
// -------------------- //

// OsInstance
OS_DECLARE_FUNCTION(void, osCreateInstance,
                    OsInstance* pInstance)
OS_DECLARE_FUNCTION(void, osDestroyInstance,
                    OsInstance pInstance)

// OsProtocol
OS_DECLARE_FUNCTION(void, osEnumerateProtocols,
                    OsInstance instance, uint32_t* protocolCount, OsProtocol** pProtocols)
OS_DECLARE_FUNCTION(void, osGetProtocolInfo,
                    OsProtocol protocol, OsProtocolInfo* pProtocolInfo)

// OsPhysicalInterface
OS_DECLARE_FUNCTION(void, osEnumeratePhysicalInterfaces,
                    OsProtocol protocol, uint32_t* physicalInterfaceCount, OsPhysicalInterface** pPhysicalInterfaces)
OS_DECLARE_FUNCTION(void, osGetPhysicalDeviceInfo,
                    OsPhysicalInterface physicalInterface, OsPhysicalInterfaceInfo* pPhysicalInterfaceInfo)

// OsInterface
OS_DECLARE_FUNCTION(OsResult, osCreateInterface,
    OsInterfaceCreateInfo physicalInterface, OsInterface* pInterface)
OS_DECLARE_FUNCTION(void, osDestroyInterface,
                    OsInterface interface)

// OsDevice
OS_DECLARE_FUNCTION(OsResult, osCreateDevice,
    OsDeviceCreateInfo* pCreateInfo, OsDevice* pDevice)
OS_DECLARE_FUNCTION(void, osDestroyDevice,
                    OsDevice device)

// OsBuffer
OS_DECLARE_FUNCTION(OsResult, osAllocateBuffer,
    OsDeviceCreateInfo* pCreateInfo, OsDevice* pDevice)
OS_DECLARE_FUNCTION(void, osFreeBuffer,
                    OsBuffer buffer)

// OsCallback
OS_DECLARE_FUNCTION(void, osEnumerateProtocolCallbacks,
                    OsProtocol protocol, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION(void, osEnumerateInterfaceCallbacks,
                    OsInterface interface, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION(void, osEnumerateDeviceCallbacks,
                    OsDevice device, uint32_t* callbackCount, OsCallback** pCallbacks)
OS_DECLARE_FUNCTION(void, osGetCallbackInfo,
                    OsCallback callback, OsCallbackInfo* pCallbackInfo)
OS_DECLARE_FUNCTION(OsResult, osRegisterCallback,
    OsCallback callback, OsCallbackRegistryInfo callbackRegistryInfo)
OS_DECLARE_FUNCTION(void, osRemoveCallback,
                    OsCallback callback, void (*pFunction) (void* userData))
OS_DECLARE_FUNCTION(void, osRemoveAllCallbacks,
                    OsCallback callback)

// OsTransaction
OS_DECLARE_FUNCTION(void, osBeginTransaction,
                    OsTransactionInfo transactionInfo, OsTransaction* transaction);
OS_DECLARE_FUNCTION(void, osWaitForTransaction,
                    OsTransaction transaction)

#endif //LIBOSMIO_FUNCTIONS_H
