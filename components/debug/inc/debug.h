#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef DEBUG_SEGGER
    #include <SEGGER_RTT.h>

    #define DEBUG_PRINT_STRING(str) SEGGER_RTT_WriteString(0, (str));
    #define DEBUG_PRINTF(...) SEGGER_RTT_printf(0, __VA_ARGS__);
#else
    #define DEBUG_PRINT_STRING(str)
    #define DEBUG_PRINTF(...)
#endif

void Debug_CrashHandler(void);
void Debug_PrintMemoryUsage(void);
void Debug_Breakpoint(void);

#endif // DEBUG_H_
