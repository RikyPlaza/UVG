#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void getReference(xmlDocPtr doc, xmlNodePtr cur) {

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"reference"))) {
		    printf("uri: %s\n", xmlGetProp(cur, "uri"));
		    }
	    cur = cur->next;
	}
    return;
}


void parseDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	
	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}
		
	getReference (doc, cur);
	xmlFreeDoc(doc);
	return;
}

int main(int argc, char **argv) {

	const char *docname;

	docname = "./variables.xml";
	parseDoc (docname);
	
	return (1);
}