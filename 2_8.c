#include <stdio.h>
int main(){
        int n,a,last,result,time;
        scanf("%d",&n);
        a=n;
        while(a!=1){
                last=a%10;
                printf("%d",last);
                if(a>=10)
                        a=((a-last)/10);
                else break;
        }
        printf("\n");
return 0;
}
