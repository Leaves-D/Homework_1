#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char id[20];
    char name[20];
    float scores[3];   // 3门课程成绩
    float average;     // 平均分
} Student;


Student students[100];
int studentCount = 0;
const char* fileName = "student_data.txt";

// 函数声明
void menu();
void inputStudent();
void queryStudent();
void sortStudents();
void statistics();
void printStudent(Student s);
int loadData();
int saveData();
void trimNewline(char* str);
void clearBuffer(); // 新增：清空输入缓冲区

int main() {
    // 启动加载历史数据
    if (loadData() == 0) {
        printf("成功加载历史数据，当前共 %d 名学生\n", studentCount);
    } else {
        printf("无历史数据（首次运行），已创建数据文件\n");
    }
    printf("按任意键进入菜单...");
    clearBuffer(); // 替换getchar()，确保清空缓冲区
    getchar();     // 等待用户按任意键
    system("clear");

    int choice;
    while (1) {
        menu();
        printf("请输入功能编号：");
        scanf("%d", &choice);
        clearBuffer(); // 读取功能编号后，清空缓冲区残留换行符

        switch (choice) {
            case 1:
                inputStudent();
                break;
            case 2:
                queryStudent();
                break;
            case 3:
                sortStudents();
            case 4:
                statistics();
                break;
            case 0:
                printf("退出系统，数据已保存...\n");
                saveData(); // 退出时再次保存
                return 0;
            default:
                printf("输入错误，请重新选择！\n");
        }
        printf("\n按任意键返回菜单...");
        clearBuffer(); // 清空缓冲区，避免残留字符干扰
        getchar();
        system("clear");
    }
}

// 主菜单
void menu() {
    printf("==================== 学生成绩管理系统 ====================\n");
    printf("1. 录入学生信息\n");
    printf("2. 查询学生信息（学号精确/姓名模糊）\n");
    printf("3. 按平均分排序\n");
    printf("4. 成绩统计\n");
    printf("0. 退出系统\n");
    printf("==========================================================\n");
}
// 新增：清空输入缓冲区（核心修正）
void clearBuffer() {
    int ch;
    // 循环读取缓冲区所有字符，直到读到换行符或EOF（清空残留）
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// 去除字符串末尾的换行符（不变）
void trimNewline(char* str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0'; // 把换行符替换为字符串结束符
    }
}

// 从TXT加载数据到内存
int loadData() {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        fp = fopen(fileName, "w");
        fclose(fp);
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        trimNewline(line); // 读取后立即去除换行符，避免存入结
构体
        if (strlen(line) == 0) continue; // 跳过空行
        char* token = strtok(line, ",");
        if (token == NULL) continue;
        strcpy(students[studentCount].id, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(students[studentCount].name, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[studentCount].scores[0] = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[studentCount].scores[1] = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[studentCount].scores[2] = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[studentCount].average = atof(token);

        studentCount++;
        if (studentCount >= 100) {
            printf("警告：已达最大学生数100，停止读取更多数据>！\n");
            break;
        }
    }

    fclose(fp);
    return 0;
}

// 内存数据写入TXT文件
int saveData() {
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("文件写入失败！数据未保存！\n");
        return 1;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%s,%s,%.1f,%.1f,%.1f,%.1f\n",
                students[i].id,
                students[i].name,
                (double)students[i].scores[0],
                (double)students[i].scores[1],
                (double)students[i].scores[2],
                (double)students[i].average);
    }

    fclose(fp);
    return 0;
}
// 录入学生信息（修正：添加缓冲区清空）
void inputStudent() {
    if (studentCount >= 100) {
        printf("系统容量已满，无法添加更多学生！\n");
        return;
    }

    Student s;
    printf("请输入学生信息：\n");
    printf("学号（最多19个字符）：");
    scanf("%19s", s.id);
    clearBuffer();

    printf("姓名（最多19个字符）：");
    scanf("%19s", s.name);
    clearBuffer();

    printf("请输入3门课程成绩（用空格分隔）：");
    scanf("%f %f %f", &s.scores[0], &s.scores[1], &s.scores[2]);
    clearBuffer(); // 录入成绩后，清空缓冲区残留换行符/空格

    // 成绩合法性校
    for (int i = 0; i < 3; i++) {
        if (s.scores[i] < 0 || s.scores[i] > 100) {
            printf("警告：成绩需在0-100之间，已自动修正为0！\n");
            s.scores[i] = 0;
        }
    }

    s.average = (s.scores[0] + s.scores[1] + s.scores[2]) / 3.0;
    students[studentCount++] = s;
    printf("录入成功！当前共有 %d 名学生\n", studentCount);
    saveData(); // 录入后保存
}

// 打印单个学生信息
void printStudent(Student s) {
    printf("学号：%s\t姓名：%s\t", s.id, s.name);
    printf("成绩1：%.1f\t成绩2：%.1f\t成绩3：%.1f\t",
           (double)s.scores[0], (double)s.scores[1], (double)s.scores[2]);
    printf("平均分：%.1f\n", (double)s.average);
}

// 查询学生信息
void queryStudent() {
    if (studentCount == 0) {
        printf("暂无学生信息，请先录入！\n");
        return;
    }

    int choice;
    char key[20];
    printf("查询方式：1.按学号精确查询  2.按姓名模糊查询\n");
    printf("请选择：");
    scanf("%d", &choice);
    clearBuffer(); // 读取查询方式后，清空缓冲区

    printf("请输入查询关键词：");
    scanf("%19s", key);
    clearBuffer(); // 读取关键词后，清空缓冲区

    int found = 0;
    printf("\n查询结果：\n");
    for (int i = 0; i < studentCount; i++) {
        if (choice == 1) {
            // 学号精确匹配
            if (strcmp(students[i].id, key) == 0) {
                printStudent(students[i]);
                found++;
            }
        } else if (choice == 2) {
            // 姓名模糊匹配
            if (strstr(students[i].name, key) != NULL) {
                printStudent(students[i]);
                found++;
            }
        }
    }

    if (!found) {
        printf("未找到匹配的学生信息！\n");
    } else {
       printf("查询完成，共找到 %d 条记录！\n", found);
    }
}

// 按平均分降序排序（不变）
void sortStudents() {
    if (studentCount <= 1) {
        printf("学生人数不足，无需排序！\n");
        return;
    }

    // 冒泡排序
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
    saveData(); // 排序后保存顺序
}

// 成绩统计（不变）
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
