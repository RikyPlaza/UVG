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
    for(int i = 0; i < DEV_NUMBER_MAX; i++)
    {
        devlist->dev[i].name = strdup("");
        devlist->dev[i].port = strdup("");
        devlist->dev[i].type = NONE;
    }
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

void printVars(variables* varlist)
{
    for(int i = 0; i < VAR_NUMBER_MAX; i++)
    {
        printf("Source device: %s - Source address: %s - Destination device: %s - Destination address: %s\n", varlist->var[i].sourceDev, varlist->var[i].sourceAddress, 
                varlist->var[i].destinationDev, varlist->var[i].destinationAddress);
    }
}

void printDevs(devices* devlist)
{
    for(int i = 0; i < DEV_NUMBER_MAX; i++)
    {
        printf("Device name: %s - Device type: %s - Device port: %s\n", devlist->dev[i].name, getDevDesc(devlist->dev[i].type), devlist->dev[i].port);
    }
}

void printConfig(devices* devlist, variables* varlist)
{
    printVars(varlist);
    printDevs(devlist);
}