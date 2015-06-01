#include <iostream>
using namespace std;

int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

//数大小不超过10
void calcTimes(int num[],int len)
{
	qsort(num,len,sizeof(int),compare);

	int count[11]={0};

	for(int i=0;i<len;i++)
		count[num[i]]++;

	int max = count[0];
	for(i=0;i<11;i++)
		if(count[i]>max)
			max=count[i];


	for(i=0;i<11;i++)
		if(count[i]==max)
			cout<<i<<" ";
	
	cout<<endl;
}

int main()
{
	int n,i=0,a[100];

	cin>>n;
	while(getchar()!='\n')
	{
		a[i++]=n;
		cin>>n;
	}
	a[i++]=n;

	calcTimes(a,i);

	return 0;
}