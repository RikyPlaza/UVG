#include "uvgstrings.h"

char* strtolower(char* str)
{
    for(char *p = str; *p; p++) 
    {
        *p=tolower(*p);
    }

    return s;
}