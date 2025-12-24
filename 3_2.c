#include <stdio.h>
int main(){
        int yuan[10],i,j;
        int count[10]={0};
        printf("输入十个数字按空格隔开:\n");
        for(i=0;i<10;i++){
                scanf("%d",&yuan[i]);
        }
        for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                        if(j==yuan[i]){
                                count[j]+=1;
                                break;
                        }
                }
        }
        for(i=0;i<10;i++){
                printf("%d在输入中出现的次数为：%d\n",i,count[i]);
        }
}
