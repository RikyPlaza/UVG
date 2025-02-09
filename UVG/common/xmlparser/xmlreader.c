#include "xmlreader.h"
#include "strings/uvgstrings.h"

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

void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur, devices* devlist) 
{
	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"device"))) 
        {
            devlist->dev[devlist->devNumber].name = (char*) xmlGetProp(cur, "name");
            devlist->dev[devlist->devNumber].port = (char*) xmlGetProp(cur, "port");
            devlist->dev[devlist->devNumber].type = getDevType((char*) xmlGetProp(cur, "type"));

            devlist->devNumber += 1; 
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
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"variable"))) 
        {
            varlist->var[varlist->varNumber].sourceDev = (char*) xmlGetProp(cur, "source");
            varlist->var[varlist->varNumber].sourceAddress = (char*) xmlGetProp(cur, "sourceaddress");
            varlist->var[varlist->varNumber].destinationDev = (char*) xmlGetProp(cur, "destination");
            varlist->var[varlist->varNumber].destinationAddress = (char*) xmlGetProp(cur, "destinationaddress");

            vvarlistarList->varNumber += 1;
		}
	    cur = cur->next;
	}
    return;
}

void readFullConfig(devices* devlist, variables* varlist)
{
	xmlDocPtr config;
	xmlNodePtr cur;
    char docPath[CONFIG_PATH_MAX_LENGHT];

    snprintf(docPath, sizeof(docPath), "%s/variables.xml", confpath());
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