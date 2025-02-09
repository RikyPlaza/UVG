#include "xmlparser/xmlreader.h"

const char* confpath(void);
void initStructs(devices* devlist, variables* varlist);
void populateStructs(devices* devlist, variables* varlist);
void printVars(variables* varlist);
void printDevs(devices* devlist,);
void printConfig(devices* devlist, variables* varlist);