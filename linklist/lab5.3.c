#include <stdio.h> 
#include <stdlib.h> 
typedef struct node { 
    int data; 
    struct node *next; 
} node_t; 

// Write your code here 
// ... 
node_t *findNode(node_t *headNode,int index){
    node_t *ptrNode = headNode;
    for (int i = 0; i < index; i++)
    {
        ptrNode = ptrNode->next;
    }
    return ptrNode;
}
node_t *findLastNode(node_t *headNode) {
    node_t *ptrNode = headNode;
    while (ptrNode->next != NULL) {
        ptrNode = ptrNode->next;
    }
    return ptrNode;
}
node_t *createNewNode(int value) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

node_t *append(node_t *headNode) {
    node_t *ptrNode ;
    //struct Node* head = NULL;
    int number;
    scanf("%d", &number);
    node_t *tempNode = createNewNode(number);
    if (headNode == NULL) {
        headNode = tempNode;
    }else{
        ptrNode = findLastNode(headNode);
        ptrNode->next = tempNode;
    }
    return headNode;
}
node_t *get(node_t *headNode){
    int index;
    scanf("%d",&index);
    node_t *ptrNode = findNode(headNode,index);
    printf("%d\n",ptrNode->data);
}
node_t *show(node_t *headNode){
    node_t *ptrNode = headNode;
    while (ptrNode != NULL)
    {
        printf("%d ",ptrNode->data);
        ptrNode = ptrNode->next;
    }
}
node_t *reverse(node_t *headNode){
    node_t *currentnode =  headNode;
    node_t *prevnode = NULL;
    node_t *nextnode;
    while(currentnode != NULL){
        nextnode = currentnode->next;
        currentnode ->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    headNode = prevnode;
    return headNode;
}    

node_t *cut(node_t *headNode){
    int first,end;
    scanf("%d %d",&first,&end);
    node_t *firstindex = findNode(headNode,first);
    node_t *endindex = findNode(headNode,end);
    if(endindex->next != NULL){
        free(endindex->next);
    }
    endindex->next = NULL;
    return firstindex;
}
    

void printLinkedList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
     printf("\n");
}

int main(void) { 
    node_t *startNode; 
    int n,i; 
    char command; 
    
    startNode = NULL; 
    scanf("%d", &n); 
    for (i=0; i<n; i++) { 
        scanf(" %c", &command); 
        switch (command) { 
            case 'A': 
                startNode = append(startNode);  
                //printLinkedList(startNode);
                break; 
            case 'G': 
                get(startNode); 
                break; 
            case 'S': 
                show(startNode); 
                break; 
            case 'R': 
                startNode = reverse(startNode);  
                break; 
            case 'C': 
                startNode = cut(startNode);  
                break; 
            default: 
                break; 
        } 
    }
    return 0; 
}