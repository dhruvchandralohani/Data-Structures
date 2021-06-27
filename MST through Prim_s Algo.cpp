#include <iostream>
using namespace std;
class graph
{
	public:
	int G[20][20],n,e;
	void accept();
	void  prims();
	void display();

};
void graph :: accept()
{
	int src,dest,cost;
	cout<<"\nEnter the total no of vertices and edges:=";
	cin>>n>>e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j]=0;
		}
	}
	for(int i=0 ; i<e ; i++)
	{
		cout<<"\nEnteer src dest and cost = ";
		cin>>src>>dest>>cost;
		G[src][dest] = cost;
		G[dest][src]= cost;
	}
}
void graph :: display()
{
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n ;j++)
		{
			cout<<"\t"<<G[i][j];
		}
	}  
	
}
void graph :: prims()
{
	int src,dest;
	int total=0;
	int visited[20];	
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n ; j++)
		{
			if(G[i][j]==0)
			   G[i][j]= 9999;
		}
	}
	
	for(int i =0; i<n;i++)
	{
		visited[i]=0;
	}
	
	
	cout<<"\nEnter the src for finding minimum spanning tree :=";
	cin>>src;
	
	
	visited[src]=1;
	e=0;
	while(e<n-1)
	{
		int min=9999;
		for(int i =0;i<n;i++)
		{
			if(visited[i]==1)
			{
		  		for(int j=0;j<n;j++)
				{
					if(visited[j]!=1)
					{	
						if(min>G[i][j])
						{
							min = G[i][j];
							src=i;
							dest=j;
						}
					}
				}
		 
			}
		}
	visited[dest]=1;
	total=total+G[src][dest];
	cout<<"Edge = "<<src<<".........."<<dest<<"cost:="<<min<<"\n";
	e++;
	}
cout<<"Total cost of minimum spanning tree:="<<total;
}

int main()
{
	graph g;
	g.accept();
	g.display();
	g.prims();
	return 0;
}
