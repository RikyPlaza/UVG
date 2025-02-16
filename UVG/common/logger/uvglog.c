#include <time.h>
#include <stdio.h>
#include "uvglog.h"

time_t clk;
void initlog()
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