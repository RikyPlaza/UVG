#define CONFIG_PATH_MAX_LENGHT 512
#define VAR_NUMBER_MAX 2048
#define DEV_NUMBER_MAX 30

typedef enum
{
    SIEMENS_CLIENT,
    OMRON_CLIENT,
    OPCUA_CLIENT
} devtype;

typedef struct
{
    char* name;
    devtype type;
    char* port;
} dev_t;

typedef struct
{
    dev_t dev[DEV_NUMBER_MAX]
    uint8_t devNumber
} devices;

devices devlist;

const char* confpath(void);
void initStructs(devices* devlist);