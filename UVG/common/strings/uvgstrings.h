#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>

#define STRINGLEN 1024

char* strtolower(char* str);
void uvgsprintf(char* buf, char* fmt, va_list vars);
char* uvgremovechar(char* buf, char ch);