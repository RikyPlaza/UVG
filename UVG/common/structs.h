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
} device_t;

typedef struct
{
    device_t dev[DEV_NUMBER_MAX];
    uint8_t devNumber;
} devices;

typedef struct
{
    char* sourceDev;
    char* sourceAddress;
    char* destinationDev;
    char* destinationAddress;
} variable_t;

typedef struct
{
    variable_t var[VAR_NUMBER_MAX];
    uint8_t varNumber;
} variables;