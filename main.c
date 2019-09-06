#include "headers/main.h"


int main(int argc,char **argv)
{
    LOGGER lc;
    initLogger(&lc);

    switch(argc){
        case 2:
            processLogF((unsigned char*)argv[1],&lc);
            displayLogger(&lc);
        break;
        case 3:
            processLogF((unsigned char*)argv[1],&lc);
            if(!strncmp("-wofo",argv[2],5))saveLog2F(&lc,true);
            else saveLog2F(&lc,false);
        break;
        default:puts("Error: Invalid Input File or options");
    }
    freeLogger(&lc);

    return 0;
}
