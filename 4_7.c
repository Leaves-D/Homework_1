#include <stdio.h>
#include <stdlib.h>

typedef struct list_item{
        int data;
        struct list_item *next;
}LIST;

LIST* create(int data){
        LIST *node =(LIST*)malloc(sizeof(LIST));
        if(node == NULL)
                exit(1);
        node->data=data;
        node->next=NULL;
        return node;
}

void erase_list(LIST *head){
        LIST *current=head;
        LIST *tmp;
        while(current!= NULL ){
                tmp=current->next;
                free(current);
                current=tmp;
        }

}

int main(){
        LIST *head=create(1);
        head->next=create(2);
        head->next=create(3);
        erase_list(head);
        return 0;
}
