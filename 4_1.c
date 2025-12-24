#include <stdio.h>
int main(){
        int a,b;
        int *p;
        p=&a;
        printf("%d %p %p %d\n",a,&a,p,*p);
        p=&b;
        b=*p+10;
        printf("%d\n",b);
        return 0;
}
