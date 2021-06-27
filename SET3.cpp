#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <bitset>
#define MAX 10
using namespace std;
void show(set<int> s)
{
	cout<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<'\t'; 
	}
	cout<<endl;
}
set<int> input(set<int> a)
{
	int x;
	char ch='Y';
	while((ch=='Y') | (ch=='y'))
	{
		cout<<"\nEnter element of set: ";
		cin>>x;
		a.insert(x);
		cout<<"\nMore? (Y/N):";
		cin>>ch;
	}
	return a;
}
string* binary(int n )
{
	string *s=new string[MAX];
	for (int i = 0; i <n ; i++)
	{
		string q;
		q=s[i];
		q=bitset<3>(i).to_string();
		s[i]=q;
	}
	return s;
}
void powerset(set<int> s)
{
	int l=s.size();
	int pwrsize=pow(2,s.size());
	string *p=(binary(pwrsize));
	for (int i = 0; i <pwrsize ; i++)
	{
		int k=0;
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
		{
			if((p[i][l-1-k++])=='1')
				cout<<*it;
		}
		cout<<endl;
	}
}
void membership(set<int> s)
{
	int t;
	cout<<"Enter the element to check it's membership:";
	cin>>t;
	set<int>::iterator it;
	it=s.find(t);
	if(it==s.end())
		cout<<"The element is not a member of the set";
	else
		cout<<"The element is a member of the set";
}
set<int> Union(set<int> s,set<int> s2)
{
	set<int> s3;
	set<int>::iterator it;
	set<int>::iterator it2;
	for (it=s.begin(); it!=s.end(); it++)
	{
		s3.insert(*it);
	}
	for (it2=s.begin(); it2!=s2.end(); it2++)
	{
		s3.insert(*it2);
	}
	return s3;
	
}
set<int> Intersection(set<int> s,set<int> s2)
{
	set<int> s3;
	set<int>::iterator it;
	set<int>::iterator it2=s2.begin();
	for (it=s.begin(); it!=s.end(); it++,it2++)
	{
		if(*it==*it2)
			s3.insert(*it);
	}
	return s3;
	
}
void Subset(set<int> s, set<int> s2)
{
	set<int>::iterator it=s.begin();
	set<int>::iterator it2=s2.begin();
	set<int>::iterator it3;
	
	if(s.size()>s2.size())
	{
		bool isSet=true;
		for (it2=s2.begin(); it2!=s2.end() ; it++,it2++)
		{
			it3=s.find(*it2);
			if(it3==s2.end())
				isSet=false;
		}
		if(isSet)
			cout<<"\nSecond set is a subset of First set";
	}
	else if(s.size()<s2.size())
	{
		bool isSet=true;
		for (it=s.begin(); it!=s.end() ; it++,it2++)
		{
			it3=s2.find(*it);
			if(it3==s2.end())
				isSet=false;
		}
		if(isSet)
			cout<<"\nFirst set is subset of Second set";
	}
	else if(s.size()==s2.size())
	{
		bool isSet=true;
		for (it=s.begin(); it!=s.end() ; it++,it2++)
		{
			if(*it!=*it2)
				isSet=false;
		}
		if(isSet)
			cout<<"\nBoth sets are Equal";
	}
}
set<int> Complement(set<int> s)
{
	set<int> d;
	set<int>:: iterator it2=d.begin();
	
	for (int i = 0; i <10 ; i++)
	{
		d.insert(i);
	}
	
	set<int>::iterator it;
	for (it=s.begin(); it !=s.end() ; it++,it2++)
	{
		if(*it==*it2)
			d.erase(*it);
	}
	return d;
}
set<int> Difference(set<int> s,set<int> s2)
{
	set<int> s3;
	set<int>::iterator it;
	set<int>::iterator it2=s2.begin();
	for (it=s.begin(); it!=s.end(); it++,it2++)
	{
		if(*it==*it2)
			s.erase(*it2);
	}
	return s;
}
set<int> SymmetricDiff(set<int> s,set<int> s2)
{
	return Union(Difference(s,s2),Difference(s2,s));
}

void CartesianP(set<int> s,set<int> s2)
{
	set<int>::iterator it;
	set<int>::iterator it2;
	for (it=s.begin(); it!=s.end(); it++)
	{
		for (it2=s2.begin(); it2!=s2.end(); it2++)
		{
			cout<<"("<<*it<<","<<*it2<<")";
		}
	}

}
int main()
{
	set<int> s, s2;
	cout<<"\nEnter Elements of the First set";
	s=input(s);
	show(s);
	cout<<"\nEnter ELements of the Second set";
	s2=input(s2);
	show(s2);
	CartesianP(s,s2);
}
