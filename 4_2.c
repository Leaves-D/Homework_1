#include <stdio.h>
int main(){
        int i,j;
        int a[5];
        for(i=0;i<=4;i++){
                scanf("%d",&a[i]);
        }
        int *p;
        p=&a[0];
        for(j=0;j<=4;j++){
                printf("%d,%p ",*p,p);
                p++;
        }
        return 0;
}
