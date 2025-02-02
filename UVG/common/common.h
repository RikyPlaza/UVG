typedef enum
{
    
} devtype;

typedef struct
{
    devtype type;
    char* port;
} dev_t;

const char* confpath(void)