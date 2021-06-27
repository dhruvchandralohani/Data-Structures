//Program to perform various operationn on Doubly Linked List.
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
int x,j,count=1,count1=1;
void display()									//Function to display all the nodes.
{
	cout<<"\nThe List is: ";
	temp=head;
	while(temp!=NULL && temp!=tail->next)
	{
		cout<<(temp->val)<<" ";
		temp=temp->next;
	}
	cout<<"\n In Reverse: ";
	temp=tail;
	while(temp!=NULL && temp!=head->prev)
	{
		cout<<(temp->val)<<" ";
		temp=temp->prev;
	}
}
bool search(int k)								//Function to find the location of the element.
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
bool search_specific(int k, int j)					//Function to find the location of the element
{												//specified between two adjacent nodes.
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
bool search_nth(int cc)							//Function to find the location of the element
{												//present at (n)th location.
	found=false;
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
			++count;
			temp=temp->next;
		}
	}
	return found;
}
bool search_nthrev(int cc)							//Function to find the location of the element
{												//present at (n)th location(reverse).
	found=false;
	temp=tail;
	cc=cc-1;
	while((temp!=NULL) && (!found))
	{
		if(count1==cc)
		{
			found=true;
		}
		else
		{
			++count1;
			temp=temp->prev;
		}
	}
	return found;
}
void del(int s)									//Function to delete an element.
{
	search(s);
	if(found==true)
	{
		if(head->val==s)
		{
			x--;
			head=temp->next;
			free(temp);
		}
		else if(tail->val==s)
		{
			x--;
			tail=temp->prev;
			free(temp);
		}
		else
		{
			x--;
			q->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}
	else
	{
		cout<<"\nElement "<<s<<" is not in the list.";
	}
}
void add_head(int s)								//Function to add element at head.
{
	x++;
	node * p=(node*)malloc(sizeof(node));
	p->val=s;
	p->next=head;
	head->prev=p;
	head=p;
}
void add_tail(int s)								//Function to add element at tail.
{
	x++;
	node * p=(node*)malloc(sizeof(node));
	p->val=s;
	p->next=tail->next;
	tail->next=p;
	p->prev=tail;
	tail=p;
}
void add(int s)									//Function to add after an element.
{
	cout<<"\nEnter element after which you want to add:";
	cin>>j;
	if(j==tail->val)
	{
		x++;
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
			x++;
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
void add_before(int s)							//Function to add before an element.
{
	cout<<"\nEnter element before which you want to add:";
	cin>>j;
	if(j==head->val)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=head;
		head->prev=p;
		head=p;
	}
	else
	{
		search(j);
		if(found==true)
		{
			x++;
			node * p=(node*)malloc(sizeof(node));
			p->val=s;
			p->next=q->next;
			q->next=p;
			p->prev=q;
			p->next->prev=p;
		}
		else
		{
			cout<<"\n\nElement is not in the list.";
		}
	}
}
void add_specific(int s , int a)						//Function to add an element between specified nodes.
{
	cout<<"\nEnter element which you want to add:";
	cin>>j;
	search_specific(s,a);
	if(found==true)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=j;
		p->next=temp->next;
		temp->next=p;
		p->prev=temp;
		p->next->prev=p;
	}
	else
	{
		cout<<"\n\nCannot be added. Please enter adjacent values.";
	}
}
void add_nth(int s)								//Function to add an element at (n)th position.
{
	cout<<"\nEnter the position at which you want to add:";
	cin>>j;
	if(j==1)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=head;
		head->prev=p;
		head=p;
	}
	else if(j==x+1)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
	else if(j>x+1)
	{
		cout<<"\n\nInvalid Input.\n";
		return;
	}
	else
	{
		search_nth(j);
		if(found==true)
		{
			x++;
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
void add_nthrev(int s)							//Function to add an element at (n)th position(reverse).
{
	cout<<"\nEnter the position at which you want to add:";
	cin>>j;
	if(j==1)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		p->next=head;
		head->prev=p;
		head=p;
	}
	else if(j==x+1)
	{
		x++;
		node * p=(node*)malloc(sizeof(node));
		p->val=s;
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
	else if(j>x+1)
	{
		cout<<"\n\nInvalid Input.\n";
		return;
	}
	else
	{
		search_nthrev(j);
		if(found==true)
		{
			x++;
			node * p=(node*)malloc(sizeof(node));
			p->val=s;
			p->prev=temp->prev;
			temp->prev=p;
			p->next=temp;
			p->prev->next=p;
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
	cout<<"\n7 . Add at Nth place(reverse).";
	cout<<"\n8 . Delete a node.";
	cout<<"\n9 . EXIT.";
	cout<<"\n\nEnter your choice:";
}
int main()
{
	int y,p,q,r,s,t,u,v,w,choice;
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
					cout<<"\n\nEnter first element(node):";
					cin>>q;
					cout<<"\n\nEnter second element(node):";
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
					cout<<"\n\nEnter the element which is to be added:";
					cin>>w;
					add_nthrev(w);
					display();
					break;
			case 8:
					cout<<"\n\nEnter the element which you want to delete.";
					cin>>t;
					del(t);
					cout<<"\n\nAfter deleting first "<<t;
					display();
					break;
			case 9:
					break;
			default:
					cout<<"\n\nInvalid Input"<<endl;
		}
	}while(choice!=9);
	return 0;
}
