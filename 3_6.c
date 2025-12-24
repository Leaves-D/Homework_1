#include <stdio.h>

int sum_hang(const char *p,int i,int b){
        int l,sum=0;
        for(l=0;l<b;l++){
                sum+=*(p+l);
        }
        return sum;
}

//引用第三题选择排序算法

int main(){
        int a,b,i,j,k,tmp,min;
        printf("需排序不同数组请在c文件内部更改数组和维度参数");
        char A[5][6] = {
                {'S','D','U','Y','E','S'},
                {'C','H','I','N','A','!'},
                {'A','F','T','E','R','X'},
                {'h','e','r','o','a','b'},
                {'C','y','y','D','S','!'}
        };
        a=5;b=6;
        int SUM[a];

        for(i=0;i<a;i++){
                SUM[i]=sum_hang(&A[i][0],i,b);

        }//到此已经求单行和
        char TMP[b];
        for(i=0;i<(a-1);i++){
                for(j=i+1;j<a;j++){
                        min=SUM[i];
                        if(SUM[j]<min){
                                for(k=0;k<b;k++){
                                        TMP[k]=A[i][k];
                                        A[i][k]=A[j][k];
                                        A[j][k]=TMP[k];
                                        tmp=SUM[i];
                                        SUM[i]=SUM[j];
                                        SUM[j]=tmp;
                                }
                        }
                }
        }
//到此应该完成行的排序
        for(k=0;k<a;k++){
        for(i=0;i<(b-1);i++){
                for(j=i+1;j<b;j++){
                        if(A[k][j]<A[k][i]){
                        TMP[i]=A[k][i];
                        A[k][i]=A[k][j];
                        A[k][j]=TMP[i];
                        }

                }
        }
        }
//此处排列完行内
        for(i=0;i<a;i++){
                printf("\n");
                for(j=0;j<b;j++){
                        printf("%c",A[i][j]);
                }
                printf("\n");
        }


        return 0;
}
