#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	struct node * next;
	struct node * prev;
};
node * head=(node*)malloc(sizeof(node));
node * temp=(node*)malloc(sizeof(node));
node * tail=(node*)malloc(sizeof(node));
node * q=(node*)malloc(sizeof(node));
bool found=false;
int x,j;
void display()
{
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
}
bool search(int k)
{
	temp=head;
	q=head;
	if(temp->val!=k)
	{
		temp=temp->next;
	}
	while((temp!=NULL) && (!found))
	{
		if(temp->val==k)
		{
			found=true;
		}
		else
		{
			temp=temp->next;
			q=q->next;
		}
	}
	return found;
}
void add(int s)
{
	cout<<"\nEnter element after which you want to add:";
	cin>>j;
	if(j==x)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=tail->next;
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
	else
	{
		search(j);
		if(found==true)
		{
			node * p=(node*)malloc(sizeof(node));
			p->val=s;
			p->next=temp->next;
			temp->next=p;
			p->prev=temp;
			p->next->prev=p;
		}
		else
		{
			cout<<"\n\nElement is not in the list.";
		}
	}
}
int main()
{
	int y;
	cout<<"Number of elements you want to enter:";
	cin>>x;
	int ar[x];
	cout<<"\nEnter the elements:\n";
	for(int i=0;i<x;i++)
	{
		cin>>ar[i];
	}
	head=NULL;
	for(int i=0;i<x;i++)
	{
		node * e=(node*)malloc(sizeof(node));
		e->val=ar[i];
		e->next=NULL;
		e->prev=NULL;
		if(i==x-1)
		{
			tail=e;
		}
		if(head==NULL)
		{
			head=e;
		}
		else
		{
			temp->next=e;
			e->prev=temp;
		}
		temp=e;
	}
	display();
	cout<<"\n\nEnter the element which is to be added:";
	cin>>y;
	add(y);
	display();
	return 0;
}

