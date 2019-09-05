#ifndef _hnd_file_h_
#define _hnd_file_h_


#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "logs.h"

extern unsigned char* dec2bin(intmax_t dec);

void processLogF(unsigned char* fname,LOGGER* logger);
void saveLog2F(LOGGER *logger,bool op);

#endif
