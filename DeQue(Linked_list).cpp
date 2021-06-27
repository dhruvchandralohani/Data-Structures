//Program to create DEQUE using Linked-List/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct deque
{
	int val;
	struct deque * next;
};
deque * front=(deque*)malloc(sizeof(deque));
deque * rear=(deque*)malloc(sizeof(deque));
deque * temp=(deque*)malloc(sizeof(deque));
int n;
void display()											//Function to DISPLAY all the ELEMENTS of the QUEUE.
{
	if(front!=NULL)
	{
		cout<<"\nQUEUE is ";
		temp=front;
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<"\n**********************************";
	}
	else
	{
		cout<<"\nQUEUE is EMPTY.";
		cout<<"\n**********************************";
	}
}
bool queue_empty()										//Function to check if QUEUE is EMPTY or NOT.
{
	if(front==NULL && rear==NULL)
	return true;
	else
	return false;
}
void add_rear(int x)										//Function to ADD ELEMENT in QUEUE at REAR.
{
	deque * p=(deque*)malloc(sizeof(deque));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(front==NULL && rear==NULL)
		{
			front=p;
			rear=p;
		}
		else
		{
			rear->next=p;
		}
		rear=p;
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE Overflow.";
		cout<<"\n**********************************";
	}
}
void add_front(int x)										//Function to ADD ELEMENT in QUEUE at FRONT.
{
	deque * p=(deque*)malloc(sizeof(deque));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(front==NULL && rear==NULL)
		{
			front=p;
			rear=p;
		}
		else
		{
			p->next=front;
		}
		front=p;
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE Overflow.";
		cout<<"\n**********************************";
	}
}
void del_front()											//Function to REMOVE ELEMENT from QUEUE from FRONT.
{
	if(!queue_empty())
	{
		if(front!=rear)
		{
			temp=front;
			int x=front->val;
			front=temp->next;
			free(temp);
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
			cout<<"\n**********************************";
		}
		else
		{
			int x=front->val;
			front=NULL;
			rear=NULL;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
			cout<<"\n**********************************";
			cout<<"\nQUEUE is EMPTY.";
			cout<<"\n**********************************";
		}
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE is EMPTY.";
		cout<<"\n**********************************";
	}
}
void del_rear()											//Function to REMOVE ELEMENT from QUEUE from REAR.
{
	if(!queue_empty())
	{
		if(front!=rear)
		{
			temp=front;
			while(temp->next->next!=NULL)
				temp=temp->next;
			int x=rear->val;
			free(temp->next);
			temp->next=NULL;
			rear=temp;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
			cout<<"\n**********************************";
		}
		else
		{
			int x=front->val;
			front=NULL;
			rear=NULL;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
			cout<<"\n**********************************";
			cout<<"\nQUEUE is EMPTY.";
			cout<<"\n**********************************";
		}
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE is EMPTY.";
		cout<<"\n**********************************";
	}
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . ADD into QUEUE at FRONT.";
	cout<<"\n2 . ADD into QUEUE at REAR.";
	cout<<"\n3 . DELETE from QUEUE from FRONT.";
	cout<<"\n4 . DELETE from QUEUE from REAR.";
	cout<<"\n5 . DISPLAY QUEUE.";
	cout<<"\n6 . EXIT.";
	cout<<"\n\nEnter your choice:";
}
int main()
{
	int choice,z;
	cout<<"\nEnter the size of QUEUE:";
	cin>>n;
	int * ar=new int[n];
	cout<<"\nEnter the values in QUEUE:";
	front=NULL;
	rear=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		add_rear(ar[i]);
	}
	cout<<"\n**********************************";
	display();
	do
	{
		show_choices();
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\nEnter the element to ADD at FRONT.";
					cin>>z;
					add_front(z);
					cout<<"\n**********************************";
					display();
					break;
			case 2:
					cout<<"\nEnter the element to ADD at REAR.";
					cin>>z;
					add_rear(z);
					cout<<"\n**********************************";
					display();
					break;
			case 3:
					del_front();
					break;
			case 4:
					del_rear();
					break;
			case 5:
					cout<<"\n**********************************";
					display();
					break;
			case 6:
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nInvalid Input";
					cout<<"\n**********************************";
		}
	}while(choice!=6);
	return 0;
}
