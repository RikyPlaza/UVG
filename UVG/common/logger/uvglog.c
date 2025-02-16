#include <time.h>
#include <stdio.h>
#include "uvglog.h"

void initlog(time_t* clk)
{
    clk = time(NULL);
}

void uvglog(const char* log)
{
    printf("%s - %s\n", ctime(&clk), log);
}

void uvgdebuglog(const char* log, int codeLine, const char* funcName)
{
#ifdef DEBUG
    printf("%s - Function: %s Line: %d - %s\n", ctime(&clk), funcName, codeLine, log);
#endif
}