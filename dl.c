#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
    struct listNode *prev ; //will keep address of previous node
} ;
struct listNode * list ;
struct listNode * tail ;
int length;

void initializeList()
{
    list = 0 ; //set to NULL
    tail = 0 ; //set to NULL
    length=0;
}

int insertItemBegin(int item)
{
    struct listNode *newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    newNode->prev = 0 ; //no previous node as this is the first item
    if ( newNode->next != 0 ){
        newNode->next->prev = newNode ;
    } else{
        tail = newNode ; //this is the first node in the list
    }
    length++;
    return SUCCESS_VALUE ;
}

int insertItemLast(int item)
{
    struct listNode *newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->prev = tail ;
    tail = newNode ;
    newNode->next = 0 ; //no next node as this is the last node
    if ( newNode->prev != 0 ){
        newNode->prev->next = newNode ;
    }
    else
        {
            list = newNode ; //this is the first node in the list
        }
    length++;
    return SUCCESS_VALUE ;
}

void PrintALL()
{
    struct listNode *temp;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        printf("%d ",temp->item);
        temp = temp->next ; //move to next node
    }
    printf("\n");
}


//ASSIGNMENTS STARTS HERE...
// Delete the last occurrence of the item in the list
int deleteLastOccurrence(int item){

    if(list == NULL || length == 0){
        return NULL_VALUE;
    }

    struct listNode * temp = list, * prev = NULL,*curr = NULL;;

    while(temp){
        if(temp->next && temp->next->item == item){
          prev = temp;
          curr = temp->next;
        }
        temp = temp->next;
    }

    if(prev){
        prev->next = curr->next;
    }else if(list->item == item){
        list = list->next;
    }

    length--;
	return SUCCESS_VALUE;

}

// delete the first item of the list
int deleteFirstItem(){
    if(list == NULL || length == 0){
        return NULL_VALUE;
    }
    list = list->next;
	free(list->prev);
	list->prev = NULL;
	length--;
	return SUCCESS_VALUE;
};

// delete the last item of the list
int deletelastItem(){
     if(list == NULL || length == 0){
        return NULL_VALUE;
    }

    while(list) {
		if (list->next->next == NULL) {
			free(list->next);
			list->next = NULL;
			length--;
			return SUCCESS_VALUE;
		}
		list = list->next;
	}
	return SUCCESS_VALUE;
};

//ASSIGNMENTS ENDS HERE...



int main()
{
    char inp1, chk;
    int inp2;
    int s;
    initializeList();
    while(1){
        scanf("%c",&inp1);


        switch(inp1)
        {
        case 'I':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;
        case 'i':
            scanf("%d",&inp2);
            s=insertItemLast(inp2);
            break;
        case 'P':
            PrintALL();
            break;
        case 'L':
            printf("Length: %d\n",length);
            break;

        case 'p':
            scanf("%d",&inp2);
            s=deleteLastOccurrence(inp2);
            break;

        case 'R':
            s=deletelastItem();
            break;

        case 'D':
            s=deleteFirstItem();
            break;
        }
        if(s==NULL_VALUE) break;
    }

}
