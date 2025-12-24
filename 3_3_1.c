#include <stdio.h>
int main(){
        int i,j,position,min,max,bigger,smaller;
        int yuan[4],zhenyuan[4],maopaoxu[4];
        //下面不小心对yuan操作了，所以yuan最后变成选择排序后的结
果了，zhenyuan为原数
        printf("输入4个数字，按空格隔开:\n");
        for(i=0;i<4;i++){
                scanf("%d",&yuan[i]);
                maopaoxu[i]=yuan[i];
                zhenyuan[i]=yuan[i];
        }

        //选择算法
        for(i=0;i<3;i++){
                min=yuan[i];
                for(j=i+1;j<4;j++){
                        if(min>yuan[j]){
                                min=yuan[j];
                                position=j;
                        }
                }
                yuan[position]=yuan[i];
                yuan[i]=min;
        }

        printf("选择排序后得到：\n");
        for(i=0;i<4;i++){
                printf("%d ",yuan[i]);
        }
