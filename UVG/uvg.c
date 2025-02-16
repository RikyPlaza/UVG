#include <stdio.h>
#include "common/common.h"
#include "common/logger/uvglog.h"

int main(int argc, char **argv) 
{
	devices devList;
	variables varList;
	
	initlog();
	initStructs(&devList, &varList);
	populateStructs(&devList, &varList);
	
	return (1);
}
