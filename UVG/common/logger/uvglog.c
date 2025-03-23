#include <time.h>
#include <stdio.h>
#include "uvglog.h"

time_t clk;
void initlog()
{
    clk = time(NULL);
    char* timestamp = ctime(&clk);
    uvgremovechar(timestamp, '\n');
    printf("%s - Logger initialized.\n", timestamp);
}

void uvglog(const char* log)
{
    char* timestamp = ctime(&clk);
    uvgremovechar(timestamp, '\n');
    printf("%s - %s\n", timestamp, log);
}

void uvgdebuglog(int codeLine, const char* funcName, const char* log, ...)
{    
#ifdef DEBUG
    va_list args;
    va_start (args, log);

    char buffer[STRINGLEN];
    uvgsprintf(buffer, log, args);
    char* timestamp = ctime(&clk);
    uvgremovechar(timestamp, '\n');
    uvgremovechar(buffer, '\n');
    printf("%s - Function: %s Line: %d - %s\n", timestamp, funcName, codeLine, buffer);

    va_end (args);
#endif
}