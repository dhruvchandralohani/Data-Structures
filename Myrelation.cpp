#include <iostream>
#define MAX 5
using namespace std;
class relation
{
	private:
	int a[MAX][MAX]={{0,0}};
	int n;
	public:
	bool s=true;
	relation(int b[MAX][MAX] , int c)
	{
		n=c;
		for(int i=0 ; i< n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				a[i][j]=b[i][j];
			}
			cout<<endl;
		}
	}
	bool reflexive()
	{
		for(int i=0 ; i<n ;i++)
		{
			if(a[i][i]!=1)
			s=false;
		}
		return s;
	}
	bool symmetric()
	{
		s=false;
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				if(a[i][j]==a[i][i])continue;
				if ((a[i][j]==a[j][i]) && (a[i][j]==1) && (a[j][i]==1))
				s=true;
			}
		}
		return s;
	}
	bool antisymmetric()
	{
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				if(a[i][j]!=a[j][i])
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
						if(a[j][k]==1)
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
	cout<<"\nReflexive: "<<r.reflexive();
	cout<<"\nAntisymmetric: "<<r.antisymmetric();
	cout<<"\nSymmetric: "<<r.symmetric();
	cout<<"\nTransitive: "<<r.transitive();
	return 0;
}



