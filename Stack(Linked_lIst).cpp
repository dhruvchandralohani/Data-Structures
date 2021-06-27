//Program to create STACK using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack
{
	int val;
	struct stack *next;
};
stack * head=(stack*)malloc(sizeof(stack));
stack * temp=(stack*)malloc(sizeof(stack));
stack * top=(stack*)malloc(sizeof(stack));
int y;
void display()												//Function to DISPLAY all the ELEMENTS of STACK.
{
	if(head!=NULL)
	{
		cout<<"\nSTACK is:";
		temp=head;
		while(temp!=NULL)
		{
			cout<<(temp->val)<<" ";
			temp=temp->next;
		}
		cout<<"\n**********************************";
		temp=head;
	}
	else
	{
		cout<<"\nSTACK is EMPTY.";
		cout<<"\n**********************************";
	}
}
bool stack_empty()											//Function to check if STACK is EMPTY or NOT.
{
	if(head==NULL && top==NULL)
	return true;
	else
	return false;
}
void push(int x)												//Function to PUSH values into STACK.
{
	stack * p=(stack*)malloc(sizeof(stack));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(top==NULL)
		{
			head=p;
		}
		else
		{
			top->next=p;
		}
		top=p;
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nSTACK Overflow.";
		cout<<"\n**********************************";
	}
}
void pop()													//Function to POP values from STACK.
{
	if(!stack_empty())
	{
		if(head!=top)
		{
			temp=head;
			while(temp->next->next!=NULL)
				temp=temp->next;
			int x=temp->next->val;
			free(temp->next);
			temp->next=NULL;
			top=temp;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is Popped.";
			cout<<"\n**********************************";
		}
		else
		{
			int x=head->val;
			head=NULL;
			top=NULL;
			cout<<"\n**********************************";
			cout<<"\n"<<x<<" Is Popped.";
			cout<<"\n**********************************";
			cout<<"\nSTACK is EMPTY.";
			cout<<"\n**********************************";
		}
	}
	else
	{
		cout<<"\n**********************************";
		cout<<"\nSTACK is EMPTY.";
		cout<<"\n**********************************";
	}
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . PUSH";
	cout<<"\n2 . POP";
	cout<<"\n3 . DISPLAY STACK";
	cout<<"\n4 . EXIT";
	cout<<"\n\nEnter choice:";
}
int main()
{
	int choice,z;
	cout<<"\nEnter the size of STACK:";
	cin>>y;
	int * ar=new int[y];
	cout<<"\nEnter the values in STACK:";
	head=NULL;
	top=NULL;
	for(int i=0;i<y;i++)
	{
		cin>>ar[i];
		push(ar[i]);
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
					cout<<"\nEnter the element to PUSH into STACK.";
					cin>>z;
					push(z);
					cout<<"\n**********************************";
					display();
					break;
			case 2:
					pop();
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
