#include <stdlib.h>
#include <string.h>
#include "common.h"

void initStructs(devices* devlist, variables* varlist)
{
    devlist->devNumber = 0;
    varlist->varNumber = 0;
    for(int i = 0; i < VAR_NUMBER_MAX; i++)
    {
        varlist->var[i].sourceDev = strdup("");
        varlist->var[i].sourceAddress = strdup("");
        varlist->var[i].destinationDev = strdup("");
        varlist->var[i].destinationAddress = strdup("");
    }    
}

void populateStructs(devices* devlist, variables* varlist)
{
    readFullConfig(devlist, varlist);
}