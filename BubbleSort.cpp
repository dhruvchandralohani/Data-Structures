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
static void bubblesort(int a[],int n)
{
	int temp=0,c_count=0;
	for (int i = 0; i <n-1 ; i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			c_count++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				show(a,n);
			}
			else
			{
				cout<<"NO SWAPPING-";
				show(a,n);
			}
		}
	}
	cout<<"\nTotal comparisons: "<<c_count;
}
int main()
{
	int a[]={1,6,4,5,7,3};
	bubblesort(a,6);
	return 0;
}
