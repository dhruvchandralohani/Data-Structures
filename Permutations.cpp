#include <iostream>
#include <string>
using namespace std;
void rep(int* ar)
{
	for (int i = 0; i <3 ; i++)
	{
		for (int j= 0; j <3 ; j++)
		{
			for (int k = 0; k <3 ; k++)
			{
				if((ar[i]==ar[j]) | (ar[i]==ar[k]) | (ar[k]==ar[j])) continue;
				cout<<ar[i]<<","<<ar[j]<<","<<ar[k];
				cout<<endl;
			}
		}
	}
}
void norep(int* ar)
{
	for (int i = 0; i <3 ; i++)
	{
		for (int j= 0; j <3 ; j++)
		{
			for (int k = 0; k <3 ; k++)
			{
				cout<<ar[i]<<","<<ar[j]<<","<<ar[k];
				cout<<endl;
			}
		}
	}
}

int main()
{
	int ar[]={1,2,3};
	cout<<"With Repetitions\n\n";
	norep(ar);
	cout<<"\n";
	cout<<"Without Repetitions\n\n";
	rep(ar);
	return 0;
}

