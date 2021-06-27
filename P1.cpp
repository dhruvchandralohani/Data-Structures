#include <iostream>
using namespace std;
template <class T>
class search
{
	public:
		T val;
		search<T> *next;
};
search<int> * head=(search<int>*)malloc(sizeof(search<int>));
search<int> * temp=(search<int>*)malloc(sizeof(search<int>));
bool Lfound,Bfound;
int n;
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
void show_choices()
{
	cout<<"\n\nMENU";
	cout<<"\n1 . Linear Search.";
	cout<<"\n2 . Binary Search.";
	cout<<"\n\nEnter your choice:";
}
template <class T> void create(T x)
{
	search<int> * p=(search<int>*)malloc(sizeof(search<int>));
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
template <class T> void lsearch(T data)
{
	temp=head;
	Lfound=false;
	while(temp!=NULL && !(Lfound))
	{
		if(temp->val==data)
		{
			cout<<"\n"<<data<<" is in the List.";
			Lfound=true;
		}
		else
			temp=temp->next;
	}
}
template <class T> void bsearch(T data,int n)
{
	int lb,ub,mid;
	Bfound=false;
	for (int i = 0; i <n ; i++)
	{
		lb=i;
		ub=n-1;
		mid=(lb+ub)/2;
		if(traverse(mid)==data)
		{
			Bfound=true;
			cout<<"\nKey found at index: "<<mid+1;
			break;
		}
		else if(traverse(mid)>data)
		{
			ub=mid;
		}
		else
			lb=mid;
	}	
	if(!Bfound)
		cout<<"\nKey not found";
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
				cout<<"\nEnter the element which is to be searched:";
				cin>>z;
				lsearch(z);
				break;
			case 2:
				cout<<"\nEnter the element which is to be searched:";
				cin>>z;
				temp=head;
				bsearch(z,n);
				break;
			case 3:
				break;
		}
	}while(choice!=3);
	return 0;
}
