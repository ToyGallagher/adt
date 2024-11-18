/*#include <stdio.h>
#include <string.h>

int STARTYEAR =1970;
int STARTDAY= 5;
int STARTMONTH =1;

struct day {
    char name[4];
    //int index;
} days[7];

struct month {
    char name[10];
    int totalDays;
} months[12];

void setupDays() {
    strcpy(days[0].name, "Sun");
    strcpy(days[1].name, "Mon");
    strcpy(days[2].name, "Tue");
    strcpy(days[3].name, "Wed");
    strcpy(days[4].name, "Thu");
    strcpy(days[5].name, "Fri");
    strcpy(days[6].name, "Sat");
}

void setupMonths() {
    strcpy(months[0].name, "JAN");
    strcpy(months[1].name, "FEB");
    strcpy(months[2].name, "MAR");
    strcpy(months[3].name, "APR");
    strcpy(months[4].name, "MAY");
    strcpy(months[5].name, "JUN");
    strcpy(months[6].name, "JUL");
    strcpy(months[7].name, "AUG");
    strcpy(months[8].name, "SEP");
    strcpy(months[9].name, "OCT");
    strcpy(months[10].name, "NOV");
    strcpy(months[11].name, "DEC");

    months[0].totalDays = 31;
    months[1].totalDays = 28;
    months[2].totalDays = 31;
    months[3].totalDays = 30;
    months[4].totalDays = 31;
    months[5].totalDays = 30;
    months[6].totalDays = 31;
    months[7].totalDays = 31;
    months[8].totalDays = 30;
    months[9].totalDays = 31;
    months[10].totalDays = 30;
    months[11].totalDays = 31;
}

typedef struct datetime {
    int date;
    int month;
    int year;
    int dayOfWeek;
    int hour;
    int minute; 
    int second; 
} datetime_t;

int isLeapYear(int year) {
    if (year % 400 == 0 && year % 100 == 0) return 1;
    else if (year % 4 == 0 && year % 100 != 0) return 1;
    else return 0;
}

datetime_t createDate(int timestamp) {
    setupDays();
    setupMonths();
    datetime_t dateInformation;

    int secondsInOneDay = 60 * 60 * 24;
    int currSeconds = 0;
    int currDay = 1, currMonth = STARTMONTH, currYear = STARTYEAR;
    int totalDays = STARTDAY;

    while (currSeconds + secondsInOneDay < timestamp) {
        currSeconds += secondsInOneDay;
        currDay+=1;
        totalDays+=1;

        if (currDay > months[currMonth - 1].totalDays) {
            currDay = 1;
            currMonth++;
        }

        if (currMonth > 12) {
            currMonth = 1;
            currYear++;
            months[1].totalDays = (isLeapYear(currYear)) ? 29 : 28;
        }
    }

    timestamp = timestamp - (totalDays - STARTDAY) * secondsInOneDay;
    //printf("%d\n",totalDays);
    //printf("%d\n",timestamp);

    dateInformation.hour = timestamp / (60 * 60);
    dateInformation.minute = (timestamp % (60 * 60)) / 60;
    dateInformation.second = timestamp % (60 * 60) % 60;
    dateInformation.date = currDay;
    dateInformation.dayOfWeek = (totalDays - 1) % 7 + 1;
    dateInformation.month = currMonth;
    dateInformation.year = currYear;
    return dateInformation;
}
void printDate(datetime_t dateInformation) {
    printf("%s %d %s %d %02d:%02d:%02d",
    days[dateInformation.dayOfWeek - 1].name,
    dateInformation.date,
    months[dateInformation.month - 1].name,
    dateInformation.year,
    dateInformation.hour,
    dateInformation.minute,
    dateInformation.second);
}

int main(void) {
    datetime_t inputDate;
    int timestamp;
    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}*/
//1 
/*#include <stdio.h> 
typedef struct datetime { 
    int date; // 1-31 
    int month; // 1-12 
    int year; // 1970++ 
    int dayOfWeek; // 0-6 
    int hour; // 0-23 
    int minute; // 0-59 
    int second; // 0-59 
} datetime_t; 

int checkLeapYear(int year){
    
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else{
        return 0;
    }
}
    createDate(int timestamp) { 
        
        return 0 ;
} 
    //printDate() { 
 
//} 
int main(void) { 
    datetime_t inputDate; 
    int timestamp; 
    scanf("%d", &timestamp); 
    inputDate = createDate(timestamp);  
    //printDate(inputDate); 
    return 0; 
}*/

// 3
/*#include <stdio.h> 
#include <stdlib.h> 
typedef struct node { 
    int data; 
    struct node *next; 
} node_t; 

// Write your code here 
// ... 
int append(*int number){
    struct Node* head = NULL;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = number;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return head;
    }
    struct node* current = head;  
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;

    return head;

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
                printLinkedList(startNode);
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
}*/

