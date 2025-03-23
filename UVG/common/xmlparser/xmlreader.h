#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "../structs.h"
#include "../../drivers/driverlist.h"
#include "../logger/uvglog.h"

void setDevType(char* type, devtype* device);
char* getDevDesc(devtype type);
void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur, devices* devlist);
void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur, variables* varlist);
void readFullConfig(devices* devlist, variables* varlist, char* docPath);