#include <stdio.h>

int sum(int m){
        int i,a=0;
        for(i=1;i<=m;i++){
                a+=i;
        }
        return a;
}

int main(){
        int n,result;
        scanf("%d",&n);
        result=sum(n);
        printf("%d\n",result);
return 0;

}
