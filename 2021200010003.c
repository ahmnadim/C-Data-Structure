#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999


struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
} ;
struct listNode * list ;
int length;

void initializeList()
{
    list = NULL ; //set to NULL
    length=0;
}

int insertItemBegin(int item)
{
    struct listNode * newNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    length++;
    return SUCCESS_VALUE ;
}

int insertItemLast(int item)
{
    struct listNode * newNode, *temp;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    temp = list;
    newNode->item = item;
    newNode->next = NULL;
	if (temp == NULL) {
		temp = newNode;
	} else {
		while (temp->next != NULL){
            temp = temp->next;
		}
		temp->next = newNode;
	}
	length++;
    return SUCCESS_VALUE;
}

int insertItemAT(int position, int item)
{
    if(position < 0 || position > length){
        return NULL_VALUE;
    }else if(position == 0){
        insertItemBegin(item);
        length++;
        return SUCCESS_VALUE;
    }else if(position == length){
        insertItemLast(item);
        length++;
        return SUCCESS_VALUE;
    }else{
        struct listNode * newNode, *temp, *prev, *next;
        newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
        temp = list;
        newNode->item = item;
        newNode->next = NULL;
         for (int i = 1; i != position; i++){
            temp = temp -> next;
         }
		newNode -> next = temp -> next;
		temp -> next = newNode;

        length++;
        return SUCCESS_VALUE;
    }

}

int searchItem(int item)
{
    struct listNode *temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp->item ;
        temp = temp->next ; //move to next node
    }
    return 0 ;
}

int GetItem(int position)
{
    if(position<0 || position>=length) return NULL_VALUE;
    struct listNode *temp;
    int count=0;
    temp=list;
    while(count<position)
    {
        temp=temp->next;
        count++;
    }
    return temp->item;
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


int deleteFirstOccurrence(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    length--;
    return SUCCESS_VALUE ;
}






int main()
{
    char inp1, chk;
    int inp2, pos;
    int s;
    initializeList();
    while(1){
        printf("what you want: ");
        scanf("%c",&inp1);


        switch(inp1)
        {
        case 'U':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;

        case 'P':
            scanf("%d",&inp2);
            s=insertItemLast(inp2);
            break;

        case 'I':
            scanf("%d %d",&inp2, &pos);
            s=insertItemAT(pos, inp2);
            break;

        case 'G':
            scanf("%d",&inp2);
            s=GetItem(inp2);
            printf("%d\n",s);
            break;

        case 'S':
            scanf("%d",&inp2);
            printf("Address: %d\n",searchItem(inp2));
            break;

        case 'R'://delete the item of first occurrence
            scanf("%d",&inp2);
            s=deleteFirstOccurrence(inp2);
            break;

        case 'E':
            PrintALL();
            break;

        case 'L':
            printf("Length: %d\n",length);
            break;
        }
        if(s==NULL_VALUE) break;
    }

}
