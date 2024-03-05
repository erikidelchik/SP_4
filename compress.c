#include <stdio.h>
#include <stdlib.h>

int poww(int a,int b){
    if(b==0) return 1;
    while(b>1){
        a+=a;
        b--;
    }
    return a;
}

void intToBinFile(int n,FILE *file){

    n = n&0xF;

    char bin[4];
    for(int i=3;i>=0;i--){
        if(n%2==0){
            bin[i]='1';
            n=n>>1;
        }
        else{
            bin[i]='0';
            n = n>>1;
        }
    }
    fprintf(file,"%s ",bin);
}

void binToIntFile(char* s,FILE *file){
    char b[4];
    for(int i=0;i<4;i++){
        if(s[i]=='0') b[i]='1';
        else b[i]='0';
    }
    int n=0;
    for(int i=0;i<4;i++){
        if(b[i]=='1')
            n+=poww(2,4-i);
    }
    sprintf(b,"%d",n);
    fprintf(file,"%s ",b);
}


