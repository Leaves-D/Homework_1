#include <stdio.h>

int two_dim_array_access(int *x,int i,int j,int m,int n,int C){
        int offset = (m - i) * C + (n - j);
        return *(x + offset);
}

int main(){
        int A[2][3]={
                {1,2,3},
                {4,5,6}
        };
        int a=two_dim_array_access(&A[0][0],0,0,1,2,3);
        int b=two_dim_array_access(&A[0][1],0,1,1,2,3);
        printf("%d\n%d\n",a,b);
        return 0;
}
