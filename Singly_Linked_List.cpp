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
}
bool search(int k)
{
	found=false;
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
bool search_specific(int k, int j)
{
	found=false;
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
bool search_nth(int cc)
{
	found=false;
	temp=head;
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
void add_head(int s)
{
	node * p=(node*)malloc(sizeof(node));
	p->val=s;
	p->next=head;
	head=p;
}
void add_tail(int s)
{
	node * p=(node*)malloc(sizeof(node));
	p->val=s;
	tail->next=p;
	tail=p;
}
void add(int s)
{
	cout<<"\nEnter element after which you want to add:";
	cin>>j;
	search(j);
	if(found==true)
	{
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=temp->next;
		temp->next=p;
	}
	else
	{
		cout<<"\n\nElement is not in the list.";
	}
}
void add_before(int s)
{
	cout<<"\n\nEnter element before which you want to add:";
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
void add_specific(int s , int a)
{
	cout<<"\n\nEnter element which you want to add:";
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
void add_nth(int s)
{
	cout<<"\n\nEnter the position at which you want to add:";
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
			p->next=temp->next;
			temp->next=p;
		}
		else
		{
			cout<<"\n\nElement is not in the list.";
		}
	}
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . Add after a specified value.";
	cout<<"\n2 . Add before a specified value.";
	cout<<"\n3 . Add between specified nodes.";
	cout<<"\n4 . Add at head.";
	cout<<"\n5 . Add at tail.";
	cout<<"\n6 . Add at Nth place.";
	cout<<"\n7 . Delete a node.";
	cout<<"\n8 . EXIT.";
}
int main()
{
	int y,p,q,r,s,t,u,v,choice;
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
		}
		temp=e;
	}
	display();
	do
	{
		show_choices();
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\n\nEnter the element which is to be added:";
					cin>>y;
					add(y);
					display();
					break;
			case 2:
					cout<<"\n\nEnter the element which is to be added:";
					cin>>p;
					add_before(p);
					display();
					break;
			case 3:
					cout<<"\n\nEnter first element:";
					cin>>q;
					cout<<"\n\nEnter second element:";
					cin>>r;
					add_specific(q,r);
					display();
					break;
			case 4:
					cout<<"\n\nEnter the element which you want to add at head:";
					cin>>u;
					add_head(u);
					display();
					break;
			case 5:
					cout<<"\n\nEnter the element which you want to add at the tail:";
					cin>>v;
					add_tail(v);
					display();
					break;
			case 6:
					cout<<"\n\nEnter the element which is to be added:";
					cin>>s;
					add_nth(s);
					display();
					break;
			case 7:
					cout<<"\n\nEnter the element which you want to delete.";
					cin>>t;
					del(t);
					cout<<"\n\nAfter deleting first "<<t;
					display();
					break;
			case 8:
					break;
			default:
					cout<<"\n\nInvalid Input"<<endl;
		}
	}while(choice!=8);
	return 0;
}
