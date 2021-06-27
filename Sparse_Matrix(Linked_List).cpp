//Program to create a SPARSE-MATRIX using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct smatrix
{
	int val;
	struct smatrix * right;
	struct smatrix * down;
};
smatrix * head=(smatrix*)malloc(sizeof(smatrix));
smatrix * temp1;
smatrix * temp2;
int b,c,i,j,k,l,m,n,w,x,p,count=0;
int main()
{
	cout<<"\nEnter the NUMBER of ROWS of MATRIX:";
	cin>>w;
	cout<<"\nEnter the NUMBER of COLUMNS of MATRIX:";
	cin>>x;
	int ar[w][x];
	cout<<"\nEnter the elements:";
	for(b=0;b<w;b++)
	{
		for(c=0;c<x;c++)
		{
			cin>>ar[b][c];
			if(ar[b][c]!=0)
			{
				count++;
			}
		}
	}
	head->val=count;
	temp1=head;
	temp2=head;
	for(i=0;i<w;i++)
	{
		for(j=0;j<x;j++)
		{
			if(ar[i][j]!=0)
			{
				if(temp1==head)
				{
					cout<<"\nROW HEADER IS CREATED. i="<<i;
					smatrix * p=(smatrix*)malloc(sizeof(smatrix));
					p->right=NULL;
					p->down=NULL;
					p->val=i;
					temp1->down=p;
					temp1=p;
					if(temp2==head)
					{
						cout<<"\nCOLUMN HEADER IS CREATED. j="<<j;
						smatrix * q=(smatrix*)malloc(sizeof(smatrix));
						q->right=NULL;
						q->down=NULL;
						q->val=j;
						temp2->right=q;
						temp2=q;
					}
				}
				else
				{
					cout<<"\n(ELSE PART)FOR i="<<i;
					cout<<"\n(ELSE PART)FOR j="<<j;
					temp1=head;
					temp1=temp1->down;
					while(temp1!=NULL)
					{
						cout<<"\nWHILE(temp1!=NULL)FOR i="<<i;
						cout<<"\nWHILE(temp1!=NULL)FOR j="<<j;
						if(i==temp1->val)
						{
							cout<<"\nIF(i==temp1->val)FOR i="<<i;
							cout<<"\nIF(i==temp1->val)FOR j="<<j;
							temp2=head;
							temp2=temp2->right;
							while(temp2!=NULL)
							{
								if(j==temp2->val)
								{
									cout<<"\nJUMPED.";
									cout<<"\ni="<<i;
									cout<<"\nj="<<j;
									goto label1;
								}
								else
								{
									temp2=temp2->right;
								}
							}
							cout<<"\nNEW COLUMN1. j="<<j;
							smatrix * r=(smatrix*)malloc(sizeof(smatrix));
							r->val=j;
							temp2=head;
							while(temp2->right!=NULL)
								temp2=temp2->right;
							temp2->right=r;
							goto label1;
						}
						else
						{
							temp1=temp1->down;
						}
					}
					cout<<"\nNEW ROW. i="<<i;
					smatrix * s=(smatrix*)malloc(sizeof(smatrix));
					s->val=i;
					temp1=head;
					while(temp1->down!=NULL)
						temp1=temp1->down;
					temp1->down=s;
					temp2=head;
					while(temp2!=NULL)
					{
						if(j==temp2->val)
							goto label;
						else
							temp2=temp2->right;
					}
					cout<<"\nNEW COLUMN2. i="<<j;
					smatrix * t=(smatrix*)malloc(sizeof(smatrix));
					t->val=j;
					temp2=head;
					while(temp2->right!=NULL)
						temp2=temp2->right;
					temp2->right=t;
				}
			}
			label1:;
		}
		label: ;
	}
	cout<<"\n***********************";
	cout<<"\nROW HEADERS:";
	temp1=head;
	temp1=temp1->down;
	while(temp1!=NULL)
	{
		cout<<temp1->val<<" ";
		temp1=temp1->down;
	}
	cout<<"\n***********************";
	cout<<"\nCOLUMN HEADERS:";
	temp2=head;
	temp2=temp2->right;
	
	while(temp2!=NULL)
	{
		cout<<temp2->val<<" ";
		temp2=temp2->right;
	}
	cout<<"\n***********************\n";
	for(k=0;k<w;k++)
	{
		for(l=0;l<x;l++)
		{
			if(ar[k][l]!=0)
			{
				smatrix * u=(smatrix*)malloc(sizeof(smatrix));
				u->val=ar[k][l];
				u->right=NULL;
				u->down=NULL;
				//Making Connection with ROW.
				temp1=head;
				temp1=temp1->down;
				while(temp1->val!=k)
					temp1=temp1->down;
				while(temp1->right!=NULL)
					temp1=temp1->right;
				temp1->right=u;
				//Making Connection with COLUMN.
				temp2=head;
				temp2=temp2->right;
				while(temp2->val!=l)
					temp2=temp2->right;
				while(temp2->down!=NULL)
					temp2=temp2->down;
				temp2->down=u;
			}
		}
	}
	cout<<"\nTotal NON-ZERO ELEMENTS are:"<<head->val<<endl;
	temp1=head;
	temp1=temp1->down;
	temp2=head;
	temp2=temp2->right;
	int a=0;
	cout<<endl<<endl;
	for(int rw=0;rw<w;rw++)
	{
		if(temp1!=NULL && rw==temp1->val)
		{
			for(int cl=0;cl<x;cl++)
			{
				bool output=false;
				temp2=head;
				temp2=temp2->right;
				while(temp2!=NULL)
				{
					if((cl==temp2->val) && (temp2->down==temp1->right))
					{
						cout<<temp1->right->val<<" ";
						temp1=temp1->right;
						if(temp2->down->down!=NULL)
							temp2->down=temp2->down->down;
						output=true;
						break;
					}
					else
					{
						temp2=temp2->right;
					}
				}
				if(output==false)
				{
					cout<<"0"<<" ";
				}
			}
			cout<<endl;
			temp1=head;
			temp1=temp1->down;
			for(int K=0;K<=(rw-a);K++)
				temp1=temp1->down;
		}
		else
		{
			a++;
			for(int Y=0;Y<x;Y++)
				cout<<"0"<<" ";
			cout<<endl;
		}
	}
	return 0;
}
