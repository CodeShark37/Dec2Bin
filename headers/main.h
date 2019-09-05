#ifndef _main_h_
#define _main_h_


#include <stdbool.h>
#include "logs.h"

extern int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
extern void processLogF(unsigned char* fname,LOGGER* logger);
extern void saveLog2F(LOGGER *logger,bool op);
extern int __cdecl puts(const char *_Str);

#endif
