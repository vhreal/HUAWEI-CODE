#include <iostream>
#include <math.h>
using namespace std;

int x[10];

bool PLACE(int k)
{
    int i=1;
    while(i<k)
	{
        if (x[i]==x[k]||abs(x[i]-x[k])==abs(i-k))
            return false;
        i=i+1;
	}
	return true;
}


void NQUEENS(int n)
{
	x[1]=0;
	int k=1;
	int num=0;
    while(k>0)
	{
		x[k]=x[k]+1;
        while(x[k]<=n&&!PLACE(k))
		{
			x[k]=x[k]+1;
		}
        if (x[k]<=n)
		{
			if(k==n) 
			{
				for(int i=1;i<=n;i++)
					cout<<x[i]<<"  ";
				num++;
				cout<<endl;
			}
			else 
			{
				k=k+1;
				x[k]=0;
			}
		}
        else 
			k=k-1;
	}

	cout<<num<<endl;
}

int main()
{
	int n;
	while(cin>>n)
		NQUEENS(n);
	
	return 0;
}

