#include "Logger.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

void FALog(LogLevel level, const char* message, ...) {

    const char* levels[4] = {"[TRACE]", "[INFO]", "[WARN]", "[ERROR]"};

    const int maxMsgLen = 32000;
    char output[maxMsgLen];
    memset(output, 0, sizeof(output));

    va_list arg;
    va_start(arg, message);
    const int status = vsnprintf(output, maxMsgLen, message, arg);
    va_end(arg);

    if (status < 0)
        FALog(LogLevelError, "String formatting error");

    char out[maxMsgLen];

    sprintf(out, "%s: %s\n", levels[level], output);

    const char* colors[] = {"1;30", "1;32", "1;33", "0;41"};

    printf("\033[%sm%s\033[0m", colors[level], out);
}
