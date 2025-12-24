#include <stdio.h>

int my_strlen(char *str){
        int len=0;
        while(*str!='\0'){
                len++;
                str++;
        }
        return len;
}

int main(){
        int length=0;
        char str[100];
        scanf("%s",str);
        length=my_strlen(str);
        printf("长度为%d\n",length);
        return 0;
}
