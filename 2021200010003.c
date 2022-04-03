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
    struct listNode * newNode, *temp = list;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    newNode->item = item;
    newNode->next = NULL;

	if (temp == NULL) {
		list = newNode;
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
    }else if(position == length){
        insertItemLast(item);
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

int NumOfItems(int item){
    struct listNode *temp;
    int count = 0;
    temp = list ;
    while (temp != NULL)
    {
        if (temp->item == item){
            count++;
        }
        temp = temp->next ;
    }
    return count;
}

int deleteALLOccurrence(int item){
    struct listNode *temp = list, *prev;
    if(temp == NULL) return NULL_VALUE;

    while (temp != NULL && temp->item == item){
        list = temp->next; // Changed head
        free(temp); // free old head
        temp = list; // Change Temp
    }

    while (temp != NULL){
        while (temp != NULL && temp->item != item){
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return NULL_VALUE;
        prev->next = temp->next;
        free(temp); // Free memory
        temp = prev->next;
    }
    return SUCCESS_VALUE ;
}

int deleteLastOccurrence(int item){
    struct listNode * temp = list;
    if(temp == NULL) return NULL_VALUE;
    struct listNode * prev = NULL,* curr = NULL;

      while(temp){
        if(temp->next && temp->next->item == item){
          prev = temp;
          curr = temp->next;
        }
        temp = temp->next;
      }
      if(prev){
        prev->next = curr->next;
      }else if(temp->item == item){
        temp = temp->next;
      }
      length--;
      return SUCCESS_VALUE ;
}

int deleteFirstItem(){
    struct listNode *temp = list;
    if(temp = NULL){
        return NULL_VALUE;
    }
    list = list->next;
    free(temp);
    length--;
    return SUCCESS_VALUE;
}

int deletelastItem(){
    struct listNode *temp = list, *lastNode;
    if(temp == NULL){
        return NULL_VALUE;
    }
    if(temp->next == NULL){
        deleteFirstItem();
    }
    while(temp-> next->next != NULL){
        temp = temp->next;
    }
    lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
    length--;
    return SUCCESS_VALUE;
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

        case 'N':
            scanf("%d", &inp2);
            s=NumOfItems(inp2);
            printf("%d\n", s);
            break;

        case 'D':
            scanf("%d", &inp2);
            s=deleteALLOccurrence(inp2);
            break;

        case 'O':
            scanf("%d", &inp2);
            s=deleteLastOccurrence(inp2);
            break;

        case 'F':
            s=deleteFirstItem();
            break;

        case 'X':
            s=deletelastItem();
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
