#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int i,j,bushu=0,nP=1;//nP表示当前操作玩家为1P还是2P
int A[20][20];
//初始化

int moshi=1,suiji=0;
int a=-1,b=-1;

int suijishu();
        void (*p)();
        void panshengfu(int a,int b);
        void renjixia();
        void dayindangqianqipan();
        void mingquewanjia();
void xiaqi();


int main(){
        //初始化基础数据
        srand((unsigned int)time(NULL));

        for(i=0;i<20;i++){
                for(j=0;j<20;j++){
                        A[i][j]=0;
                }
        }

        printf("2P对决请按1，人机对决请按2\n");
        scanf("%d",&moshi);
        printf("\n");

        if(1==moshi){
                p=xiaqi;
        }
        else if(2==moshi){
                p=renjixia;
        }
        printf("模式选择完毕，请输入坐标下棋\n");
        int m;
        for(m=0;m<20;m++){
        mingquewanjia();
        xiaqi();
        mingquewanjia();
        p();
        }
}

void panshengfu(int a, int b) {
    // 判断当前落子的玩家（1或2）
    int k = (bushu % 2 == 1) ? 1 : 2;  // 确保逻辑正确：步数为
奇/偶对应玩家
    int count;  // 连续相同棋子的计数

    // 1. 水平方向判断（同一行）
    count = 1;  // 初始化为1（当前落子本身）
    // 向左检查
    for (int i = 1; i < 5; i++) {
        // 边界检查：不超出棋盘左边界，且棋子相同
        if (b - i >= 0 && A[a][b - i] == k) {
            count++;
        } else {
            break;  // 遇到不同棋子或边界，停止检查
        }
    }
    // 向右检查
    for (int i = 1; i < 5; i++) {
        if (b + i < SIZE && A[a][b + i] == k) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 5) {
        printf("%dP win!\n", k);
        exit(0);  // 胜利，退出程序
    }

    // 2. 垂直方向判断（同一列）
    count = 1;
    // 向上检查
    for (int i = 1; i < 5; i++) {
        if (a - i >= 0 && A[a - i][b] == k) {
            count++;
        } else {
            break;
        }
    }
    // 向下检查
    for (int i = 1; i < 5; i++) {
        if (a + i < SIZE && A[a + i][b] == k) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 5) {
        printf("%dP win!\n", k);
        exit(0);
    }

    // 3. 斜线方向1（左上到右下）
    count = 1;
    // 左上方向
    for (int i = 1; i < 5; i++) {
        if (a - i >= 0 && b - i >= 0 && A[a - i][b - i] == k) {
            count++;
        } else {
            break;
        }
    }
    // 右下方向
    for (int i = 1; i < 5; i++) {
        if (a + i < SIZE && b + i < SIZE && A[a + i][b + i] == k) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 5) {
        printf("%dP win!\n", k);
        exit(0);
    }

    // 4. 斜线方向2（右上到左下）
    count = 1;
    // 右上方向
    for (int i = 1; i < 5; i++) {
        if (a - i >= 0 && b + i < SIZE && A[a - i][b + i] == k) {
            count++;
        } else {
            break;
        }
    }
    // 左下方向
    for (int i = 1; i < 5; i++) {
        if (a + i < SIZE && b - i >= 0 && A[a + i][b - i] == k) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 5) {
        printf("%dP win!\n", k);
        exit(0);
    }
}

void renjixia(){//需要上一步玩家下的位置
        i=0,j=0;
        while(1){
        i++;
        int suiji1=suijishu();
        int suiji2=suijishu();
        int x = a + suiji1;
        int y = b + suiji2;
        // 检查坐标是否在棋盘内且未被占用
        if (x >= 0 && x < SIZE && y >=0 && y < SIZE && A[x][y] == 0){
                A[x][y] = 2;
                bushu += 1;
                panshengfu(x, y);
                break;
        }
        if(i>50)break;
        }
}
int suijishu(){
        return (rand()%2)?1:-1;//周围正负1格随机
}

void dayindangqianqipan(){
        printf("   ");
        for(i=0;i<20;i++){
                printf("%3d",i);
        }
        printf("\n");
        for(i=0;i<20;i++){
                printf("%3d",i);
                for(j=0;j<20;j++){
                        printf("%3d",A[i][j]);
                }
                printf("\n");
        }

}
//棋盘上只有0，1，2；

void mingquewanjia(){
        nP=(bushu+1)%2?1:2;
        printf("请%dP玩家操作",nP);
}
void xiaqi() {
    int input_result;  // 存储scanf的返回值，判断是否读取成功
    while (1) {  // 循环直到输入正确
        printf("请输入横纵坐标（格式：x,y）：");  // 提示用户>正确的输入格式
        input_result = scanf("%d,%d", &a, &b);  // 仅匹配 "数>字,数字" 格式

        // 清除输入缓冲区的残留字符（避免错误输入导致死循环）
        while (getchar() != '\n');

        // 检查输入是否成功（返回值为2表示正确读取两个整数）
        if (input_result != 2) {
            printf("输入格式错误，请按 x,y 格式重新输入（例如 3,4）\n");
            continue;
        }

        // 检查坐标是否在合法范围（0<=a<20 且 0<=b<20）
        if (a < 0 || a >= SIZE || b < 0 || b >= SIZE) {
            printf("坐标错误（范围0-19），请重新输入\n");
            continue;
        }

        // 检查坐标是否已被占用
        if (A[a][b] != 0) {
            printf("该位置已落子，请重新输入\n");
            continue;
        }
        }

        // 所有检查通过，落子并退出循环
        A[a][b] = nP;
        dayindangqianqipan();  // 打印棋盘
        bushu += 1;  // 步数+1
        panshengfu(a, b);  // 判断胜负
        break;  // 退出循环，结束函数
    }
}
