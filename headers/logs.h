#ifndef _logs_h_
#define _logs_h_

#include <stdint.h>
#define NULL ((void *)0)

struct log{
    long long dec;
    unsigned char *bin;
    struct log *next;
};

typedef struct __logger{
    uint16_t size;
    struct log *root;
}LOGGER;


void initLogger(LOGGER* logger);
void displayLogger(LOGGER* logger);
void freeLogger(LOGGER* logger);
void insertLog(LOGGER* logger,long long dec,unsigned char* bin);
struct log* getLog(LOGGER* logger,uint16_t id);

#endif
