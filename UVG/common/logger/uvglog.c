#include <time.h>
#include <stdio.h>
#include "uvglog.h"

time_t clk;
void initlog()
{
    clk = time(NULL);
    printf("%s - Logger initialized.\n", ctime(&clk));
}

void uvglog(const char* log)
{
    char* timestamp = ctime(&clk);
    uvgremovechar(timestamp, '\n');
    printf("%s - %s\n", timestamp, log);
}

void uvgdebuglog(const char* log, int codeLine, const char* funcName)
{
#ifdef DEBUG
    char* timestamp = ctime(&clk);
    uvgremovechar(timestamp, '\n');
    printf("%s - Function: %s Line: %d - %s\n", timestamp, funcName, codeLine, log);
#endif
}