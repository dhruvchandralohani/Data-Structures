//Program to create CIRCULAR-QUEUE using ARRAY.
#include <iostream>
using namespace std;       
struct queue
{
	int * a=NULL;
	int front,rear;
	queue()
	{
		front=rear=-1;
	}
}q;
int n,choice;
void display()											//Function to DISPLAY all the ELEMENTS of the QUEUE.
{
	cout<<"\nCIRCULAR QUEUE is: ";
	if(q.rear>=q.front)
	{
		for(int i=q.front;i<=q.rear;i++)
		{
			cout<<q.a[i]<<" ";
		}
		cout<<"\n**********************************";
	}
	else
	{
		for(int i=q.front;i<n;i++)
		{
			cout<<q.a[i]<<" ";
		}
		for(int i=0;i<=q.rear;i++)
		{
			cout<<q.a[i]<<" ";
		}
		cout<<"\n**********************************";
	}
}
bool queue_empty()										//Function to check if QUEUE is EMPTY or NOT.
{
	if(q.front==-1 && q.rear==-1)
	return true;
	else
	return false;
}
bool queue_full()											//Function to check if QUEUE is FULL or NOT.
{
	if(q.front==0 && q.rear==n-1)
	return true;
	else
	return false;
}
void add(int x)											//Function to ADD ELEMENT in QUEUE.
{
	if((q.front==0 && q.rear==n-1) || (q.front==q.rear+1))
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE Overflow.";
		cout<<"\n**********************************";
	}
	else if(q.rear==-1)
	{
		q.front++;
		q.rear++;
		q.a[q.rear]=x;
	}
	else if(q.rear==n-1 && q.front>0)
	{
		q.rear=0;
		q.a[q.rear]=x;
	}
	else
	{
		q.rear++;
		q.a[q.rear]=x;
	}
}
int del()												//Function to REMOVE ELEMENT from QUEUE.
{
	int x=q.a[q.front];
	q.a[q.front]=-1;
	if(q.front==q.rear)
	{
		q.front=-1;
		q.rear=-1;
	}
	else
	{
		q.front++;
	}
	cout<<"\n"<<x<<" Is REMOVED.";
	return x;
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
	int l;
	cout<<"\nEnter the size of the QUEUE:";
	cin>>n;
	q.a=new int[n];
	do
	{
		show_choices();
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					if(!queue_full())
					{
						cout<<"\nEnter the value:";
						cin>>l;
						add(l);
						cout<<"\n\n**********************************";
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nQUEUE is FULL. Cannot enter more.";
						cout<<"\n**********************************";
					}
					break;
			case 2:
					if(!queue_empty())
					{
						del();
						cout<<"\n**********************************";
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nQUEUE is EMPTY. Nothing to REMOVE";
						cout<<"\n**********************************";
					}
					break;
			case 3:
					if(!queue_empty())
					{
						cout<<"\n**********************************";
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nQUEUE is EMPTY.";
						cout<<"\n**********************************";
					}
					break;
			case 4:
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nINVALID INPUT.";
					cout<<"\n**********************************";
		}
	}while(choice!=4);
	return 0;
}
