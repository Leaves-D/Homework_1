#include <stdio.h>

void matrix_multi(double A[3][4], double B[4][5], double C[3][5]) {
    // 遍历C的每一行(i从0到2)
    for (int i = 0; i < 3; i++) {
        // 遍历C的每一列(j从0到4)
        for (int j = 0; j < 5; j++) {
            C[i][j] = 0;  // 初始化当前元素为0
            // 计算A的第i行与B的第j列的内积（k从0到3，共4个元素>）
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%lf ",C[i][j]);
        }
    printf("\n");
    }
}

int main(){
    double A[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    double B[4][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}
    };
    double C[3][5];  // 存储结果的3×5矩阵

    // 调用矩阵乘法函数
    matrix_multi(A, B, C);
}
