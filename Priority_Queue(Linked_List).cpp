//Program to create PRIORITY-QUEUE using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct pqueue
{
	int val,priority;
	struct pqueue * next;
};
pqueue * front=(pqueue*)malloc(sizeof(pqueue));
pqueue * rear=(pqueue*)malloc(sizeof(pqueue));
pqueue * temp=(pqueue*)malloc(sizeof(pqueue));
pqueue * q=(pqueue*)malloc(sizeof(pqueue));
int n;
void display()								//Function to DISPLAY all the ELEMENTS of the QUEUE.
{
	if(front!=NULL)
	{
		cout<<"\nQUEUE is ";
		temp=front;
		while(temp!=NULL)
		{
			cout<<"\nVALUE:"<<temp->val<<"    "<<"PRIORITY:"<<temp->priority<<"\n";
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
bool queue_empty()							//Function to check if QUEUE is EMPTY or NOT.
{
	if(front==NULL && rear==NULL)
	return true;
	else
	return false;
}
void add(int x,int y)							//Function to ADD ELEMENT into QUEUE according to it's PRIORITY.
{
	pqueue * p=(pqueue*)malloc(sizeof(pqueue));
	p->val=x;
	p->priority=y;
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
			if(p->priority<front->priority)
			{
				p->next=front;
				front=p;
			}
			else if(p->priority>=rear->priority)
			{
				rear->next=p;
				rear=p;
			}
			else
			{
				temp=front;
				while(temp!=NULL)
				{
					if((p->priority>=temp->priority) && (p->priority<temp->next->priority))
					{
						p->next=temp->next;
						temp->next=p;
					}
					temp=temp->next;
				}
			}
		}
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nQUEUE Overflow.";
		cout<<"\n**********************************";
	}
}
void del()									//Function to REMOVE ELEMENT from QUEUE.
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
void del_priority(int y)						//Function to REMOVE ELEMENT from QUEUE according to it's PRIORITY.
{
	if(!queue_empty())
	{
		if(y==front->priority)
		{
			temp=front;
			int x=front->val;
			front=temp->next;
			free(temp);
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
			cout<<"\n**********************************";
		}
		else if(y==rear->priority)
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
			temp=front;
			q=front;
			if(temp->priority!=y)
			{
				temp=temp->next;
			}
			while(temp!=NULL)
			{
				if(temp->priority==y)
				{
					goto jump;
				}
				else
				{
					temp=temp->next;
					q=q->next;
				}
			}
			jump:
			int x=temp->val;
			q->next=temp->next;
			free(temp);
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is REMOVED.";
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
	cout<<"\n1 . ADD into QUEUE according to PRIORITY.";
	cout<<"\n2 . NORMAL DELETE(from FRONT).";
	cout<<"\n3 . DELETE from QUEUE according to PRIORITY";
	cout<<"\n4 . DISPLAY QUEUE.";
	cout<<"\n5 . EXIT.";
	cout<<"\n\nEnter your choice:";
}
int main()
{
	int choice,z,j,p;
	cout<<"\nEnter the size of QUEUE:";
	cin>>n;
	int * ar=new int[n];
	front=NULL;
	rear=NULL;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the "<<i+1<<" VALUE:";
		cin>>ar[i];
		cout<<"\nEnter it's PRIORITY:";
		cin>>j;
		add(ar[i],j);
		cout<<endl;
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
					cout<<"\nEnter it's PRIORITY.";
					cin>>p;
					add(z,p);
					cout<<"\n**********************************";
					display();
					break;
			case 2:
					del();
					break;
			case 3:
					cout<<"\nEnter PRIORITY.";
					cin>>p;
					del_priority(p);
					break;
			case 4:
					cout<<"\n**********************************";
					display();
					break;
			case 5:
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nInvalid Input";
					cout<<"\n**********************************";
		}
	}while(choice!=5);
	return 0;
}
