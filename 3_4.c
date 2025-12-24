#include <stdio.h>
int A[2][3]={{1,2,3},{4,5,6}};

int main(){
        int i,j;
        for(i=0;i<2;i++){
                for(j=0;j<3;j++){
                        printf("%d",A[i][j]);
                }
        }
        printf("\n");
        return 0;
}
