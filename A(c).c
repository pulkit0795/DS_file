//Ques1- Write a C program that uses functions to perform the following:
//(c)Display the contents of the above list after deletion.
//created by **Pulkit Goyal(IT)(11912066)**

#include <stdio.h>
#include <stdlib.h>

void createnode(int );
void deleteatbegin();
void deleteatlast();
void deleteinbetween();
void transverselist();

struct node
{
	int data;
	struct node*link;
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
	head->link = NULL;

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
		Newnode->link=NULL;
		temp->link=Newnode;
		temp=temp->link;
	}
	printf("List created successfully\n");
}

void deleteatbegin()
{
	 head=head->link;
}

void deleteatlast()
{
	struct node *temp=head;
	while(temp->link->link != NULL)
	{
		temp=temp->link;
	}
	free(temp->link);
	temp->link=NULL;
}

void deleteinbetween()
{
	int n;
	struct node *temp=head;
	printf("Enter the position to delete\n");
	scanf("%d",&n);
	while(temp->link->data != n)
	{
		temp=temp->link;
	}
	struct node *temp1=temp;
	temp->link = temp->link->link;
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
		temp=temp->link;	
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
