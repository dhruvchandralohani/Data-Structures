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
node * temp5;
node * temp6;
bool del=false,del1=false,del2=false;
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
		cout<<"\nNew_Node->value: "<<temp2->info<<"		";
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
void inorder(node * temp3)
{
	if(temp3==NULL)
	return;
	else
	{
		inorder(temp3->left);
		cout<<temp3->info<<" ";
		inorder(temp3->right);
	}
}
void delnode1(node * temp3,int val)
{
	if(temp3==NULL)
	return;
	else
	{
		delnode1(temp3->left,val);
		if(del==true)
		{
			temp3->left=NULL;
			temp3->right=NULL;
		}
		del=false;
		if(temp3->info==val)
		{
			del=true;
			free(temp3);
		}
		delnode1(temp3->right,val);
	}
}
void delnode2(node * temp3,int val)
{
	if(temp3==NULL)
	return;
	else
	{
		delnode2(temp3->left,val);
		if(del1==true)
		{
			if(temp3->info > temp5->info)
				temp3->left=temp5;
			else if(temp3->info < temp5->info)
				temp3->right=temp5;
		}
		del1=false;
		if(del2==true)
		{
			if(temp3->info > temp6->info)
				temp3->left=temp6;
			else if(temp3->info < temp6->info)
				temp3->right=temp6;
		}
		del2=false;
		if(temp3->info==val)
		{
			if(temp3->left==NULL && temp3->right!=NULL)
			{
				del1=true;
				temp5=temp3->right;
				free(temp3);
			}
			else if(temp3->left!=NULL && temp3->right==NULL)
			{
				del2=true;
				temp6=temp3->left;
				free(temp3);
			}
		}
		delnode2(temp3->right,val);
	}
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
	temp1=root;
	for(int i=0;i<n;i++)
	{
		root=insert(root,ar[i]);
	}
	cout<<endl;
	cout<<"\nINORDER:";
	inorder(root);
	//cout<<"\nAfter Deletion1.";
	//delnode1(root,4);
	//cout<<"\nINORDER:";
	//inorder(root);
	cout<<"\nAfter Deletion1.";
	delnode1(root,20);
	cout<<"\nINORDER:";
	inorder(root);
	cout<<"\nAfter Deletion2.";
	delnode2(root,11);
	cout<<"\nINORDER:";
	inorder(root);
	//cout<<"\nAfter Deletion2.";
	//delnode2(root,31);
	//cout<<"\nINORDER:";
	//inorder(root);
	return 0;
}
