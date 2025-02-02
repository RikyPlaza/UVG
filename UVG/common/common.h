#define CONFIG_PATH_MAX_LENGHT 512
#define VAR_NUMBER_MAX 2048
#define DEV_NUMBER_MAX 30

typedef enum
{

} devtype;

typedef struct
{
    devtype type;
    char* port;
} dev_t;

const char* confpath(void);