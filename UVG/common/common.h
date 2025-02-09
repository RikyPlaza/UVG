#include <stdint.h>

#include "structs.h"

const char* confpath(void);
void initStructs(devices* devlist, variables* varlist);
void populateStructs(devices* devlist, variables* varlist);
devtype getDevType(char* type);