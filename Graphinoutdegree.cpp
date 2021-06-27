#include <iostream>
using namespace std;
#define MAX 10
int graph[MAX][MAX];
void degree(int graph[][MAX],int n,int m)
{
	int outd=0,ind=0;
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j <m ; j++)
		{
			if(graph[i][j]<0)
				ind++;
			else if(graph[i][j]==1)
				outd++;
		}
	}
	cout<<"in-degree: "<<ind<<"\nout-degree:"<<outd;
}
int main()
{
	int x;
	cout<<"Enter no. of vertices:";
	cin>>x;
	cout<<"Enter 1 for directed out arrow and -1 for directed in arrow row-wise: ";
	for (int i = 0; i <x ; i++)
	{
		for (int j = 0; j<x ; j++)
		{
			graph[i][j]=-1;
		}
		
	}
	degree(graph,x,x);
	return 0;
}
