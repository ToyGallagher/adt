//1
/*#include <stdio.h> 
#include <stdlib.h> 
typedef struct node { 
    int data; 
    struct node *next; 
} node_t; 
typedef node_t stack_t; 
stack_t *push(stack_t *s,int x){
    node_t* node = (node_t *)malloc(sizeof (node_t));
    node->data = x;
    node->next = s;
    s = node;
    return s; 
}
void top(stack_t *s){
    if (s==NULL){
        printf("Stack is empty.\n");
    }else{
        printf("%d\n",s->data);
    }
    
}
stack_t *pop(stack_t *s){
    if (s == NULL) {
        return NULL;
    }
    node_t* node = s;
    s = s->next;
    free(node);
    return s;
}
void empty(stack_t *s){
    if(s==NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is not empty.\n");
    }
}
void size(stack_t* s) {
    int count = 0;
    node_t* current = s;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("%d\n", count);
}

int main(void) { 
    stack_t *s = NULL; 
    int n, i, command, value; 
    scanf("%d", &n); 
    for (i=0; i<n; i++) { 
        scanf("%d", &command); 
        switch(command) { 
            case 1: 
            scanf("%d", &value); 
            s = push(s, value); 
             break; 
            case 2: 
                top(s); 
                break; 
            case 3: 
                s = pop(s); 
                break; 
            case 4: 
                empty(s); 
                break; 
            case 5: 
                size(s); 
                break; 
            } 
        } 
        return 0; 
}
*/


//2
/*#include <stdio.h> 
#include <stdlib.h> 
typedef struct node { 
    int data; 
    struct node *next; 
} node_t; 
typedef node_t queue_t; 

node_t* front = NULL;
node_t* rear = NULL;
queue_t *enqueue(queue_t *q,int x){
    node_t* node = (node_t *)malloc(sizeof (node_t));
    node->data = x;
    node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = node;
        return NULL;
    }
    rear->next = node;
    rear = node;
    return node;
}
queue_t *dequeue(queue_t *q){
    node_t* node = front;
    if (front==NULL)
    {
        printf("Queue is empty.\n");
        return NULL;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    
    printf("%d\n",node->data);
    
    return node;
}


void show(queue_t *q) {
    node_t *cur = front;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else{
        while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
        }
    }
    
}
void empty(queue_t *q){
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue is not empty.\n");
    }
}
void size(queue_t* q) {
    int count = 0;
    node_t* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("%d\n", count);
}

int main(void) { 
    queue_t *q = NULL; 
    int n, i, command, value; 
    
    scanf("%d", &n); 
    for (i=0; i<n; i++) { 
        scanf("%d", &command); 
        switch(command) { 
            case 1: 
            scanf("%d", &value); 
                q = enqueue(q, value);  
                break; 
            case 2: 
                q = dequeue(q); 
                break; 
            case 3: 
                show(q); 
                break; 
            case 4: 
                empty(q); 
                break; 
            case 5: 
                size(q); 
                break;
            } 
    } 
    return 0; 
}
*/
/*
//3
#include <stdio.h>
#include <string.h>
int main() {
    char input[1000000]; // 5 digits + 1 null terminator
    int input2;
    //printf("Enter 5 numbers: ");
    scanf("%d", &input2); // Read up to 5 characters
    scanf("%s", input);
    if (strlen(input) == input2) {
        // Convert the input to integers and process them
        for (int i = 0; i < input2; i++) {
            int num = input[i] - '0'; // Convert character to integer
            printf("%d ", i + 1, num);
        }
        
    } else {
        return 0;
    }

    return 0;
}
*/


//3
/*#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char character;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char c) {
    stack_t *tempNode = (stack_t *) malloc(sizeof(stack_t));
    tempNode->character = c;
    tempNode->next = s;
    s = tempNode;
    return s;
}

int empty(stack_t *s) {
    if (s == NULL)
        return 1;
    return 0;
}

char top(stack_t *s) {
    return s->character;
}   

stack_t *pop(stack_t *s) {
    if (s != NULL) {
        stack_t *tempNode = s;
        s = s->next;
        free(tempNode);
    }
    return s;
}

int openSide(char c) {
    if (c == '[' || c == '{' || c == '(')
        return 1;
    return 0;
}

int matching(char fisrtC, char secondC) {
    if (fisrtC == '(' && secondC == ')') return 1;
    if (fisrtC == '[' && secondC == ']') return 1;
    if (fisrtC == '{' && secondC == '}') return 1;
    return 0;
}

int main() {
    stack_t *s = NULL;
    int n, condition = 1;
    char inC;

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &inC);
        if (openSide(inC))
            s = push(s, inC);
        else {
            if (empty(s)) {
                condition = 0;
                break;
            } else if (matching(top(s), inC)) { 
                s = pop(s);
            } else {
                s = push(s, inC);
            }
        }
    }
    if (!empty(s)) condition = 0;
    printf("%d", condition);
    return 0;
}
*/


//4
/*#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    float number;
    struct node *next;
} node_t;
typedef node_t stack_t;

int isOperator(char c) {
    if (c == '+' || 
        c == '-' || 
        c == '*' || 
        c == '/')
        return 1;
    return 0;
}

float calculate(float num1, float num2, char operator) {
    float result;
    switch (operator) {
        case '+':
            result = num2 + num1;
            break;
        case '-':
            result = num2 - num1;
            break;
        case '*':
            result = num2 * num1;
            break;
        case '/':
            result = num2 / num1;
            break;
        default:
            break;
    }
    return result;
}

void push(stack_t **s, float number) {
    stack_t *newNode = (stack_t *) malloc(sizeof(stack_t));
    newNode->number = number;
    newNode->next = *s;
    *s = newNode;
}

float pop(stack_t **s) {
    stack_t *tempNode = *s;
    float value = tempNode->number;
    *s = (*s)->next;
    free(tempNode);
    return value;
}

int main() {
    int n;
    scanf("%d\n", &n);
    char inputChar[n + 1];
    scanf("%s", inputChar);
    stack_t *s = NULL;
    char tempC;
    float number1, number2, result;
    for (int i = 0; i < n; i++) {
        tempC = inputChar[i];

        if (isOperator(tempC)) {
            number1 = pop(&s);
            number2 = pop(&s);
            result = calculate(number1, number2, tempC);
            push(&s, result);
        } else 
            push(&s, (float)(tempC - 48));
    }
    free(s);
    printf("%.2f", result);
    return 0;
}
*/

//5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    struct node *next;
} node_t;
typedef node_t stack_t;

void push(stack_t **s, char c) {
    stack_t *newNode = (stack_t *) malloc(sizeof(stack_t));
    newNode->c = c;
    newNode->next = *s;
    *s = newNode;
}

char top(stack_t *s) {
    if (s != NULL)
        return s->c;
    return 0;
}

void pop(stack_t **s) {
    stack_t *tempNode = *s;
    *s = (*s)->next;
    free(tempNode);
}

int main() {
    stack_t *s = NULL;
    char tempC;
    
    while ((tempC = getchar()) != 'x') {
        push(&s, tempC);
    }

    int condition = 1;
    while ((tempC = getchar()) != 'y') {
        if (top(s) == tempC)
            pop(&s);
        else
            condition = 0;
    }
    if (s != NULL)
        condition = 0;
    printf("%d", condition);
    return 0;
}