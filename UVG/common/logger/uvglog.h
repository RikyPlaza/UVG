time_t clk;

void initlog();
void log(const char* log, int codeLine, const char* funcName);
void debuglog(const char* log, int codeLine, const char* funcName);