#include <stdio.h>
int main(){
        int n,a,b;
        scanf("%d",&n);
        b=28;
        if(n%400==0)
                b=29;
        else
                if(n%4==0){
                        if(n%100!=0)
                                b=29;
                }
        printf("31,%d,31,30,31,30,31,31,30,31,30,31",b);
}
