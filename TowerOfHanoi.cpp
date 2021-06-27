#include <iostream>
using namespace std;
int step=0;
void toh(int n,char src,char aux,char des)
{
	if(n==1)
	{
		step++;
		cout<<step<<". Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
		return;
	}
	toh(n-1,src,des,aux);
	step++;
	cout<<step<<". Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
	toh(n-1,aux,src,des);
}
int main()
{
	int n;
	cout<<"Enter no. of disks: ";
	cin>>n;
	toh(n,'A','B','C');
	return 0;
}

