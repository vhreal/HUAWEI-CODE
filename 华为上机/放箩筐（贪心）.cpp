#include <iostream>
using namespace std;


int m[100][100];

int min(int a,int b)
{
	return (a<b)?a:b;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}


void knapsack(int v[],int w[],int c,int n)
{	
	int jMax=min(w[n],c);
	for(int j=0;j<=jMax;j++)
		m[n][j]=0;
	for(j=w[n];j<=c;j++)
		m[n][j]=v[n];

	for(int i=n-1;i>1;i--)
	{
		jMax=min(w[i],c);
		for(j=0;j<=jMax;j++)
			m[i][j]=m[i+1][j];
		for(j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}

	m[1][c]=m[2][c];
	if(c>=w[1])
		m[1][c]=max(m[2][c],m[2][c-w[1]]+v[1]);
}

void trace(int w[],int c,int n,int x[])
{
	for(int i=1;i<n;i++)
		if(m[i][c]==m[i+1][c]) 
			x[i]=0;
		else
		{
			x[i]=1;
			c-=w[i];
		}
		x[n]=(m[n][c])?1:0;
}

void main()
{
	int c=100,v[3],t[3],x[3];

	//cout<<"输入体积:"<<endl;
	for(int i=1;i<=3;i++)
		cin>>t[i];

	//cout<<"输入价值:"<<endl;
	for(i=1;i<=3;i++)
		cin>>v[i];

	knapsack(v,t,100,3);
	trace(t,100,3,x);
		
	int vsum=0;
	for(i=1;i<=3;i++)
		vsum+=v[i]*x[i];

	cout<<vsum<<endl;
}
