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
bool search_specific(int k, int j)
{
	temp=head;
	q=head;
	if((temp->val!=k) && (temp->next->val!=j))
	{
		temp=temp->next;
	}
	while((temp!=NULL) && (temp->next!=NULL) && (!found))
	{
		if((temp->val==k) && (temp->next->val==j))
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
void add_specific(int s , int a)
{
	cout<<"\nEnter element which you want to add:";
	cin>>j;
	search_specific(s,a);
	if(found==true)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=j;
		p->next=temp->next;
		temp->next=p;
	}
	else
	{
		cout<<"\n\nCannot be added.";
	}
}
int main()
{
	int x,y,z;
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
	cout<<"\n\nEnter element at specified place.";
	cout<<"\n\nEnter the first element:";
	cin>>y;
	cout<<"Enter the second element:";
	cin>>z;
	add_specific(y,z);
	display();
	return 0;
}
