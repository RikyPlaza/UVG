#include "xmlreader.h"
#include "../logger/uvglog.h"

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
        device = OPCUA_CLIENT;
    } 
    else
    {
        /*Exit the application with error*/
    }
    
    return device;
}

char* getDevDesc(devtype type)
{
    const char *desc = NULL;

    switch(type)
    {
        case SIEMENS_CLIENT:
            desc = SIEMENS_CLIENT_DESC;
            break;
        case OMRON_CLIENT:
            desc = OMRON_CLIENT_DESC;
            break;
        case OPCUA_CLIENT:
            desc = OPCUA_CLIENT_DESC;
            break;
    }

    return desc;
}

void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur, devices* devlist) 
{
	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
        uvgdebuglog(uvgsprintf("xml node name: %s\n", (char*)cur->name), __LINE__, __FUNCTION__);

	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"devices"))) 
        {
            cur = cur->xmlChildrenNode;

            while (cur != NULL) 
            {
                uvgdebuglog(uvgsprintf("xml node name: %s\n", (char*)cur->name), __LINE__, __FUNCTION__);

                if ((!xmlStrcmp(cur->name, (const xmlChar *)"device"))) 
                {
                    uvgdebuglog(uvgsprintf("Device name: %s - Device type: %s - Device port: %s\n", (char*) xmlGetProp(cur, "name"), getDevType((char*) xmlGetProp(cur, "type")), (char*) xmlGetProp(cur, "port")), __LINE__, __FUNCTION__);
                    
                    devlist->dev[devlist->devNumber].name = (char*) xmlGetProp(cur, "name");
                    devlist->dev[devlist->devNumber].port = (char*) xmlGetProp(cur, "port");
                    devlist->dev[devlist->devNumber].type = getDevType((char*) xmlGetProp(cur, "type"));

                    devlist->devNumber += 1;
                }
                cur = cur->next;
            }
		}
	    cur = cur->next;
	}
    return;
}

void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur, variables* varlist) 
{
	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
        uvgdebuglog(uvgsprintf("xml node name: %s\n", (char*)cur->name), __LINE__, __FUNCTION__);

	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"variable"))) 
        {
            varlist->var[varlist->varNumber].sourceDev = (char*) xmlGetProp(cur, "source");
            varlist->var[varlist->varNumber].sourceAddress = (char*) xmlGetProp(cur, "sourceaddress");
            varlist->var[varlist->varNumber].destinationDev = (char*) xmlGetProp(cur, "destination");
            varlist->var[varlist->varNumber].destinationAddress = (char*) xmlGetProp(cur, "destinationaddress");

            varlist->varNumber += 1;

            uvgdebuglog(uvgsprintf("Source device: %s - Source address: %s - Destination device: %s - Destination address: %s\n", (char*) xmlGetProp(cur, "source"), (char*) xmlGetProp(cur, "sourceaddress"), 
                (char*) xmlGetProp(cur, "destination"), (char*) xmlGetProp(cur, "destinationaddress")), __LINE__, __FUNCTION__);
		}
	    cur = cur->next;
	}
    return;
}

void readFullConfig(devices* devlist, variables* varlist, char* docPath)
{
	xmlDocPtr config;
	xmlNodePtr cur;
    
	config = xmlParseFile(docPath);
	
	if (config == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	
	cur = xmlDocGetRootElement(config);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(config);
        /*Exit the application with error*/
		return;
	}

    getDevicesFromConfig(config, cur, devlist);
    getVariablesFromConfig(config, cur, varlist);

	xmlFreeDoc(config);
	return;
}