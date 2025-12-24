#include <stdio.h>

int pansu(int n){
        int a,b=1;
        for(a=2;a<n;a++){
                if(0==(n%a))
                        b=a;
        }
        if(b==1)
        return 1;
        else
        return 0;
        }

int main(){
        int i,n;
        printf("输入正数n，输出1~n的所有素数\n");
        scanf("%d",&n);
        for(i=2;i<=n;i++){
        int k=pansu(i);
        if(k==1)
                printf("%d\n",i);
        }
}
