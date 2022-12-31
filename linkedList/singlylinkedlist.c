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



void insertEnd(node *header,int item)
{
    node *ptr, *new;
    new=(node *)malloc(sizeof(node));
    ptr=(node *)malloc(sizeof(node));
    ptr=header;
    while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
    new->data=item;
    new->link=ptr->link;
    ptr->link=new;
}

//insertion at end is possible with key but not at front

void insert(node *header,int item,int key)
{   
    int count=0;
    node *ptr, *new;
    new=(node *)malloc(sizeof(node));
    ptr=(node *)malloc(sizeof(node));
    ptr=header->link;
    count++;
    while(ptr!=NULL&&count!=key-1)
       {    
          ptr=ptr->link; 
          count++;
       } 
    new->data=item;
    new->link=ptr->link;
    ptr->link=new;

    
}
void deleteFront(node *header)
{
    node *ptr;
    ptr=header->link;
    if(ptr==NULL)
        printf("List is Empty\n");
    else
        header->link=ptr->link;
}

void deleteEnd(node *header)
{
    node *ptr, *ptr1;
    ptr=header->link;
    ptr1=header;
    if(ptr==NULL)
        printf("List is Empty\n");
    else{
        while(ptr->link!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->link;
            }
        ptr1->link=NULL;
    }
}

//deletion at end is possible with key buut not at front

void delete(node *header,int key)
{
    int count=0;
    node *ptr, *ptr1;
    ptr=header->link;
    count++;
    if(ptr==NULL)
        printf("List is Empty\n");
    else{
        while(ptr->link!=NULL&&count!=key)
        {
            count++;
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=ptr->link;
    }
}

int main()
{   
    int c,item,key;
    char a;
    node *header;
    header=(node *)malloc(sizeof(node));
    header->link=NULL;

    printf("Operations--\n1.Insert at Beginning\n2.Insert at End\n3.Insert at a specified position\n4.Delete from a specified position\n5.Delete from beginning\n6.Delete from End\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insertFront(header,item);
                    display(header);
                    break;
            case 2: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    insertEnd(header,item);
                    display(header);
                    break;
            case 3: printf("Enter the item to insert: ");
                    scanf("%d",&item);
                    printf("Enter the position to insert: ");
                    scanf("%d",&key);
                    insert(header,item,key);
                    display(header);
                    break;
            case 4: printf("Enter the position to delete: ");
                    scanf("%d",&key);
                    delete(header,key);
                    display(header);
                    break;
            case 5: deleteFront(header);
                    display(header);
                    break;  
            case 6: deleteEnd(header);
                    display(header);
                    break;
        }
        printf("Do you want to continue: ");
        scanf(" %c",&a);

    }while(a=='y'||a=='Y');
        
}
