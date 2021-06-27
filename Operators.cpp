#include <iostream>
using namespace std;
int main()
{
	bool x,y;
		cout<<"__________________________________________"<<endl<<endl;
		cout<<"Enter truth values of x and y: ";
		cin>>x>>y;
		cout<<"Conjunction = "<<(x&y)<<"\n";
		cout<<"Disjunction = "<<(x|y)<<"\n";
		cout<<"Exclusive OR = "<<(x^y)<<"\n";
		cout<<"Conditional = ";
			if(x==1&&y==0)
				cout<<0<<"\n";
			else
				cout<<1<<"\n";
		cout<<"Bi-Condtional = "<<(!(x^y))<<"\n";
		cout<<"Exclusive NOR = "<<(!(x^y))<<"\n";
		cout<<"Negation of x = "<<(!x)<<endl;
		cout<<"Negation of y = "<<(!y)<<"\n";
		cout<<"NAND = "<<(!(x&y))<<"\n";
		cout<<"NOR = "<<(!(x|y))<<"\n";
		cout<<endl<<endl<<"__________________________________________"<<endl<<endl;
}
