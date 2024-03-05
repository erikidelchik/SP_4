#include <stdio.h>
#include <string.h>
#include "compress.h"
#include <stdlib.h>

int main(int argc,char *argv[]){
    char mode;
    FILE *file = NULL;

    if(argc==3){
        if(!strcmp(argv[1],"-c")){
            mode = 'c';
            if(strlen(argv[2])>4 && !strcmp(argv[2]+ (strlen(argv[2])-4),".txt"))
                file = fopen(argv[2],"r+");
            else return -1;
        }
        else if(!strcmp(argv[1],"-d")){
            mode = 'd';
            if(strlen(argv[2])>4 && !strcmp(argv[2]+ (strlen(argv[2])-4),".bin"))
                file = fopen(argv[2],"rb+");
            else return -1;
        }
        else return -1;

    }
    else return -1;

    if(file==NULL) return -1;
    fclose(file);


    FILE *filebin = fopen("asd.bin","ab+");
    FILE *filetxt = fopen("asd.txt","r+");

    if(mode=='c'){
        int ch;
        int n;

        if(filetxt==NULL){
            perror("open file");
        }
        int c = 0;
        while((ch=fgetc(filetxt))>0){
            n = ch-'0';
            printf("%d ",n);

            intToBinFile(n,filebin);
            c++;
        }
        if(c%2!=0) fprintf(file,"0000");
    }
    if(mode=='d'){
        char buf[4];
        int curr = 0;
        fseek(filebin,curr,SEEK_SET);
        while (fread(buf,sizeof (buf),1,filebin)>0){
            binToIntFile(buf,filetxt);
            curr+=4;
            fseek(filebin,curr,SEEK_SET);
        }


    }

    fclose(filebin);
    fclose(filetxt);
    



    return 0;



}
