#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list *link;
}node;

void display(node *header)
{
    node *ptr;
    //ptr=(node *)malloc(sizeof(node));
    ptr=header->link;
    while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
}


void insertFront(node *header,int item)
{
    node *new;
    new=(node *)malloc(sizeof(node));
    new->link=header->link;
    header->link=new;
    new->data=item;
}

void deleteFront(node *header)
{
    node *ptr;
    ptr=header->link;
    if(ptr==NULL)
        printf("Stack underflow\n");
    else
        header->link=ptr->link;
}

int checksize(node *header)
{
    node *ptr;
    int count=0;
    ptr=header->link;
    while (ptr!=NULL)
    {
       count++;
       ptr=ptr->link;
    }
    return count;
    
}

int main()
{
    int c,item,key,n;
    char a;
    node *header;
    header=(node *)malloc(sizeof(node));
    header->link=NULL;
    printf("Enter the max size of stack: ");
    scanf("%d", &key);
    printf("Operations--\n1.Push elements to the stack.\n2.Pop elements from the stack.\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1: n=checksize(header);
                    if(n<key)
                    {
                        printf("Enter the item to insert: ");
                        scanf("%d",&item);
                        insertFront(header,item);
                        display(header);
                    }else printf("Stack overflow\n");
                    break;
            case 2: deleteFront(header);
                    display(header);
                    break;
            
                        
        }
        printf("Do you want to continue: ");
        scanf(" %c",&a);

    }while(a=='y'||a=='Y');
        
}
