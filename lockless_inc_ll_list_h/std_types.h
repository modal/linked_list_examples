#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

#include <limits.h>

#ifdef  _MSC_VER
//http://msdn.microsoft.com/en-us/library/cc953fe1.aspx
//http://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.90).aspx
typedef unsigned __int8 u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;
typedef __int8 s8;
typedef __int16 s16;
typedef __int32 s32;
typedef __int64 s64;
typedef float f32;
typedef double f64;
#endif

#ifdef __NIOS2__
#include "alt_types.h"
typedef alt_8 s8;
typedef alt_u8 u8;
typedef alt_16 s16;
typedef alt_u16 u16;
typedef alt_32  s32;
typedef alt_u32 u32;
typedef alt_64 s64;
typedef alt_u64 u64;
typedef float f32;
typedef double f64;
#endif

#ifdef __GNUC__
#ifndef __NIOS2__
#include "inttypes.h"
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef float f32;
typedef double f64;
#endif
#endif

#ifdef __MSP430__
//EABI is different then coff
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef char s8;
typedef short s16;
typedef long s32;
typedef long long s64;
typedef float f32;
#ifdef __TI_EABI__
typedef double f64;
#else
typedef struct __f64_STRUCT {float __a[2];} f64; //COFF ABI doesn't have a 64-bit float
#endif
#endif

#ifndef BUILD_BUG_ON
//http://lxr.free-electrons.com/source/tools/virtio/linux/bug.h
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#endif
#define BUILD_BUG_ON_SIZE_NOT_MULT_OF_4(__TY)     BUILD_BUG_ON(sizeof(__TY) & 0x3)
#define BUILD_BUG_ON_SIZE_TEST(__TY, SZ)    BUILD_BUG_ON(sizeof(__TY) != (SZ))

//Verify type size are correct
inline static void std_type_verify(void)
{
    BUILD_BUG_ON(sizeof(u8)  != 1);
    BUILD_BUG_ON(sizeof(u16) != 2);
    BUILD_BUG_ON(sizeof(u32) != 4);
    BUILD_BUG_ON(sizeof(s8)  != 1);
    BUILD_BUG_ON(sizeof(u64) != 8);
    BUILD_BUG_ON(sizeof(s16) != 2);
    BUILD_BUG_ON(sizeof(s32) != 4);
    BUILD_BUG_ON(sizeof(s64) != 8);
    BUILD_BUG_ON(sizeof(f32) != 4);
    BUILD_BUG_ON(sizeof(f64) != 8);
}

#endif
