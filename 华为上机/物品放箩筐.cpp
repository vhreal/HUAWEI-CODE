#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[30],i,j;
	for (i=0;i<30;i++)
	{
		cin>>arr[i];
	}
    for (i=0;i<30;i++)
    {
		for (j=0;j<=i;j++)
		{
			int tmp;
			if (arr[i]<=arr[j])
			{
				tmp=arr[j];
				arr[j]=arr[i];
				arr[i]=tmp;
			}
		}
    }
	for (i=0;i<30;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int sum=0;
	for (i=0;i<30;i++)
	{
		sum=sum+arr[i];
		if (sum>100)
		{
			cout<<i<<endl;
			break;
		}
	}
	if (sum<=100)
	{
		cout<<30;
	}
	return 0;
}

