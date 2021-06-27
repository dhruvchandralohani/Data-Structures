#include <iostream>
#include <cmath>
using namespace std;
void f(int x)
{
	int n,sum=0;
	cout<<"Enter highest degree of polynomial function:";
	cin>>n;
	int f2[n],f3[n];
	cout<<"Enter coefficients of the function (from constant to highest power of function):"; 
	for (int i = 0; i <n ; i++)
	{
		cin>>f2[i];
	}
	cout<<"\n"<<"Given function is:";
	for (int i = 0; i <n; i++)
	{
		cout<<f2[n-1-i]<<"x^"<<n-1-i;
		if((n-1-i)!=0)
			cout<<"+";
		else continue;
	}
	for (int i = 0; i <n ; i++)
	{
		f3[i]=pow(x,i);
		sum+=f2[i]*f3[i];
	}
	cout<<"\nF("<<x<<"): "<<sum;
}
int main()
{
	f(3);
	return 0;
}
