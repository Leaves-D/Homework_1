#include <stdio.h>
#include <string.h>

struct Student{
        char name[20];
        int score;
} student[3];

int main(){
        struct Student *p=student;
        strcpy(p->name,"yihao");
        p->score = 96;
        strcpy((p+1)->name,"erhao");
        (p+1)->score = 98;
        strcpy((p+2)->name,"sanhao");
        (p+2)->score = 99;

        struct Student student_max=*p;
        int i;
        for(i=0;i<3;i++){
                if((p+i)->score > student_max.score){
                        student_max=*(p+i);
                }
        }
        printf("%s,%d\n",student_max.name,student_max.score);

        return 0;
}
