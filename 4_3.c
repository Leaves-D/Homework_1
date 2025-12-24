#include <stdio.h>

void swap(int *x,int *y);


int main(){
        int a,b,c=0;//测试可以不
        scanf("%d %d",&a,&b);
        swap(&a,&b);
        printf("%d,%d",a,b);
        return 0;
}

void swap(int *x,int *y){
        int temp = *x;
        *x=*y;
        *y=temp;

}
