//Ques-F- Write a C program to calculate:
//(a) Number of Leaf and non-Leaf in a binary tree.
//created by **Pulkit Goyal(IT)(11912066)**

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
} node;

int x=0,y=0;

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


void countnodes(struct node *root)
{
    if(root==0)
        return;
    countnodes(root->left);
    countnodes(root->right);
    if(root->left==0&&root->right==0)
    {
        x++;
    }
    else
    {
        y++;
    }
}


int main()
{
	node* root;
	root=createnode();
	countnodes(root);
	printf("Total no. of Leaf nodes: %d\nTotal no. of non-Leaf nodes: %d\n",x,y );
	
	return 0;
}