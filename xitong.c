#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DATA "%s,%s,%.1f,%.1f,%.1f,%.1f\n"

typedef struct Student{
        char id[20];
        char name[20];
        float scores[3];
        float average;
} Student;

Student students[100];
int studentCount=0;
const char* fileName="student_date.txt";

void menu();
void inputStudent();
void queryStudent();
void sortStudents();
void statistics();
void printStudent(Student s);
int loadData();
int saveData();

int main(){
        if(loadData()==0){
                printf("成功加载历史数据，当前共 %d 名学生\n",studentCount);
        }
        else{
                printf("首次运行，已创建数据文件\n");
        }
        int choice;
        while(1){
                menu();
                printf("请输入功能编号");
                scanf("%d",&choice);
                getchar();

                switch(choice){
                        case 1:
                                inputStudent();
                                break;
                        case 2:
                                queryStudent();
                                break;
                        case 3:
                                sortStudents();
                                break;
                        case 4:
                                statistics();
                                break;
                        case 0:
                                printf("退出系统，数据已保存...\n");
                                return 0;
                        default:
                                printf("输入错误，请重新选择!\n");
                }
                printf("\n按任意键返回菜单...");
                getchar();
                system("clear");
        }

        return 0;
}

void menu() {
    printf("==================== 学生成绩管理系统 ====================\n");
    printf("1. 录入学生信息\n");
    printf("2. 查询学生信息\n");
    printf("3. 按平均分排序\n");
    printf("4. 成绩统计\n");
    printf("0. 退出系统\n");
    printf("==========================================================\n");
}

int loadData(){
        FILE* fp=fopen(fileName,"r");
        if (fp=NULL){
                FILE* fp=fopen(fileName,"w");
                printf("无存储数据,已创建文件");
                fclose(fp);
                return 1;
        }

        char line[100];
        while(fgets(line,sizeof(line),fp)!=NULL){
                char* token=strtok(line,",");
                if(token==NULL)continue;
                strcpy(students[studentCount].id,token);

                token = strtok(NULL, ",");
                strcpy(students[studentCount].name, token);

                token = strtok(NULL, ",");
                students[studentCount].scores[0] = atof(token); // 字符串转浮点数

                token = strtok(NULL, ",");
                students[studentCount].scores[1] = atof(token);

                token = strtok(NULL, ",");
                students[studentCount].scores[2] = atof(token);
                token = strtok(NULL, ",");
                students[studentCount].average = atof(token);  

                studentCount++;
                if (studentCount>=100)break;
        }
        fclose(fp);
        return 0;
}

int saveData(){
        FILE* fp=fopen(fileName,"w");
        if(NULL==fp){
                printf("数据未正常保存\n");
                return 1;
        }
        for(int i=0;i<studentCount;i++){
                fprintf(fp,DATA,
                        students[i].id,
                        students[i].name,
                        students[i].scores[0],
                        students[i].scores[1],
                        students[i].scores[2],
                        students[i].average);
        }
        fclose(fp);
        printf("大致是正常保存了");
        return 0;
}
void inputStudent() {
    if (studentCount >= 100) {
        printf("系统容量已满，无法添加更多学生！\n");
        return;
    }

    Student s;
    printf("请输入学生信息：\n");
    printf("学号：");
    scanf("%s", s.id);
    printf("姓名：");
    scanf("%s", s.name);
    printf("请输入3门课程成绩（用空格分隔）：");
    scanf("%f %f %f", &s.scores[0], &s.scores[1], &s.scores[2]);

    s.average = (s.scores[0] + s.scores[1] + s.scores[2]) / 3.0;
    students[studentCount++] = s;
    printf("录入成功！当前共有 %d 名学生\n", studentCount);

    // 录入后自动保存到文件
    saveData();
}

void printStudent(Student s){
        printf(DATA,s.id,s.name,s.scores[0],s.scores[1],s.scores[2],s.average);
}

//void printStudent(Student s) {
//    printf("学号：%s\t姓名：%s\t", s.id, s.name);
//    printf("成绩1：%.1f\t成绩2：%.1f\t成绩3：%.1f\t", s.scores[0], s.scores[1], s.scores[2]);
//    printf("平均分：%.1f\n", s.average);
//}

// 查询学生信息（不变）
void queryStudent() {
    if (studentCount == 0) {
        printf("暂无学生信息，请先录入！\n");
        return;
    }

    int choice;
    char key[20];
    printf("查询方式：1.按学号查询  2.按姓名查询\n");
    printf("请选择：");
    scanf("%d", &choice);
    getchar();

    printf("请输入查询关键词：");
    scanf("%s", key);

    int found = 0;
    printf("\n查询结果：\n");
    for (int i = 0; i < studentCount; i++) {
        if ((choice == 1 && strcmp(students[i].id, key) == 0) ||
            (choice == 2 && strcmp(students[i].name, key) == 0)) {
            printStudent(students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的学生信息！\n");
    }
}

// 按平均分排序（新增保存调用，可选）
void sortStudents() {
    if (studentCount <= 1) {
        printf("学生人数不足，无需排序！\n");
        return;
    }

    // 冒泡排序（降序）
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - 1 - i; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("排序成功！按平均分降序排列如下：\n");
    for (int i = 0; i < studentCount; i++) {
        printf("排名%d：", i + 1);
        printStudent(students[i]);
    }

    // 排序后保存（排序改变了数组顺序，需更新文件）
    saveData();
}

// 成绩统计
void statistics() {
    if (studentCount == 0) {
        printf("暂无学生信息，请先录入！\n");
        return;
    }

    float totalAll = 0;
    float maxAvg = students[0].average;
    float minAvg = students[0].average;
    int passCount = 0;

    for (int i = 0; i < studentCount; i++) {
        totalAll += students[i].average;
        if (students[i].average > maxAvg) maxAvg = students[i].average;
        if (students[i].average < minAvg) minAvg = students[i].average;
        if (students[i].average >= 60) passCount++;
    }

    printf("==================== 成绩统计报告 ====================\n");
    printf("学生总数：%d 人\n", studentCount);
    printf("所有学生平均分均值：%.1f\n", totalAll / studentCount);
    printf("最高平均分：%.1f\n", maxAvg);
    printf("最低平均分：%.1f\n", minAvg);
    printf("及格人数（平均分>=60）：%d 人\n", passCount);
    printf("及格率：%.1f%%\n", (float)passCount / studentCount * 100);
    printf("======================================================\n");
}
