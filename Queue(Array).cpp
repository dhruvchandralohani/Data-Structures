//Program to create QUEUE using ARRAY.
#include <iostream>
using namespace std;
struct queue
{
	int * a=NULL;
	int front,rear;
	queue()
	{
		front=rear=0;
	}
}q;
int n,choice;
void display()											//Function to DISPLAY all the ELEMENTS of the QUEUE.
{
	for(int i=q.front;i<q.rear;i++)
	cout<<q.a[i]<<" ";
	cout<<"\n**********************************";
}
bool queue_empty()										//Function to check if QUEUE is EMPTY or NOT.
{
	if(q.front-q.rear==0)
	return true;
	else
	return false;
}
bool queue_full()											//Function to check if QUEUE is FULL or NOT.
{
	if(q.rear==n)
	return true;
	else
	return false;
}
void add(int x)											//Function to ADD ELEMENT in QUEUE.
{
	if(!queue_full())
	{
		q.a[q.rear]=x;
		q.rear++;
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQueue Overflow";
		cout<<"\n**********************************";
	}
}
int del()												//Function to REMOVE ELEMENt from QUEUE.
{
	if(!queue_empty())
	{
		if(q.front==q.rear)
		{
			int x=q.a[q.front];
			q.front=q.rear=0;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED."<<endl;
			cout<<"\n**********************************";
			cout<<"\nQUEUE is EMPTY.";
			cout<<"\n**********************************";
			return x;
		}
		else
		{
			int x=q.a[q.front];
			q.front++;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED."<<endl;
			cout<<"\n**********************************";
			return x;
		}
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE is EMPTY.";
		cout<<"\n**********************************";
		return 0;
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
						cout<<"\n**********************************";
						cout<<"\nThe QUEUE is:";
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
						cout<<"\nThe QUEUE is:";
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
					cout<<"\n**********************************";
					display();
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nINVALID INPUT.";
					cout<<"\n**********************************";
		}
	}while(choice!=4);
	return 0;
}
