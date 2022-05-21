#include <stdio.h>

#define STACK_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
//int data[STACK_MAX_SIZE];


typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* top;
int length = 0;

 push(int value){
    if(STACK_MAX_SIZE == length){
        return NULL_VALUE;
    }
    struct Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = top;
    top = temp;
    length++;
    return value;
}

 pop(){
    Node* temp = top;
    if(top == NULL) return;
    top = temp->next;
    free(temp);
    length--;
    return top->value;
}

char* isEmpty(){
    Node* temp = top;
    int i = 0;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i == 0 ? "Empty" : "Not Empty";
}

int IsFull()
{
    if(top == STACK_MAX_SIZE) return TRUE_VALUE ;
    else return FALSE_VALUE ;
}

int getLength()
{
    printf("\n Length is: %d", length);
}


void PrintAll(){
    Node* temp = top;
    while(temp != NULL){
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int a,result;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        switch(ch)
        {
        case 'P':
            scanf("%d",&a);
            result=push(a);
            break;
        case 'p':
            result=pop();
            printf("%d\n",result);
            break;
        case 's':
            PrintAll();
            break;

        case 'l':
            getLength();
            break;

        default:
            break;
        }
        if(result==NULL_VALUE) break;
    }
}
