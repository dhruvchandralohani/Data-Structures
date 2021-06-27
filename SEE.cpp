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
	while((temp!=NULL)&&(!found))
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
void del(int s)
{
	search(s);
	if(found==true)
	{
		if(head->val==s)
		{
			head=temp->next;
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
		cout<<"\nElement "<<s<<" is not in the list.";
	}
}
int main()
{
	int x,y;
	cout<<"Number of elements you want to enter:";
	cin>>x;
	int ar[x];
	cout<<"Enter the elements:-\n";
	for(int i=0;i<x;i++)
	{
		cin>>ar[i];
	}
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
	display();
	cout<<"\n\nEnter the element to be deleted:";
	cin>>y;
	del(y);
	display();
	return 0;
}
