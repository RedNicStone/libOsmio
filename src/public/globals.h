//
// Created by nic on 23/03/23.
//

#ifndef LIBOSMIO_GLOBALS_H
#define LIBOSMIO_GLOBALS_H

#include <cstring>
#include <cstdlib>


// -------------- //
// Function Table //
// -------------- //


#include "functions.h"

#undef OS_DECLARE_FUNCTION
#define OS_DECLARE_FUNCTION(type, functionName, ...) \
    CONCATENATE(OS_FUNCTION_PTR_PREFIX, functionName) functionName;

struct OsFunctionTable {
#undef LIBOSMIO_FUNCTIONS_H
#include "functions.h"
};

struct OsICD {
    char* name;
    void (*functionRegister)();
    void (*functionDeregister)();
    OsFunctionTable functionTable;
};

OsICD** osRegisteredICDs;
uint32_t osICDCount = 0;
uint32_t osICDLimit = 0;

void osRegisterICD(OsICD* icd) {
    if (icd == nullptr)
        return;

    if (osICDCount >= osICDLimit) {
        osICDLimit *= 2;
        OsICD** currentICDs = osRegisteredICDs;
        osRegisteredICDs = (OsICD**) malloc(osICDLimit * sizeof(OsICD**));

        memcpy(osRegisteredICDs, currentICDs, osICDCount * sizeof(OsICD**));
        free(currentICDs);
    }

    osRegisteredICDs[osICDCount + 1] = icd;
}

#endif //LIBOSMIO_GLOBALS_H
