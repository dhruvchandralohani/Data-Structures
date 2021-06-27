#include <iostream>
using namespace std;
int n,m;
template <class T>
class List1
{
	public:
		T val;
		List1<T> * next;
		void operator +(List1<int> *head2)
		{
			while(next!=NULL)
				next=next->next;
			next->next=head2;
		}
};
List1<int> * head1=(List1<int>*)malloc(sizeof(List1<int>));
List1<int> * temp1=(List1<int>*)malloc(sizeof(List1<int>));
List1<int> * head2=(List1<int>*)malloc(sizeof(List1<int>));
List1<int> * temp2=(List1<int>*)malloc(sizeof(List1<int>));

void display1()
{
	cout<<"\nThe List is: ";
	temp1=head1;
	while(temp1!=NULL)
	{
		cout<<(temp1->val)<<" ";
		temp1=temp1->next;
	}
}
void display2()
{
	cout<<"\nThe List is: ";
	temp2=head2;
	while(temp2!=NULL)
	{
		cout<<(temp2->val)<<" ";
		temp2=temp2->next;
	}
}
template <class T> void create1(T x)
{
	List1<int> * p=(List1<int>*)malloc(sizeof(List1<int>));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(head1==NULL)
		{
			head1=p;
		}
		else
			temp1->next=p;
		temp1=p;
	}
}
template <class T> void create2(T x)
{
	List1<int> * p=(List1<int>*)malloc(sizeof(List1<int>));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(head2==NULL)
		{
			head2=p;
		}
		else
			temp2->next=p;
		temp2=p;
	}
}

int main()
{
	cout<<"Enter the size of the List1:";
	cin>>n;
	int *ar1=new int[n];
	cout<<"\nEnter the List:";
	head1=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>ar1[i];
		create1(ar1[i]);
	}
	cout<<"\n\nEnter the size of the List2:";
	cin>>m;
	int *ar2=new int[m];
	cout<<"\nEnter the List:";
	head2=NULL;
	for(int i=0;i<m;i++)
	{
		cin>>ar2[i];
		create2(ar2[i]);
	}
	display1();
	cout<<endl;
	display2();
	head1+head2;
	display1();
}
