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
struct stack2
{
	int *a2;
	int top2;
	stack2()
	{
		top2=-1;
	}
}s2;
void s2push(int x)
{
	s2.a2[s2.top2+1]=x;
	s2.top2++;
}
int s2pop()
{
	int x=s2.a2[s2.top2];
	s2.top2--;
	return x;
}
void display2()
{
	for(int i=0;i<=s2.top2;i++)
	cout<<s2.a2[i]<<" ";
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
		s2push(p);
	}
}
int main()
{
	int n,z;
	cout<<"\nEnter the number of elements:";
	cin>>n;
	s1.a1=new int[n];
	s2.a2=new int[n];
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
	display2();
}
