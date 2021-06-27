#include <iostream>
using namespace std;
int fibbonaci(int n)
{
    if(n==1||n==2)
    return 1;
    else
    return (fibbonaci(n-1)+fibbonaci(n-2));
}
int main()
{
    int i=1;
    while(i<=5)
    {
    cout<<fibbonaci(i)<<" ";
    i++;
    }
    return 0;
}
