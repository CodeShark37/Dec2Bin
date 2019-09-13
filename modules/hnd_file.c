#include "../headers/hnd_file.h"


extern int __cdecl tmpnam_s(char*,rsize_t);
extern int __cdecl printf_s(const char *_Format,...);
extern int __cdecl fprintf_s(FILE *_File,const char *_Format,...);
extern int __cdecl fscanf_s(FILE *_File,const char *_Format,...);
extern int __cdecl strcpy_s(char * __restrict__ _Dest,rsize_t _Destmax,const char * __restrict__ _Source);


void processLogF(unsigned char* fname,LOGGER* logger){
    intmax_t data;
    FILE* in = NULL;
    in = fopen((const char*)fname,"r");
    if(!in)puts("Error: Invalid Input File");
    else{
        while(!feof(in)){
            if(fscanf_s(in,"%lld,",&data) > 0)
            insertLog(logger,data,dec2bin(data));
            else{puts("Error: An Invalid Input data");break;}
        }
    }
    fclose(in);
}

void saveLog2F(LOGGER *logger,bool op){
    uint8_t i;
    char fname[13];
    FILE* out = NULL;
    tmpnam_s(fname,7);
    strcpy_s(fname+6,4,"txt");
    out = fopen((const char*)fname+1,"w+");
    if(!out)puts("Error: Failed to create Output File");
    else{
        struct log* _log = NULL;
        for(i=0;i<logger->size;i++){
            _log = getLog(logger,i+1);
            if(op)
                fprintf_s(out,"[%.2hu]:%s;\n",i+1,_log->bin);
            else fprintf_s(out,"[%.2hu]:%lld:%s;\n",i+1,_log->dec,_log->bin);
        }
    }
    fclose(out);
}
