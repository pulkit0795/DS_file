//Ques2- Write a C program that uses functions to perform the following:
//(a)Create a doubly linked list of integers.
//created by **Pulkit Goyal(IT)(11912066)**

#include <stdio.h>
#include <stdlib.h>

void createnode(int );

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

int main()
{
	int n;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	createnode(n);

	return 0;
}
