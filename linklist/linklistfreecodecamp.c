#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void Insert(int x){
    struct Node *ptr;
    ptr = head;
    struct Node* temp = malloc(sizeof(struct Node));    
    temp->data = x;
    temp->next = NULL;
    while(ptr->next != NULL){ 
        ptr = ptr->next;
    }
    ptr->next = temp;
    /*if(head==NULL){
        head = temp;
        return;
    }
    struct Node *temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    temp1->next = temp;
    }*/
}
void Print(){
    struct Node*temp = head;
    printf("List is : ");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL;
    printf("HOW many number? \n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter a number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
}