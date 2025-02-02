#include "xmlreader.h"
#include "../common.h"

void getDevicesFromConfig(xmlDocPtr doc, xmlNodePtr cur) 
{

	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"device"))) 
        {
            devList.dev[devList.devNumber].name = (char*) xmlGetProp(cur, "name");
            devList.dev[devList.devNumber].port = (char*) xmlGetProp(cur, "port");
            devList.dev[devList.devNumber].type = getDevType((char*) xmlGetProp(cur, "type"));
		}
	    cur = cur->next;
	}
    return;
}

void getVariablesFromConfig(xmlDocPtr doc, xmlNodePtr cur) 
{

	cur = cur->xmlChildrenNode;
	while (cur != NULL) 
    {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"variable"))) 
        {
            /*insert into structure*/
		}
	    cur = cur->next;
	}
    return;
}

void readFullConfig()
{

	xmlDocPtr config;
	xmlNodePtr cur;
    char docPath[CONFIG_PATH_MAX_LENGHT] 

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

	xmlFreeDoc(config);
	return;
}