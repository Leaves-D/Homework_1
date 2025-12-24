#include <stdio.h>
int main(){
        char c;
        int i,b;
        //enum xushuci{first=1,second,third,fourth,fifth,sixth,seventh,eighth} th;
        scanf("%c",&c);
        for(i=8;i>=1;i--){
                th=i;
                if(c/(2^i)==1){
                        b=1;
                        c=c-2^i;
                }
                else b=0;
                printf("The %d bit is %d,\n",b,b);
        }
        //th f=3;
        //printf("%c",f);
        return 0;
}
