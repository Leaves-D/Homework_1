#include <stdio.h>
int main(){
        int i,shige[10],result[10];
        printf("分行输入十个整数,程序为您逆序输出\n");
        for(i=0;i<10;i++){
                scanf("%d",&shige[i]);
                result[9-i]=shige[i];
        }
        for(i=0;i<10;i++){
                printf("%d ",result[i]);
        }

return 0;
}
