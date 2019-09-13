#ifndef _convert_h_
#define _convert_h_

#include <stdint.h>

#define NULL ((void *)0)
#if SIZE_MAX == UINT64_MAX
#define USE_64BITS
#endif // SIZE_MAX

extern void *__cdecl malloc(size_t _Size);
unsigned char* dec2bin(intmax_t dec);

#endif
