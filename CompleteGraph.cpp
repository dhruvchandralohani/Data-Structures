#include <iostream>
using namespace std;
#define MAX 10
int graph[MAX][MAX];
bool check(int graph[][MAX],int n , int m)
{
	bool iscomplete=true;
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j <m ; j++)
		{
			if (graph[i][j]!=1)
				iscomplete=false;
		}
	}
	return iscomplete;
}

int main()
{
	int x;
	cout<<"Enter no. of vertices:";
	cin>>x;
	cout<<"Enter elements of Adjacency Matrix row-wise: ";
	for (int i = 0; i <x ; i++)
	{
		for (int j = 0; j<x ; j++)
		{
			cin>>graph[i][j];
		}
		
	}
	if(check(graph,x,x))
		cout<<"It is a complete graph";
	else
	{
		cout<<"It is not a complete graph";
	}
	return 0;
}
