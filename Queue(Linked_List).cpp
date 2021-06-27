//Program to create QUEUE using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct queue
{
	int val;
	struct queue * next;
};
queue * front=(queue*)malloc(sizeof(queue));
queue * rear=(queue*)malloc(sizeof(queue));
queue * temp=(queue*)malloc(sizeof(queue));
int n;
void display()												//Function to DISPLAY all the ELEMENTS of the QUEUE.
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
bool queue_empty()											//Function to check if QUEUE is EMPTY or NOT.
{
	if(front==NULL && rear==NULL)
	return true;
	else
	return false;
}
void add(int x)												//Function to ADD ELEMENT in QUEUE.
{
	queue * p=(queue*)malloc(sizeof(queue));
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
void del()													//Function to REMOVE ELEMENT from QUEUE.
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
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . ADD into QUEUE.";
	cout<<"\n2 . DELETE from QUEUE.";
	cout<<"\n . DISPLAY QUEUE.";
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
		add(ar[i]);
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
					cout<<"\nEnter the element to PUSH into QUEUE.";
					cin>>z;
					add(z);
					cout<<"\n**********************************";
					display();
					break;
			case 2:
					del();
					break;
			case 3:
					cout<<"\n**********************************";
					display();
					break;
			case 4:
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nInvalid Input";
					cout<<"\n**********************************";
		}
	}while(choice!=4);
	return 0;
}
