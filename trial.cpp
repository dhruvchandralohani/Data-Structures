#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	struct node * next;
	struct node * prev;
};
int main()
{
	node * head=(node*)malloc(sizeof(node));
	node * temp=(node*)malloc(sizeof(node));
	node * tail=(node*)malloc(sizeof(node));
	int x;
	cout<<"Number of elements you want to enter:";
	cin>>x;
	int ar[x];
	cout<<"Enter the elements:-\n";
	for(int i=0;i<x;i++)
	{
		cin>>ar[i];
	}
	head=NULL;
	for(int i=0 ; i<x ; i++)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=ar[i];
		p->next=NULL;
		p->prev=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			temp->next=p;
			p->prev=temp;
			if(i==x-1)
			{
				tail=p;
			}
		}
		temp=p;
	}
	cout<<"\nThe List is: ";
	temp=head;
	while(temp!=NULL)
	{
		cout<<(temp->val)<<" ";
		temp=temp->next;
	}
	cout<<"\n In Reverse: ";
	temp=tail;
	while(temp!=NULL)
	{
		cout<<(temp->val)<<" ";
		temp=temp->prev;
	}
	return 0;
}
