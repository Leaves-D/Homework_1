#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define P snake_pointer
#define BIAN1 "@@@@@@@@@@@\n"
//9*9的可移动范围

typedef struct snake_node{
        int x;
        int y;
        struct snake_node *next;
}snake_node,*snake_pointer;

int A[9][9];
int PAN=0,f=0;
int food_x,food_y;
int snake_head_x=4,snake_head_y=4;
char direction ='d';
P head=NULL;
        int new_head_x = 4;
        int new_head_y = 4;
int food_exist=0;

void create_food();
P create_node(int x,int y);
void insert_tail(P *head,int x,int y);
void free_list(P head);
void dayin();
void yidong();
void yi();void er();int san();void si(int eat_food);void wu();void liu();
void zhuti();
void update_snake_body(P,int,int);
void init_snake(){
        insert_tail(&head,snake_head_x,snake_head_y);
        A[snake_head_x][snake_head_y]=1;
}
int eat_food =0;

int main(){
        //设置地图初始值
        for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                        A[i][j]=0;
                }
        }
        //set snake head
        init_snake();
        srand((unsigned int)time(NULL));
        while(!PAN){
                if(!food_exist){
                        create_food();
                        food_exist=1;
                }
                dayin();
                zhuti();
                if(PAN)break;
        }
        printf("Good Game\n");
        free_list(head);

        return 0;
}

void zhuti(){
        //由键盘输入-yi
        yi();
        if(PAN)return;
        f++;
        //改蛇头位置-er
        er();
        if(PAN)return;
        //判断碰撞-wu
        wu();
        if(PAN)return;
        //判断吃食物-san
        eat_food = san();
        //改网格012，也即改蛇身和蛇尾-si
        si(eat_food);
        if(eat_food)food_exist=0;
}

void wu(){
        if(A[new_head_x][new_head_y]==1){
                PAN=1;
                printf("撞到自己了\n");
                return;
        }
}

// 删除尾节点，并返回其坐标（用于清除 A[][]）
void delete_tail(P *head, int *tail_x, int *tail_y) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        // 只有一个节点
        *tail_x = (*head)->x;
        *tail_y = (*head)->y;
        free(*head);
        *head = NULL;
        return;
    }
    P temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    P tail = temp->next;
    *tail_x = tail->x;
    *tail_y = tail->y;
    free(tail);
    temp->next = NULL;
}

// 在头部插入新节点
void insert_head(P *head, int x, int y) {
    P new_pointer= create_node(x, y);
    new_pointer->next = *head;
    *head = new_pointer;
}

void si(int eat_food) {
    int tail_x = 0, tail_y = 0;

    // 先清除旧蛇在 A 中的标记（后面会重新标记）
    // 实际上我们只删尾（如果不吃食物），头会新增

    if (!eat_food) {
        // 没吃食物：删除尾部
        delete_tail(&head, &tail_x, &tail_y);
        A[tail_x][tail_y] = 0;  // 清除尾部显示
    }

    // 插入新头
    insert_head(&head, new_head_x, new_head_y);
    A[new_head_x][new_head_y] = 1;  // 标记新头

    // 更新全局蛇头（其实可以不用，但为了 san() 兼容）
    snake_head_x = new_head_x;
    snake_head_y = new_head_y;

    if (eat_food) {
        printf("成功吃食，长蛇小子\n");
    }
}

//原问题爆点
void si_(int eat_food){
        A[new_head_x][new_head_y]=1;

        snake_head_x =new_head_x;
        snake_head_y =new_head_y;

        if(!eat_food){
                P temp=head;
                if(temp==NULL)return;
                if(temp->next==NULL){
                        A[temp->x][temp->y]=0;
                        temp->x=snake_head_x;
                        temp->y=snake_head_y;
                        return;
                }
                else{   //找倒数第二个节点
                        while(temp->next->next!=NULL){
                                temp=temp->next;
                        }
                        A[temp->next->x][temp->next->y]=0;
                        free(temp->next);
                        temp->next = NULL;
                }
        }
        else{
                insert_tail(&head,food_x,food_y);
                A[food_x][food_y]=0;
                printf("成功吃食，长蛇小子\n");
        }

}
int san(){
        if(food_x==snake_head_x && food_y==snake_head_y)return 1;
        else return 0;
}

void create_food(){
        do{
                food_x=rand()%9;
                food_y=rand()%9;
        }while(A[food_x][food_y]==1);
        A[food_x][food_y]=2;
}

void er(){
        new_head_x = snake_head_x;
        new_head_y = snake_head_y;

        switch(direction){
                case 'a':new_head_y--;break;
                case 'w':new_head_x--;break;
                case 'd':new_head_y++;break;
                case 's':new_head_x++;break;
                default:
                         printf("异常:%c\n",direction);
                         break;
        }
        if(new_head_x <0 || new_head_x >= 9||new_head_y<0||new_head_y>=9){
                PAN=1;
                return;
        }
}

void yi(){
        printf("请移动第%d次\n",f);
        fflush(stdout);
        do{
                direction =getchar();
        }while(direction=='\n'||direction==' ');

        if(direction>='A'&&direction<='Z')direction+=32;
        printf("direction  %c\n",direction);
        if(direction !='w' && direction != 'a' && direction != 's' && direction != 'd'){
                printf("输入错误！请重新输入\n");
                f--;
                return;
        }

}


snake_pointer create_node(int x,int y){
        snake_pointer new_pointer=(snake_pointer)malloc(sizeof(snake_node));
        if(NULL == new_pointer){
                perror("malloc failed");
                exit(EXIT_FAILURE);
        }
        new_pointer->x = x;
        new_pointer->y = y;
        new_pointer->next = NULL;
        return new_pointer;
}

void insert_tail(snake_pointer *head,int x,int y){
        snake_pointer new_pointer=create_node(x,y);
        if(NULL==*head){
                *head=new_pointer;
                return;
        }
        snake_pointer temp=*head;
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next =new_pointer;
}

void free_list(snake_pointer head){
        snake_pointer current=head;
        snake_pointer next_node =NULL;
        int r=0;
        while(NULL != current ){
                next_node = current->next;
                free(current);
                current=next_node;
                r++;
        }
        printf("已释放%d个链节\n",r);
}

void dayin(){
        printf(BIAN1);

        //逐格检测
        for(int i=0;i<9;i++){
                printf("@");
                for(int j=0;j<9;j++){
                        switch(A[i][j]){
                                case 0:
                                        printf(" ");
                                        break;
                                case 1:
                                        printf("O");
                                        break;
                                case 2:
                                        printf("*");
                                        break;
                        }
                }
                printf("@");
                printf("\n");
        }


        printf(BIAN1);
}
