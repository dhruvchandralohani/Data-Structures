#include <iostream>
using namespace std;
struct stack1
{
	int *a1;
	int top1;
	stack1()
	{
		top1=-1;
	}
}s1;
void s1push(int x)
{
	s1.a1[s1.top1+1]=x;
	s1.top1++;
}
int s1pop()
{
	int x=s1.a1[s1.top1];
	s1.top1--;
	return x;
}
void display1()
{
	for(int i=0;i<=s1.top1;i++)
	cout<<s1.a1[i]<<" ";
}
struct node
{
	int val;
	node * next;
};
node * front=(node*)malloc(sizeof(node));
node * rear=(node*)malloc(sizeof(node));
node *temp=(node*)malloc(sizeof(node));
void enqueue(int x)
{
	node * p=(node*)malloc(sizeof(node));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(front==NULL && rear==NULL)
			front=p;
		else
			rear->next=p;
		rear=p;
	}
	else
	{
		cout<<"\nQueue Overflow.";
	}
}
bool stack_empty()
{
	if(s1.top1==-1)
	return true;
	else
	return false;
}
void exchange()
{
	while(!stack_empty())
	{
		int p;
		p=s1pop();
		enqueue(p);
	}
}
int main()
{
	int n,z;
	front=NULL;
	rear=NULL;
	cout<<"\nEnter the number of elements:";
	cin>>n;
	s1.a1=new int[n];
	cout<<"\nEnter Elements:";
	for(int i=0;i<n;i++)
	{
		cin>>z;
		s1push(z);
	}
	cout<<"\nBefore Reversing:"<<endl;
	display1();
	exchange();
	cout<<"\nAfter Reversing:"<<endl;
	temp=front;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
}
