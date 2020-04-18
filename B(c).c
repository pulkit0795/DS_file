//Ques2- Write a C program that uses functions to perform the following:
//(c)Display the contents of the above list after deletion.
//created by **Pulkit Goyal(IT)(11912066)**

#include <stdio.h>
#include <stdlib.h>

void createnode(int );
void deleteatbegin();
void transverselist();

struct node
{
	int data;
	struct node*prev;
	struct node*next;
}*head;

void createnode(int n)
{
	int data;
	struct node *temp;
	head=(struct node*)malloc(sizeof(struct node));

	if(head==NULL)
	{
		printf("Memory not allocated");
		return;
	}

	printf("Enter first node data\n");
	scanf("%d",&data);
	temp=head;
	head->data = data;
	head->prev = NULL;
	head->next = NULL;

	for(int i=2;i<=n;i++)
	{
		struct node *Newnode=(struct node*)malloc(sizeof(struct node));

		if(Newnode==NULL)
		{
			printf("Memory not allocated");
			break;
		}
		printf("Enter node data\n");
		scanf("%d",&data);
		Newnode->data=data;
		Newnode->next=NULL;
		Newnode->prev=temp;
		temp->next=Newnode;
		temp=temp->next;
	}
	printf("List created successfully\n");
}

void deleteinbetween()
{
	int n;
	struct node *temp=head;
	printf("Enter the data to delete\n");
	scanf("%d",&n);
	while(temp->next->data != n)
	{
		temp=temp->next;
	}
	struct node *temp1=temp;
	temp->next = temp->next->next;
	temp->next->prev=temp;
	free(temp1);
	temp1=NULL;
}

void transverselist()
{
	struct node *temp=head;
	int i=1;
	while(temp)
	{
		printf("Printing %d element of Linked List %d\n",i,temp->data);
		i++;
		temp=temp->next;	
	}
}


int main()
{
	int n;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	createnode(n);
	deleteinbetween();
	transverselist();

	return 0;
}
