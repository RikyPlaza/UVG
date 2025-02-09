#include <stdint.h>

#include "structs.h"

#define CONFIG_PATH_MAX_LENGHT 512
#define VAR_NUMBER_MAX 2048
#define DEV_NUMBER_MAX 30

const char* confpath(void);
void initStructs(devices* devlist, variables* varlist);
void populateStructs(devices* devlist, variables* varlist);
devtype getDevType(char* type);