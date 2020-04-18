//Ques-E-Write a program that uses functions to perform the following:
//(a) Create a Binary Search Tree of characters.
//created by **Pulkit Goyal(IT)(11912066)**

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
} node;

node* createnode()
{
	char data;
	node *temp;
	temp=(node*)malloc(sizeof(node));

	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}

	printf("Enter data(-1 for no node):\n");
	scanf("%c",&data);

	if(data==-1)
		return NULL;

	temp->data=data;
	printf("Enter left child of %c:\n",data );
	temp->left=createnode();
	printf("Enter right child of %c:\n",data );
	temp->right=createnode();

	return temp;

}


int main()
{
	node* root;
	root=createnode();
	
	return 0;
}