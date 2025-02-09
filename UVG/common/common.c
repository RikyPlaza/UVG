#include <stdlib.h>

#include "common.h"
#include "strings/uvgstrings.h"
#include "../drivers/driverlist.h"

const char* confpath(void)
{
	static const char *path = NULL;
	if (path)
		return path;

	path = getenv("UVG_CONFIGPATH");

	if (path == NULL) 
    {
		/*Exit the application with error*/
	}

	return path;
}

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

devtype getDevType(char* type)
{
    devtype device;
    type = strtolower(type);

    if(type == SIEMENS_CLIENT_DESC)
    {
        device = SIEMENS_CLIENT;
    } 
    else if (type == OMRON_CLIENT_DESC)
    {
        device = OMRON_CLIENT;        
    } 
    else if (type == OPCUA_CLIENT_DESC)
    {
        device = OMRON_CLIENT;
    } 
    else
    {
        /*Exit the application with error*/
    }
    
    return device;
}