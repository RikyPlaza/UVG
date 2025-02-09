#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "../structs.h"

devtype getDevType(char* type);
void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur, devices* devlist);
void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur, variables* varlist);
void readFullConfig(devices* devlist, variables* varlist);