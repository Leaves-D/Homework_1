#include <stdio.h>
int main(){
        int n,a,b;
        b=1;
        scanf("%d",&n);
        for(a=1;a<n;a++){
                if(0==(n%a))
                        b=a;
        }
        if(b==1)
        printf("yes\n");
        else
        printf("no\n");
}
