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

void uvgsprintf(char* buf, char* fmt, va_list vars)
{    
    vsprintf (buf, fmt, vars);
}

char* uvgremovechar(char* buf, char ch)
{
    int shift = 0;
    bool skipStrReset = false;
    for(int i = 0; i < strlen(buf); i++)
    {
        if(buf[i] == ch)
        {
            shift++;

            if(i == strlen(buf))
                skipStrReset = true;
        }            

        buf[i] = buf[i + shift];
    }

    int originalstrsize = strlen(buf);
    if(skipStrReset)
        for(int i = strlen(buf) - 1; i > originalstrsize - 1 - shift; i--)
            buf[i] = '\0';
}