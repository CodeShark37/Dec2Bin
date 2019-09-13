#include "../headers/logs.h"


extern void __cdecl free(void *_Memory);
extern void *__cdecl malloc(size_t _Size);
extern int __cdecl puts(const char *_Str);
extern int __cdecl printf_s(const char *_Format,...);

static void freeLog(struct log** logn);
static void removeLog(LOGGER* logger,uint16_t id);


void initLogger(LOGGER* logger){
    if(logger){
        logger->size = 0;
        logger->root = NULL;
    }
}

struct log* getLog(LOGGER* logger,uint16_t id){
    unsigned short i;
    struct log *tmp = NULL;
    for(i=1,tmp=logger->root;(i<id)&&(id<=logger->size);tmp=tmp->next,i++);
    return tmp;
}

void insertLog(LOGGER* logger,intmax_t dec,unsigned char* bin){
    if(logger){
        struct log *tmp = NULL;
        tmp = (struct log*) malloc(sizeof(struct log));
        if(!tmp)return;
        tmp->dec = dec;
        tmp->bin = bin;
        tmp->next = NULL;
        if(logger->root){
            struct log *_tmp = NULL;
            _tmp = getLog(logger,logger->size);
            _tmp->next = tmp;
        }else{logger->root = tmp;}
        logger->size++;
    }
}

static void removeLog(LOGGER* logger,uint16_t id){
    if(logger->root){
        struct log *tmp = NULL;
        tmp=getLog(logger,id);
        if( tmp == logger->root){
            logger->root = tmp->next;
            freeLog(&tmp);
        }
        else{
            tmp = getLog(logger,(id-1));
            struct log *_tmp = (tmp->next->next) ? tmp->next->next:NULL;
            freeLog(&tmp->next);
            tmp->next = _tmp;
        }
        logger->size--;
    }
}

void displayLogger(LOGGER* logger){
    if(logger->root){
        uint16_t i;
        struct log *tmp = logger->root;
        puts("\n\tN\tFROM_(10)\tTO_(2)");
        for(i=0;i<logger->size;i++){
            printf_s("\t%.2hu\t%lld\t\t%s\n",i+1,tmp->dec,tmp->bin);
            tmp = tmp->next;
       }
    }
}

static void freeLog(struct log** logn){
    if(logn){
        (*logn)->dec = 0;
        free((*logn)->bin);
        (*logn)->bin = NULL;
        (*logn)->next = NULL;
        free(*logn);
        *logn = NULL;
    }
}

void freeLogger(LOGGER* logger){
    uint16_t i;
    for(i=logger->size;i>0;removeLog(logger,i),i--);

}
