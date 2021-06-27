#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	struct node * next;
};
int main()
{
	bool found=false;
	int x,y;
	cout<<"Number of elements you want to enter:";
	cin>>x;
	int ar[x];
	cout<<"Enter the elements:-\n";
	for(int i=0;i<x;i++)
	{
		cin>>ar[i];
	}
	node * head=(node*)malloc(sizeof(node));
	node * temp=(node*)malloc(sizeof(node));
	node * q =(node*)malloc(sizeof(node));
	head=NULL;
	for(int i=0;i<x;i++)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=ar[i];
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			temp->next=p;
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
	cout<<"\n\nEnter the element to be deleted:";
	cin>>y;
	temp=head;
	q=head;
	if(temp->val!=y)
	{
		temp=temp->next;
	}
	while((temp!=NULL)&&(!found))
	{
		if(temp->val==y)
		{
			found=true;
		}
		else
		{
			temp=temp->next;
			q=q->next;
		}
	}
	if(found==true)
	{
		if(head->val==y)
		{
			head=temp->next;;
			free(temp);
		}
		else
		{
			q->next=temp->next;
			free(temp);
		}
	}
	else
	{
		cout<<"\nElement "<<y<<" is not in the list.";
	}
	cout<<"\n\nThe new List is: ";
	temp=head;
	while(temp!=NULL)
	{
		cout<<(temp->val)<<" ";
		temp=temp->next;
	}
	return 0;
}