//2
/*
#include <stdio.h>
#include <stdlib.h>

char *mallocCharBySize(int size) {
    return (char *) malloc(sizeof(char) * size);
}

char *reallocCharBySize(char *ptr, int size) {
    return (char *) realloc(ptr, sizeof(char) * size);
}

int getInput(char **ptrArr) {
    int countSize = 1;
    while (1) {
        char temp = getchar();
        if (temp == '\n') 
            break;

        *(*ptrArr + (countSize - 1)) = temp;
        *ptrArr = reallocCharBySize(*ptrArr, sizeof(char) * (++countSize));
        *(*ptrArr + (countSize - 1)) = '\0';
    }
    return countSize;
}

int copyRemainValue(char **pResultArr, char *ptrArr, int pointIndex, int carry) {
    int copyValue;
    int repeat = pointIndex + 1;
    for (int i = 0; i < repeat; i++) {
        copyValue = *(ptrArr + pointIndex) - 48 + carry;

        if (copyValue >= 10) 
            carry = 1;
        else 
            carry = 0;

        *(*pResultArr + pointIndex) = copyValue % 10 + 48;

        pointIndex--;
    }
    return carry;
}

int plus(char **pResultArr, char *pNumArr1, char *pNumArr2, int sizeArr1, int sizeArr2) {
    int pointIndex1 = sizeArr1 - 2, pointIndex2 = sizeArr2 - 2, pointResultIndex; 
    int repeat;
    int carry, largerArr;
    if (sizeArr1 > sizeArr2) {
        *pResultArr = reallocCharBySize(*pResultArr, sizeArr1);
        pointResultIndex = sizeArr1 - 2;
        repeat = sizeArr2 - 1;
        largerArr = 1;
    }
    else {
        *pResultArr = reallocCharBySize(*pResultArr, sizeArr2);
        pointResultIndex = sizeArr2 - 2;
        repeat = sizeArr1 - 1;
        largerArr = 0;
    }
    *(*pResultArr + pointResultIndex + 1) = '\0';

    carry = 0;
    for (int i = 0; i < repeat; i++) {
        int sumOfTwoDigits = (*(pNumArr1 + pointIndex1) - 48) + (*(pNumArr2 + pointIndex2) - 48) + carry;
        if (sumOfTwoDigits >= 10) 
            carry = 1;
        else 
            carry = 0;

        *(*pResultArr + pointResultIndex) = (char)(sumOfTwoDigits % 10 + 48);

        pointIndex1--;
        pointIndex2--;
        pointResultIndex--;
    }
    if (largerArr) 
        carry = copyRemainValue(&*pResultArr, pNumArr1, pointIndex1, carry);
    else 
        carry = copyRemainValue(&*pResultArr, pNumArr2, pointIndex2, carry);
    return carry;
}

void displayResult(char *ptrArr, int carry) {
    if (carry) 
        printf("1%s", ptrArr);
    else
        printf("%s", ptrArr);
}

int main(void) {
    char *pNumArr1 = mallocCharBySize(1);
    char *pNumArr2 = mallocCharBySize(1);
    char *pResultArr = mallocCharBySize(1);
    int sizeArr1 = getInput(&pNumArr1);
    int sizeArr2 = getInput(&pNumArr2);
    int carry;
    carry = plus(&pResultArr, pNumArr1, pNumArr2, sizeArr1, sizeArr2);
    displayResult(pResultArr, carry);
    free(pNumArr1);
    free(pNumArr2);
    free(pResultArr);
    return 0;
}*/
/*
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void addLargeNumbers(const char num1[], const char num2[], char result[]) {
    int carry = 0;
    int i, j;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

    char paddedNum1[MAX_DIGITS + 1];
    char paddedNum2[MAX_DIGITS + 1];

    // Pad zeros to make both numbers have the same length
    strcpy(paddedNum1, num1);
    strcpy(paddedNum2, num2);

    while (strlen(paddedNum1) < maxLen)
        strcat(paddedNum1, "0");
    while (strlen(paddedNum2) < maxLen)
        strcat(paddedNum2, "0");

    // Addition loop
    for (i = maxLen - 1; i >= 0; i--) {
        int sum = (paddedNum1[i] - '0') + (paddedNum2[i] - '0') + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    // Handle the final carry, if any
    if (carry)
        result[maxLen++] = carry + '0';

    // Null-terminate the result
    result[maxLen] = '\0';

    // Reverse the result to get the correct sum
    reverse(result, maxLen);
}

int main() {
    const char num1[] = "94354657669743043298785692374893278427348962874678326498779483279234692369487837489267536";
    const char num2[] = "65084675429473847289473894578934758937458973489539887349857984375983745897348957983478947";
    char result[MAX_DIGITS + 1];

    addLargeNumbers(num1, num2, result);

    printf("Sum: %s\n", result);

    return 0;
}*/
/*
//4
#include <stdio.h>


int main(){
    int player;
    int number;
    int limit[1000];
    int result;
    int count_drink[1000];
    int count = 0;
    scanf("%d %d",&player , &number);
    for (int i = 0; i < player; i++)
    {
        scanf("%d",&limit[i]);
        limit[i]++;
    }
    
    }
    


    //for (int i = 0; i < player; i++){
        //printf("%d ",limit[i]);
        //}
    
}*/