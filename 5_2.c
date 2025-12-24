#include <stdio.h>

char f(char (*pp)[5]) 
{return pp[1][2];}

int main(){
    char *B[20];
    f(B);
    printf("%s\n",f(B));
    return 0;
}
