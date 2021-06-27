//Program to create STACK using ARRAY.
#include <iostream>
using namespace std;
struct stack
{
	int * a = NULL;
	int top=-1;
}s;
int n=0,choice;
bool stack_empty()									//Function to check if STACK is EMPTY or NOT.
{
	if(s.top==-1)
	return true;
	else
	return false;
}
bool stack_full()										//Function to check if STACK is FULL or NOT.
{
	if(s.top==(n-1))
	return true;
	else
	return false;
}
void push(int x)										//Function to PUSH values into STACK.
{
		s.a[s.top+1]=x;
		s.top++;
}
int pop()											//Function to POP values from STACK.
{
	int x;
	n--;
	x=s.a[s.top];
	s.top--;
	cout<<"\n**********************************";
	cout<<"\n"<<x<<" Is Popped."<<endl;
	cout<<"\n**********************************";
	return x;
}
void display()										//Function to DISPLAY all the ELEMENTS of STACK.
{
	for(int i=0;i<=s.top;i++)
	cout<<s.a[i]<<" ";
	cout<<"\n**********************************";
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . PUSH into STACK.";
	cout<<"\n2 . POP from STACK.";
	cout<<"\n3 . EXIT.";
	cout<<"\n\nEnter your choice:";
}
int main()
{
	int p;
	cout<<"\nEnter the size of the stack:";
	cin>>n;
	s.a=new int[n];
	do
	{
		show_choices();
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					if(!stack_full())
					{
						cout<<"\nEnter the value to PUSH into STACK.";
						cin>>p;
						push(p);
						cout<<"\n**********************************";
						cout<<"\nThe STACK is:";
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nStack is FULL. Cannot enter more.";
						cout<<"\n**********************************";
					}
					break;
			case 2:
					if(!stack_empty())
					{
						pop();
						cout<<"\n**********************************";
						cout<<"\nThe STACK is:";
						display();
					}
					else
					{
						cout<<"\n**********************************";
						cout<<"\nStack is EMPTY. Nothing to POP";
						cout<<"\n**********************************";
					}
					break;
			case 3:
					break;
			default:
					cout<<"\n**********************************";
					cout<<"\nInvalid Input.";
					cout<<"\n**********************************";
		}
	}while(choice!=3);
	return 0;
}
