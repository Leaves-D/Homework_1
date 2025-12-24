#include <stdio.h>
int main(){
        int n,a,b,t;//n%2==1
        b=1;
        scanf("%d",&n);
        for(a=1;a<=n;a+=2){
                if(a!=n)
                        for(t=1;t<=((n-a)/2);t++){
                        printf(" ");
                        }
                for(b=1;b<=a;b++){
                        printf("*");
                }
        printf("\n");
        }
        int c;
        for(c=(n-2);c>=1;c-=2){
                for(t=1;t<=((n-c)/2);t++){
                        printf(" ");
                }
                for(b=1;b<=c;b++){
                        printf("*");
                }
        printf("\n");
        }
}
