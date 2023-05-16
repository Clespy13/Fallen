#include <iostream>

#define FA_TRACE 1
#define FA_INFO 1
#define FA_WARN 1
#define FA_ERROR 1

typedef enum LogLevel {
    LogLevelTrace = 0,
    LogLevelInfo,
    LogLevelWarn,
    LogLevelError,
} LogLevel;

void FALog(LogLevel level, const char* message, ...);

#ifndef TRACE
#ifdef FA_TRACE
#define TRACE(message, ...) FALog(LogLevelTrace, message, ##__VA_ARGS__)
#else
#define TRACE(message, ...)
#endif
#endif

#ifndef INFO
#ifdef FA_INFO
#define INFO(message, ...) FALog(LogLevelInfo, message, ##__VA_ARGS__)
#else
#define INFO(message, ...)
#endif
#endif

#ifndef WARN
#ifdef FA_WARN
#define WARN(message, ...) FALog(LogLevelWarn, message, ##__VA_ARGS__)
#else
#define WARN(message, ...)
#endif
#endif

#ifndef ERROR
#ifdef FA_ERROR
#define ERROR(message, ...) FALog(LogLevelError, message, ##__VA_ARGS__)
#else
#define ERROR(message, ...)
#endif
#endif

