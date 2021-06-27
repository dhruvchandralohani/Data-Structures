#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct node
{
	char *name;
	int age;
	node(char *n , int a = 0)
	{
		name=strdup(n);
		age=a;
	}
	node(const node& n)
	{
		name=strdup(n.name);
		age=n.age;
	}
	node& operator=(const node& n)
	{
		if(this==&n)
		{
			if(name!=0)
			free(name);
			name=strdup(n.name);
			age=n.age;
		}
		return *this;
	}
};
int main()
{
	node node1("Roger" , 20);
	node node2(node1);
	node node3=node1;
	strcpy(node2.name,"WENDY");
	node2.age=30;
	cout<<node1.name<<"\n"<<node1.age<<"\n";
	cout<<node2.name<<"\n"<<node2.age<<"\n";
	cout<<node3.name<<"\n"<<node3.age;
	return 0;
}
