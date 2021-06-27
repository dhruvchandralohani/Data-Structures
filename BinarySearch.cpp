#include <iostream>
using namespace std;
void bsearch(int a[],int key,int n)
{
	int lb,ub,mid;
	bool found=false;
	for (int i = 0; i <n ; i++)
	{
		lb=i;
		ub=n-1;
		mid=(lb+ub)/2;
		if(a[mid]>key)
		{
			ub=mid;
		}
		else if(a[mid]==key)
		{
			found=true;
			cout<<"The key is found at index: "<<mid+1;
			break;
		}
		else
			lb=mid;
	}	
	if(!found)
		cout<<"The key is not present in the list";
}
int bsearch2(int a[],int lb,int ub,int key)
{
	static int mid;
	mid=lb+ub/2;
	if(a[lb]==key)
		return lb;
	else if(a[ub]==key)
		return ub;
	else if(a[mid]>key)
		return bsearch2(a,lb,mid,key);
	else 
		return bsearch2(a,mid,ub,key);
}
 
int main()
{
	int a[]={1,2,3,4,5,6,7};
	bsearch(a,7,7);
	cout<<"\nThe key is found at position: "<<bsearch2(a,0,6,7)+1<<"th (Recursion)";
	return 0;
}
