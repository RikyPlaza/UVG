#include <stdio.h>
#include "common/common.h"

int main(int argc, char **argv) 
{
	time_t clk;
	initlog(&clk);

	devices devList;
	variables varList;
	initStructs(&devList, &varList);
	populateStructs(&devList, &varList);
	
	return (1);
}
