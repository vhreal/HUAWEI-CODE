#include <iostream>
#include <string>
using namespace std;

int sum(int x){
	int sum=0;
	while (x!=0)
	{
		sum+=x%10;
		x=x/10;
	}
	return sum;
}

void sort1(int x[],int n){
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<=i;j++)
		{
			if (x[i]<=x[j])
			{
				k=x[j];
				x[j]=x[i];
				x[i]=k;
			}
		}
	}
}

void sort2(int x[],int n){
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<=i;j++)
		{
			if (sum(x[i])<sum(x[j]))
			{
				k=x[j];
				x[j]=x[i];
				x[i]=k;
			}
		}
	}
}

int main()
{
	int arr[10];
	for (int i=0;i<10;i++)
	{
		cin>>arr[i];
	}

	//个位和相同，按数字从小到大排序
	sort1(arr,10);
	sort2(arr,10);
    for (i=0;i<10;i++)
    {
		cout<<arr[i]<<" ";
    }

	return 0;
}

