#include <stdio.h>
#include "uvgstrings.h"

char* strtolower(char* str)
{
    for(char *p = str; *p; p++) 
    {
        *p=tolower(*p);
    }

    return str;
}

char* uvgsprintf(char* buf, char* fmt, ...)
{
    va_list va;
    va_start (va, fmt);
    vsprintf (buf, fmt, va);
    va_end (va);

    return buf;
}