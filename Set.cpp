#include <iostream>
#include <set>
#include <unordered_set>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	unordered_set<int> AU;
	set <int,greater<int> > AG;
	char ch='Y';
	int x,choice,ele,pwrsetsize,indicator ,yes;
	while ((ch=='Y' || (ch=='y')))
	{
		cout<<"Enter element of the set (only integers):\t";
		cin>>x;
		AU.insert(x);
		AG.insert(x);
		cout<<"More? <Y/N>: ";
		cin>>ch;

	}
	unordered_set <int>::iterator itru;
	set <int,greater<int> >::iterator itrg;
	cout<<"The Set AU is:";
	for (itru=AU.begin();itru!=AU.end(); ++itru)
	{
			cout<<"\t"<<*itru;
	}
	cout<<'\n';
	cout<<"The Set AG is:";
	for (itrg=AG.begin();itrg!=AG.end(); ++itrg)
	{
			cout<<"\t"<<*itrg;
	}

	cout<<"\nCardinality of the set: "<<AU.size()<<"\n";
	cout<<"\n----------------------------\n";
	while (choice!=3)
	{
		cout<<"\n1.Test membership\n";
		cout<<"2. show Powerset \n";
		cout<<"3.Quit \t\t\n";
		cin>>choice;
		switch (choice)
		{
			case 1:cout<<"Element?\t";
					cin>>ele;
					itru=AU.find(ele);
					if (itru==AU.end())
						cout<<ele<<"is not a member of set.\n";
					else
						cout<<ele<<"is a member of the set.\n";
					break;
			case 2:cout<<"Powerset is a member of the set. \n";
					pwrsetsize=pow(2,AU.size());
					for (int k = 0; k <pwrsetsize ; k++)
					{
						cout<<"{";
						indicator=k;
						itru=AU.begin();
						while (indicator>0)
						{
							yes=indicator%2;
							if (yes==1)
								if (indicator>2)
									cout<<*itru<<",";
								else
									cout<<*itru;
								indicator=indicator/2;
								advance(itru,1);
						}
						if(k<pwrsetsize-1)
							cout<<"}";
						else
							cout<<"}";
					}
					cout<<"}\n";
						break;
			case 3: break;
			default:;
		}
	}
	return 1;
}
