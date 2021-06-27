//Program to create CIRCULAR-QUEUE using LINKED-LIST.
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
void display()												//Function to DISPLAY all the ELEMENTS of the QUEUE.
{
	if(front!=NULL)
	{
		cout<<"\n**********************************";
		cout<<"\nCIRCULAR QUEUE is:";
		temp=front;
		while(temp!=rear)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<rear->val<<" ";
		cout<<"\n**********************************";
	}
	else
	{
		cout<<"\n**********************************";
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
		rear->next=front;
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
	if(front!=rear)
	{
		temp=front;
		int x=front->val;
		front=temp->next;
		free(temp);
		rear->next=front;
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
	}
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . ADD into QUEUE.";
	cout<<"\n2 . DELETE from QUEUE.";
	cout<<"\n3 . DISPLAY QUEUE.";
	cout<<"\n4 . EXIT.";
	cout<<"\n\nEnter your choice:";
}
int main()
{
	int n,choice,z;
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
					display();
					break;
			case 2:
					if(!queue_empty())
					{
						del();
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nQUEUE is EMPTY.";
						cout<<"\n**********************************";
					}
					break;
			case 3:
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
