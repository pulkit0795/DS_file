//Ques-F- Write a C program to calculate:
//(a) Number of nodes in a binary tree.
//created by **Pulkit Goyal(IT)(11912066)**

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
} node;

int t=0;

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

void countnode(struct node *root)
{
    if(root==0)
    {
        return;
    }
    countnode(root->left);
    t++;
    countnode(root->right);
}

int main()
{
	node* root;
	root=createnode();
	countnode(root);
	printf("Total node: %d\n",t );
	
	return 0;
}
