//hash table using chaining method and linear probing

#include<stdio.h>
#include<stdlib.h>
int size=10;
int b[10];
typedef struct list{
    int data;
    struct list *link;
}node;
node *a[30];

void chain(int key)
{
    int k=key%size;
    node *new, *ptr;
    new=(node *)malloc(sizeof(node));
    new->data=key;
    new->link=NULL;
    ptr=a[k];
    if(a[k]==NULL)
    {
        a[k]=new;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}


void display_chain()
{   
    int i;
    node *ptr;
    for(i=0;i<size;i++)
    {   
         ptr=a[i];
         printf("%d : ",i);
         while(ptr!=NULL)
        {   
             printf("%d\t",ptr->data);
             ptr=ptr->link;
        }
        printf("\n");
    }
}

void linear_prob(int key)
{
    int k=key%size,i,flag=0;
    if(b[k]==-1)
        b[k]=key;
    else{
         for(i=k+1;i<size;i++)
            {
                if(b[i]==-1)
                    { 
                        b[i]=key;
                        flag=1;
                        break;
                    }
                
            }
        if(flag==0)
        {   for(i=0;i<k;i++)
                if(b[i]==-1)
                    { 
                        b[i]=key;
                        break;
                    }

        }
    }

}
void display_lp()
{
    int i;

    for(i=0;i<size;i++)
    {   
        if(b[i]==-1)
            printf("%d : \n",i);
         else printf("%d : %d\n",i,b[i]);

    }
}


int main()
{
    int i,n,key;
    for(i=0;i<size;i++)
        b[i]=-1;
    printf("Enter the no. of values:  ");
    scanf("%d", &n);
    
    for(i=0;i<n;i++)
        { 
           printf("Enter the values:  ");
           scanf("%d", &key);
           chain(key);
           linear_prob(key);
        }
    
    printf("\nChaining method--\n");
    display_chain();
    printf("\nLinear Probing-- \n");
    display_lp();
}
