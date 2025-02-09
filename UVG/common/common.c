#include <stdlib.h>
#include <string.h>
#include "common.h"

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

void populateStructs(devices* devlist, variables* varlist)
{
    char configPath[CONFIG_PATH_MAX_LENGHT];

    snprintf(configPath, sizeof(configPath), "%s/variables.xml", confpath());

    readFullConfig(devlist, varlist, configPath);
}