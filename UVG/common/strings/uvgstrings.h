#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define STRINGLEN 1024

char* strtolower(char* str);
char* uvgsprintf(char* fmt, ...);
char* uvgremovechar(char* buf, char ch);