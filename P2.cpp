#include <iostream>
using namespace std;
template <class T>
class node
{
	public:
		T val;
		node<T> * next;
};
node<int> * head=(node<int>*)malloc(sizeof(node<int>));
node<int> * tail=(node<int>*)malloc(sizeof(node<int>));
node<int> * temp=(node<int>*)malloc(sizeof(node<int>));
node<int> * temp1=(node<int>*)malloc(sizeof(node<int>));
node<int> * q=(node<int>*)malloc(sizeof(node<int>));
bool found;
int n,j,x,store;
void display()
{
	cout<<"\nThe List is: ";
	temp=head;
	while(temp!=NULL)
	{
		cout<<(temp->val)<<" ";
		temp=temp->next;
	}
}
int traverse(int x)
{
	temp=head;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if(i==x)
			p=temp->val;
		else
			temp=temp->next;
	}
	return p;
}
template <class T>bool search(T data)
{
	found=false;
	q=head;
	temp=head;
	if(temp->val!=data)
		temp=temp->next;
	while((temp!=NULL) && (!found))
	{
		if(temp->val==data)
		{
			found=true;
		}
		else
		{
			temp=temp->next;
			q=q->next;
		}
	}
	return found;
}
template <class T>int del(T s)
{
	search(s);
	if(found==true)
	{
		if(head->val==s)
		{
			head=temp->next;
			store=temp->val;
			free(temp);
		}
		else
		{
			q->next=temp->next;
			store=temp->val;
			free(temp);
		}
	}
	else
		cout<<"\nElement "<<s<<" is not in the list.";
	return store;
}
template <class T>void add(T s)
{
	q=head;
	temp=head;
	temp=temp->next;
	if(s<head->val)
	{
		node<int> * p=(node<int>*)malloc(sizeof(node<int>));
		p->val=s;
		p->next=head;
		head=p;
	}
	else if(s>tail->val)
	{
		node<int> * p=(node<int>*)malloc(sizeof(node<int>));
		p->val=s;
		tail->next=p;
		tail=p;
	}
	else if(s>q->val && s<temp->val)
	{
		node<int> *p=(node<int>*)malloc(sizeof(node<int>));
		p->val=s;
		p->next=temp->next;
		q->next=p;
	}
	else
	{
		temp=temp->next;
		q=q->next;
	}
}
template <class T> void insort(T data)
{
	x=del(data);
	add(x);
}
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . Insertion Sort.";
	cout<<"\n2 . Bubble Sort.";
	cout<<"\n3 . Selection Sort.";
	cout<<"\n\nEnter your choice:";
}
template <class T> void create(T x)
{
	node<int> * p=(node<int>*)malloc(sizeof(node<int>));
	p->val=x;
	p->next=NULL;
	if(p!=NULL)
	{
		if(head==NULL)
		{
			head=p;
		}
		else
			temp->next=p;
		temp=p;
	}
}
int main()
{
	int z,choice;
	cout<<"Enter the size of the List:";
	cin>>n;
	int *ar=new int[n];
	cout<<"\nEnter the List:";
	head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		create(ar[i]);
	}
	do
	{
		show_choices();
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				temp1=head;
				temp1=temp1->next;
				while(temp1->next!=NULL)
				{
					insort(temp1->val);
					temp1=temp1->next;
				}
				display();
				break;
			case 2:
				cout<<"\nEnter the element which is to be searched:";
				cin>>z;
				temp=head;
				//bsearch(z,n);
				break;
			case 3:
				break;
		}
	}while(choice!=3);
	return 0;
}
