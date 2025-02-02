#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur);
void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur);
void readFullConfig();