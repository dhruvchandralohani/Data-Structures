#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	struct node * next;
};
node * head=(node*)malloc(sizeof(node));
node * temp=(node*)malloc(sizeof(node));
node * q=(node*)malloc(sizeof(node));
bool found=false;
int j;
void display()
{
	cout<<"\nThe List is: ";
	temp=head;
	while(temp!=NULL)
	{
		cout<<(temp->val)<<" ";
		temp=temp->next;
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
void add_before(int s)
{
	cout<<"\nEnter element before which you want to add:";
	cin>>j;
	search(j);
	if(found==true)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=NULL;
		if(temp==head && q==head)
		{
			p->next=temp;
			head=p;
		}
		else
		{
			q->next=p;
			p->next=temp;
		}
	}
	else
	{
		cout<<"\n\nElement is not in the list.";
	}
}
int main()
{
	int x,y;
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
		if(head==NULL)
		{
			head=e;
		}
		else
		{
			temp->next=e;
		}
		temp=e;
	}
	display();
	cout<<"\n\nEnter the element which is to be added:";
	cin>>y;
	add_before(y);
	display();
	return 0;
}

