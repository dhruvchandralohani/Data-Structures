#include <iostream>
using namespace std;
static void show(int a[],int n)
{
	cout<<'{';
	for (int i = 0; i <6 ; i++)
	{
		cout<<a[i];
		if(i==n-1) continue;
		else
			cout<<',';
	}
	cout<<"}\n";
}
void insort(int a[],int n)
{
	for (int i = 1; i <n ; i++)
	{
		int temp=a[i];
		int j=i;
		while(j>0 && temp<a[j-1])
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;
		show(a,6);
	}
	
}
int main()
{
	int a[]={1,6,4,5,7,3};
	insort(a,6);
	return 0;
}
