#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "../structs.h"
#include "../strings/uvgstrings.h"
#include "../../drivers/driverlist.h"

devtype getDevType(char* type);
char* getDevDesc(devtype type);
void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur, devices* devlist);
void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur, variables* varlist);
void readFullConfig(devices* devlist, variables* varlist, char* docPath);