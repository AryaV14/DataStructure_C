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

void deleteEnd(node *header)
{
    node *ptr, *ptr1;
    ptr=header->link;
    ptr1=header;
    if(ptr==NULL)
        printf("Queue is Empty\n");
    else{
        while(ptr->link!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->link;
            }
        ptr1->link=NULL;
    }
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
    printf("Enter the max size of queue: ");
    scanf("%d", &key);
    printf("Operations--\n1.Insert elements to the queue.\n2.Delete elements from the queue.\n");
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
                    }else printf("Queue overflow\n");
                    break;
            case 2: deleteEnd(header);
                    display(header);
                    break;
            
                        
        }
        printf("Do you want to continue: ");
        scanf(" %c",&a);

    }while(a=='y'||a=='Y');
        
}
