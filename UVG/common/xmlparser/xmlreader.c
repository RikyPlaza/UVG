#include "xmlreader.h"

void setDevType(char* type, devtype* device)
{
    uvgdebuglog(__LINE__, __FUNCTION__, "Device type %s", type);
    type = strtolower(type);
    uvgdebuglog(__LINE__, __FUNCTION__, "Device type to lower %s", type);
    if(strcmp(type, SIEMENS_CLIENT_DESC) == 0)
    {
        uvgdebuglog(__LINE__, __FUNCTION__, "Detected siemens device");
        *device = SIEMENS_CLIENT;
    } 
    else if (strcmp(type, OMRON_CLIENT_DESC) == 0)
    {
        uvgdebuglog(__LINE__, __FUNCTION__, "Detected omron device");
        *device = OMRON_CLIENT;        
    } 
    else if (strcmp(type, OPCUA_CLIENT_DESC) == 0)
    {
        uvgdebuglog(__LINE__, __FUNCTION__, "Detected opcua client device");
        *device = OPCUA_CLIENT;
    } 
    else
    {
        /*Exit the application with error*/
    }
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
    bool devicesParsed = false;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
        uvgdebuglog(__LINE__, __FUNCTION__, "xml node name: %s\n", (char*)cur->name);

	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"devices"))) 
        {
            uvgdebuglog(__LINE__, __FUNCTION__, "Inside devices");
            cur = cur->xmlChildrenNode;
            uvgdebuglog(__LINE__, __FUNCTION__, "xml node name: %s\n", (char*)cur->name);
            
            while (cur != NULL) 
            {
                uvgdebuglog(__LINE__, __FUNCTION__, "xml node name: %s\n", (char*)cur->name);

                if ((!xmlStrcmp(cur->name, (const xmlChar *)"device"))) 
                {
                    uvgdebuglog(__LINE__, __FUNCTION__, "Device detected");
                    uvgdebuglog(__LINE__, __FUNCTION__, "Device name %s", (char*) xmlGetProp(cur, "name"));
                    setDevType((char*) xmlGetProp(cur, "type"), &(devlist->dev[devlist->devNumber].type));
                    uvgdebuglog(__LINE__, __FUNCTION__, "Device type %s", getDevDesc(devlist->dev[devlist->devNumber].type));
                    uvgdebuglog(__LINE__, __FUNCTION__, "Device port %s", (char*) xmlGetProp(cur, "port"));
                    uvgdebuglog( __LINE__, __FUNCTION__, "Device name: %s - Device type: %s - Device port: %s\n", (char*) xmlGetProp(cur, "name"), getDevDesc(devlist->dev[devlist->devNumber].type), (char*) xmlGetProp(cur, "port"));
                    
                    devlist->dev[devlist->devNumber].name = (char*) xmlGetProp(cur, "name");
                    devlist->dev[devlist->devNumber].port = (char*) xmlGetProp(cur, "port");
                    setDevType((char*) xmlGetProp(cur, "type"), &(devlist->dev[devlist->devNumber].type));

                    devlist->devNumber += 1;
                }
                cur = cur->next;
            }
            
            devicesParsed = true;
            uvgdebuglog(__LINE__, __FUNCTION__, "Leaving devices");
		}
        if(devicesParsed)
            break;
	}
    return;
}

void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur, variables* varlist) 
{
	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
        uvgdebuglog( __LINE__, __FUNCTION__, "xml node name: %s\n", (char*)cur->name);

	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"variable"))) 
        {
            varlist->var[varlist->varNumber].sourceDev = (char*) xmlGetProp(cur, "source");
            varlist->var[varlist->varNumber].sourceAddress = (char*) xmlGetProp(cur, "sourceaddress");
            varlist->var[varlist->varNumber].destinationDev = (char*) xmlGetProp(cur, "destination");
            varlist->var[varlist->varNumber].destinationAddress = (char*) xmlGetProp(cur, "destinationaddress");

            varlist->varNumber += 1;

            uvgdebuglog(__LINE__, __FUNCTION__, "Source device: %s - Source address: %s - Destination device: %s - Destination address: %s\n", 
                (char*) xmlGetProp(cur, "source"), (char*) xmlGetProp(cur, "sourceaddress"), (char*) xmlGetProp(cur, "destination"), (char*) xmlGetProp(cur, "destinationaddress"));
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
    uvgdebuglog(__LINE__, __FUNCTION__, "Devices parsed");
    getVariablesFromConfig(config, cur, varlist);

	xmlFreeDoc(config);
	return;
}