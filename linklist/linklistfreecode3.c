//Insert Node at n position 
/*#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void Insert(int data){
    struct Node* temp = malloc(sizeof(struct Node));  
    temp->data = data;
    head = temp;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;  
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL) {
    current = current->next;
}
    current->next = temp;
    return head;
    
}
void Print(){
    struct Node*temp = head;
    printf("List is :");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
}*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* current = head;  
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    printf("Linked List: ");
    printLinkedList(head);
    head = insertAtEnd(head, 20);
    printf("Linked List: ");
    printLinkedList(head);
    head = insertAtEnd(head, 30);
    printf("Linked List: ");
    printLinkedList(head);
    head = insertAtEnd(head, 40);

    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}