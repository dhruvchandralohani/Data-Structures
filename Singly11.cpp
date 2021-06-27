#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int val;
	node *next;
};
int main()
{
	int a[5],i;
	cout<<"Enter the elements:"<<"\n";
	for(i=0;i<5;i++)
	cin>>a[i];
	node *head = (node*)malloc(sizeof(node));
	head->val=a[0];
	head->next=NULL;
	node *t = (node*)malloc(sizeof(node));
	t=head;
	i=1;
	while(i<5)
	{
		node *p = (node*)malloc(sizeof(node));
		p->val=a[i];
		p->next=NULL;
		t->next=p;
		t=p;
		++i;
	}
	t=head;
	while(t->next!=NULL)
	{
		cout<<"\n"<<(t->val)<<"\t";
		t=t->next;
	}
return 0;
}
