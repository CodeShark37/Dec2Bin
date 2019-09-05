#include "../headers/convert.h"


static uint8_t binlen(intmax_t dec);
static unsigned char* dec2bin8(int8_t dec);
static unsigned char* dec2bin16(int16_t dec);
static unsigned char* dec2bin32(int32_t dec);
#ifdef USE_64BITS
static unsigned char* dec2bin64(int64_t dec);
#endif // USE_64BITS

static uint8_t binlen(intmax_t dec){
    if((dec >= INT8_MIN)&&(dec <= UINT8_MAX))return 8;
    if((dec >= INT16_MIN)&&(dec <= UINT16_MAX))return 16;
    if((dec >= INT32_MIN)&&(dec <= UINT32_MAX))return 32;
    if((dec >= INT64_MIN)&&(dec <= UINT64_MAX))return 64;
}

static unsigned char* dec2bin8(int8_t dec){
    unsigned short i;
    unsigned char* bin = NULL;
    bin = (unsigned char*)malloc(9*sizeof(unsigned char));

    if(bin){
        for(i=0;i<8;i++)*(bin+i) = (dec & (0x80U>>i)) ? '1':'0';
        *(bin+i) = '\0';
    }
    return bin;
}

static unsigned char* dec2bin16(int16_t dec){
    unsigned short i;
    unsigned char* bin = NULL;
    bin = (unsigned char*)malloc(17*sizeof(unsigned char));

    if(bin){
        for(i=0;i<16;i++)*(bin+i) = (dec & (0x8000U>>i)) ? '1':'0';
        *(bin+i) = '\0';
    }
    return bin;
}

static unsigned char* dec2bin32(int32_t dec){
    unsigned short i=(dec<0)? 1:0;
    unsigned char* bin = NULL;
    bin = (unsigned char*)malloc(33*sizeof(unsigned char));

    if(bin){
        if(dec<0){*bin='1';}
        for(;i<32;i++)*(bin+i) = (dec & (0x80000000UL>>i)) ? '1':'0';
        *(bin+i) = '\0';
    }
    return bin;
}

#ifdef USE_64BITS
static unsigned char* dec2bin64(int64_t dec){
    unsigned short i=(dec<0)? 1:0;
    unsigned char* bin = NULL;
    bin = (unsigned char*)malloc(65*sizeof(unsigned char));

    if(bin){
        if(dec<0){*bin='1';}
        for(;i<64;i++)*(bin+i) = (dec & (0x8000000000000000ULL>>i)) ? '1':'0';
        *(bin+i) = '\0';
    }
    return bin;
}
#endif // USE_64BITS

unsigned char* dec2bin(intmax_t dec){
    uint8_t len = binlen(dec);
    if(len <= 8)return dec2bin8(dec);
    else if(len <= 16)return dec2bin16(dec);
    else if(len <= 32)return dec2bin32(dec);
    #ifdef USE_64BITS
    return dec2bin64(dec);
    #endif // USE_64BITS
}
