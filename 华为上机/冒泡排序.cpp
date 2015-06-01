#include <iostream>
using namespace std;

void sort(int a[],int len)
{
	int tmp;
	for(int i=0;i<len-1;i++)
		for(int j=0;j<len-i-1;j++)
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
}

void main()
{
	int a[]={23,56,343,6,2,0,56};

	int len=sizeof(a)/sizeof(a[0]);

	cout<<len<<endl;
	sort(a,len);

	for(int k=0;k<len;k++)
	{
		if(k!=0)
			cout<<" "<<a[k];
		else
			cout<<a[k];
	}
}