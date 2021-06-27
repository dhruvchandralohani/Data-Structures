#include <iostream>
using namespace std;
float com(float n,float r)
{
	if (r==1)
		return n;
	else
		return (n/r)*com(n-1,r-1);
}

float per(float n,float r)
{
	if (r==1)
		return n;
	else
		return n*per(n-1,r-1);
}
int main()
{
	cout<<com(5,2)<<'\n';
	cout<<per(5,2);
	return 0;
}

