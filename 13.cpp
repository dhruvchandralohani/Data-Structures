#include <iostream>
using namespace std;
int main()
{
	int c;
	char ch='y';
	bool x,y;
	
	while(ch=='y'||ch=='Y')
	{
		cout<<"__________________________________________"<<endl<<endl;
		cout<<"Enter truth values of x and y: ";
		cin>>x>>y;
		
		cout<<"1:Conjunction"<<endl<<"2:Disjunction"<<endl<<"3:Exclusive OR"<<endl<<"4:Conditional"<<endl<<"5:Bi-Conditional"<<endl<<"6:Exclusive NOR"<<endl<<"7:Negation"<<endl<<"8:NAND"<<endl<<"9:NOR"<<endl;
		cout<<"Enter your choice of operation: ";
		cin>>c;
		
		switch(c)
		{
			case 1:	cout<<"Conjunction = "<<(x&y);
					break;
					
			case 2:	cout<<"Disjunction = "<<(x|y);
					break;
					
			case 3:	cout<<"Exclusive OR = "<<(x^y);
					break;
					
			case 4:	cout<<"Conditional = ";	
					if(x==1&&y==0)
						cout<<0;
					else
						cout<<1;
					break;
					
			case 5:	cout<<"Bi-Condtional = "<<(!(x^y));
					break;
					
			case 6:	cout<<"Exclusive NOR = "<<(!(x^y));
					break;
					
			case 7:	cout<<"Negation of x = "<<(!x)<<endl;
					cout<<"Negation of y = "<<(!y);
					break;
					
			case 8:	cout<<"NAND = "<<(!(x&y));
					break;
					
			case 9:	cout<<"NOR = "<<(!(x|y));
					break;
					
			default: cout<<"Wrong input."<<endl;
		}
		
		cout<<endl<<endl<<"__________________________________________"<<endl<<endl;
		cout<<"Continue? (y/n): ";
		cin>>ch;
	}
}
