//Ques-E-Write a program that uses functions to perform the following:
//(b) Traverse the Binary search tree recursively in Postorder, inorder and Preorder.
//created by **Pulkit Goyal(IT)(11912066)**

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
} node;

node* createnode();
void traverse_inorder (node*);
void traverse_preorder (node*);
void traverse_postorder (node* );


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

void traverse_inorder (node *temp)
{
	if(temp!=NULL)
	{
		traverse_inorder(temp->left);
		printf("%c ",temp->data);
		traverse_inorder(temp->right);
	}
	else
		return;
}

void traverse_preorder (node *temp)
{
	if(temp!=NULL)
	{
		printf("%c ",temp->data );
		traverse_preorder(temp->left);
		traverse_preorder(temp->right);
	}
	else
		return;
}

void traverse_postorder (node* temp)
{
	if(temp!=NULL)
	{
		traverse_postorder(temp->left);
		traverse_postorder(temp->right);
		printf("%c ",temp->data );
	}
	else
		return;
}

int main()
{
	node* root;
	root=createnode();
	printf("\nInorder tranversalis:\n");
	traverse_inorder(root);
	printf("\npreorder tranversalis:\n");
	traverse_preorder(root);
	printf("\nPostorder tranversalis:\n");
	traverse_postorder(root);

	return 0;
}