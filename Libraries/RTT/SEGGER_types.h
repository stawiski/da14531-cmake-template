#ifndef SEGGER_TYPES_H
#define SEGGER_TYPES_H

#include <stdint.h>

#define U8 uint8_t
#define I8 int8_t
#define U16 uint16_t
#define I16 int16_t
#define U32 uint32_t
#define I32 int32_t

//
// CC_NO_LONG_SUPPORT can be defined to compile test
// without long support for compilers that do not
// support C99 and its long type.
//
#ifdef CC_NO_LONG_SUPPORT
    #define PTR_ADDR U32
#else // Supports long type.
    //
    // C99 compliant compiler
    //
    #define U64 unsigned long long
    #define I64 signed long long
    #define U64_C(x) x##ULL

    #define PTR_ADDR U32
#endif // Supports long type.

#endif
