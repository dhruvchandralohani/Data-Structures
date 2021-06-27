#include <iostream>
#define MAX 5
using namespace std;
class relation
{
	private:
	int a[MAX][MAX];
	int n;
	public:
	bool s = true;
	relation(int b[MAX][MAX],int c)
	{
		for (int i = 0; i <c ; i++)
		{
			for (int j = 0; j <c ; j++)
			{
				a[i][j]=b[i][j];
			}
			cout<<endl;
		}
		n=c;
	}
	bool reflexive()
	{
		for (int i = 0; i <n ; i++)
		{
			for (int j = 0; j <n ; j++)
			{
				if(a[i][i]!=1)
					s=false;
			}
		}
		return s;
	}
	bool symmetric()
	{
		for (int i = 0; i <n ; i++)
		{
			for (int j = 0; j <n ; j++)
			{
				if(i==j) continue;
				if (a[i][j]!=a[j][i])
					s=false;
			}
		}
		return s;
	}
	bool antisymmetric()
	{
		for (int i = 0; i <n ; i++)
		{
			for (int j = 0; j <n ; j++)
			{
				if(i==j) continue;
				
				if (((a[i][j])==1 )& ((a[i][i])==1))
				{	if(a[j][i]==0)
						s=true;
				}
				else if (((a[i][j])==0) & ((a[i][i])==1))
				{
					if(a[j][i]==1)
						s=true;
				}
				else
					s=true;
			}
		}
		return s;
	}
	bool transitive()
	{
		s=false;
		for (int i = 0; i <n ; i++)
		{
			for (int j = 0; j <n ; j++)
			{

				if((a[i][j]==1) & (i!=j))
				{
					for (int k = 0; k <n ; k++)
					{
						if((j,i)==(i,j)) continue;
						if((j,k)==(j,i)) continue;
						if((j,k)==(j,j)) continue;
						if(a[j][k]==1)0
						{
							if(a[i][j]*a[j][k]==a[i][k])
							s=true;
						}
					}
				}
			}
		}
		return s;
	}
};
int main()
{
	int n;
	cout<<"Enter dimension for square matrix:";
	cin>>n;
	int b[MAX][MAX];
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j <n ; j++)
		{
			cin>>b[i][j];
		}
	}
	relation r(b,n);
	if(r.reflexive() & r.symmetric() & r.transitive())
	{
		cout<<"a) The Given Relation is Equivalent";
	}
	else if(r.reflexive() & r.antisymmetric() & r.transitive())
	{
		cout<<"\nb) The Given Relation is a Partial Order relation";
	}
	else
		cout<<"\nc) None";
	return 0;
}
