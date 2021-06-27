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
node * tail=(node*)malloc(sizeof(node));
node * q=(node*)malloc(sizeof(node));
bool found=false;
int j,count=1;
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
bool search_nth(int cc)
{
	temp=head;
	q=head;
	if(temp->val!=cc)
	{
		temp=temp->next;
	}
	while((temp!=NULL) && (!found))
	{
		if(count==cc)
		{
			found=true;
		}
		else
		{
			temp=temp->next;
			q=q->next;
			++count;
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
		head=p;
	}
	else
	{
		search_nth(j);
		if(found==true)
		{
			node * p=(node*)malloc(sizeof(node));
			p->val=s;
			p->next=NULL;
			q->next=p;
			p->next=temp;
		}
		else
		{
			cout<<"\n\nCannot enter at "<<j<<".";
		}
	}
}
int main()
{
	int x,y;
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
