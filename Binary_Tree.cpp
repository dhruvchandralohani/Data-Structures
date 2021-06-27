//Program to create a TREE using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int info;
	struct node * left;
	struct node * right;
	struct node * thread;
};
node * root=(node*)malloc(sizeof(node));
node * temp1;
node * temp4;
node * newnode(int val)
{
	cout<<"\nNODE CREATED.";
	node * p=(node*)malloc(sizeof(node));
	p->info=val;
	p->left=NULL;
	p->right=NULL;
	return p;
}
node * insert(node * temp2,int data)
{
	if(temp2==NULL)
	{
		temp2=newnode(data);
		cout<<"\nNew_Node->value"<<temp2->info<<"		";
	}
	else if(data < temp2->info)
	{
		cout<<"\nMOVING IN LEFT.";
		temp2->left=insert(temp2->left,data);
	}
	else if(data > temp2->info)
	{
		cout<<"\nMOVING IN RIGHT.";
		temp2->right=insert(temp2->right,data);
	}
	return temp2;
}
void preorder(node *temp3)
{
	if(temp3==NULL)
	return;
	cout<<temp3->info<<" ";
	preorder(temp3->left);
	preorder(temp3->right);
}
void inorder(node * temp3)
{
	if(temp3==NULL)
	return;
	else
	{
		inorder(temp3->left);
		if(temp4==NULL)
		{
			temp4=temp3;
			cout<<temp4->info<<" ";
			cout<<"FIRST NODE , ";
		}
		else
		{
			temp3->thread=temp4;
			cout<<temp3->info;
			cout<<" PREVIOUS: "<<temp4->info<<" , ";
			temp4=temp3;
			inorder(temp3->right);
		}
	}
}
void postorder(node * temp3)
{
	if(temp3==NULL)
	return;
	postorder(temp3->left);
	postorder(temp3->right);
	cout<<temp3->info<<" ";
}
int main()
{
	int n;
	cout<<"\nEnter Number of NODES:";
	cin>>n;
	int * ar=new int[n];
	cout<<"\nEnter NODES:";
	for(int i=0;i<n;i++)
		cin>>ar[i];
	root=NULL;
	for(int i=0;i<n;i++)
	{
		root=insert(root,ar[i]);
	}
	cout<<endl;
	cout<<"\nPRE-ORDER:";
	preorder(root);
	cout<<"\nINORDER:";
	inorder(root);
	cout<<"\nPOST-ORDER:";
	postorder(root);
	return 0;
}
