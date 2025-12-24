#include <stdio.h>
int main(){
        int i,j,p,bigger,smaller;
        int yuan[4];
        //下面不小心对yuan操作了，所以yuan最后变成选择排序后的结
果了，zhenyuan为原数
        printf("输入4个数字，按空格隔开:\n");
        for(i=0;i<4;i++){
                scanf("%d",&yuan[i]);
        }

        //选择算法
        j=0;
        p=0;
        for(p=0;p<=3;p++){
        while(j<4){
                for(j=1;j<=3;j++){
                        if(yuan[p]>yuan[j]){
                                bigger=yuan[p];
                                smaller=yuan[j];
                                yuan[p]=smaller;
                                yuan[j]=bigger;
                                break;
                        }
                }

        }
        }
        printf("选择排序后得到：\n");
        for(i=0;i<4;i++){
               printf("%d ",yuan[i]);
        }
        return 0;
}
