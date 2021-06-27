#include <iostream>
#define MAX 10
using namespace std;
int g[MAX][MAX];
int countpaths(int graph[][MAX] , int V , int u , int v , int k)
{
	if(k==0 && u==v)
		return 1;
	if(k==1 && graph[u][v])
		return 1;
	if(k<=0)
		return 0;
	int pcount=0;
	for(int i=0 ; i<V ; i++)
	if(graph[u][i] == 1)
		pcount=pcount+countpaths(graph , V , i , v , k-1);
	return pcount;
}
int main()
{
	int V , src , dest , k , choice;
	cout<<"Number of vertices (<="<<MAX<<" in Graph) = ";
	cin>>V;
	if(V<=MAX)
	{
		cout<<"Enter the Adjecency Matrix of the graph row-wise\n";
		for(int i=0 ; i<V ; i++)
			for(int j=0 ; j<V ; j++)
				cin>>g[i][j];
		while(1)
		{
			cout<<"\nSource vertex number.? ";
			cin>>src;
			cout<<"\nDestination vertex number.? ";
			cin>>dest;
			cout<<"\nPath length.? ";
			cin>>k;
			cout<<"\nNumber of paths of length "<<k<<countpaths(g,V,src,dest,k);
			cout<<"\nAnother?...or enter 'Q' to quit ";
			cin>>choice;
			if((choice=='Q') || (choice=='q'))
			break;
		}
	}
	else
		cout<<"The Graph is larger than expected\n";
	return 1;
}
