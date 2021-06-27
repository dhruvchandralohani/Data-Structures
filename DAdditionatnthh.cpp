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
bool found=false;
int x,j,count=1;
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
bool search_nth(int cc)
{
	temp=head;
	cc=cc-1;
	while((temp!=NULL) && (!found))
	{
		if(count==cc)
		{
			found=true;
		}
		else
		{
			temp=temp->next;
			count++;
		}
	}
	return found;
}
void add_nth(int s)
{
	cout<<"\nEnter the position at which you want to add:";
	cin>>j;
	if(j==1)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=head;
		head->prev=p;
		head=p;
	}
	else if(j==x-1)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=tail->next;
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
	else if(j>x)
	{
		cout<<"\n\nCannot enter at "<<j<<" position.";
		return;
	}
	else
	{
		search_nth(j);
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
	for(int i=1;i<=x;i++)
	{
		cin>>ar[i];
	}
	head=NULL;
	for(int i=1;i<=x;i++)
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
			e->prev=temp;
		}
		if(i==x)
		{
			tail=NULL;
			tail=e;
		}
		temp=e;
	}
	display();
	cout<<"\n\nEnter the element which is to be added:";
	cin>>y;
	add_nth(y);
	display();
	return 0;
}

