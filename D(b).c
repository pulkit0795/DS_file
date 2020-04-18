//Ques-D-Write C programs to implement a double ended queue ADT using
//(b) Doubly Linked list.
//created by **Pulkit Goyal(IT)(11912066)**

#include<stdio.h>
#include<stdlib.h>

void display();
void dequeue();
void enque();

struct node
{
    int a;
    struct node *prev;
    struct node *next;
};

struct node *frontend=0,*rear=0,*temp;

void enque()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=0;
    printf("enter data : ");
    scanf("%d",&newnode->a);
    if(rear==0)
    {
        frontend=newnode;
        newnode->prev=0;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}

void dequeue()
{
    if(frontend==0&&rear==0)
    {
        printf("queue is empty\n");
    }
    else if(frontend==rear)
    {
        frontend=rear=0;
    }
    else
    {
        temp=frontend;
        frontend=frontend->next;
        frontend->prev=0;
        free(temp);
    }
}

void display()
{
    temp=frontend;
    while(temp!=0)
    {
        printf("%d ",temp->a);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int n,choice=1;
    while(choice)
    {
       printf("enter 1-enqueue 2-dequeue 3-display : ");
       scanf("%d",&n);
       switch(n)
       {
       case 1:
           enque();
           break;
       case 2:
        dequeue();
        break;
       case 3:
        display();
        break;
       }
       printf("enter 1 to cont.  : ");
       scanf("%d",&choice);
    }
}