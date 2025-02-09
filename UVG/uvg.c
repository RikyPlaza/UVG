#include <stdio.h>
#include "common/common.h"

int main(int argc, char **argv) 
{
	devices devList;
	variables varList;

	initStructs(&devList, &varList);
	populateStructs(&devList, &varList);
	
	return (1);
}
