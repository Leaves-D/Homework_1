#include <stdio.h>
#define KONG "□"
#define SHOU "■"

int A[10][10];
int a=0;
//只差读写文档
void kanzuo();
void xuanzuo();
int loaddata();
void savedata();
void jiancha();

int main(){
        loaddata();
        kanzuo();
        xuanzuo();
        jiancha();

        return 0;
}

void jiancha(){
        printf("当前A:\n");
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                        printf("%d ",A[i][j]);
                }
                printf("\n");
        }
}

void kanzuo(){
        printf("当前座位如下:\n");
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                        if(0==A[i][j]){
                                printf(KONG" ");
                        }
                        else if(1==A[i][j]){
                                printf(SHOU" ");
                        }
                }
                printf("\n");
        }

}


void xuanzuo(){
        printf("请输入行列号（格式：行，列）:");
        char B[5];
        scanf("%s",B);
        int x=B[0]-48;
        int y=B[2]-48;
        printf("%d,%d",x,y);

        //检查
        switch(A[x][y]){
                case 1:
                        printf("已售，请重选\n");
                        kanzuo();
                        break;
                case 0:
                        a=20;
                        printf("成功购票,目前所选票价为：%d元\n",a);
                        A[x][y]=1;
                        savedata();
                        kanzuo();
                        break;
        }
}

void savedata(){
        FILE* fp=fopen("a.txt","w");
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                        fprintf(fp,"%d",A[i][j]);
                }
        }
        fclose(fp);
        printf("大抵保存上了\n");

}

int loaddata(){
        char line[110];
        FILE* fp=fopen("a.txt","r");
        if(NULL==fp){
               for(int i=0;i<10;i++){
                        for(int j=0;j<10;j++){
                                A[i][j]=0;
                        }
                }
                printf("无先前数据，开始初次售票\n");
                return 0;
        }

        fgets(line,sizeof(line),fp);
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                        A[i][j]=((int)line[(10*i+j)]-48);
                }
        }
        fclose(fp);
        printf("大抵读取成功了\n");
        return 1;

}
