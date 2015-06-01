#include <iostream>
#include<math.h>
using namespace std;

int len;

int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

void calcTimes(int num[],int value)
{
	int i,k,b[100],j=0;

	for(i=0;i<len;i++)
	{
		b[j++]=abs(num[i]-value);
	}

	qsort(b,len,sizeof(int),compare);

	for(i=0;i<len;i++)
		for(k=0;k<len;k++)
			if(abs(num[k]-value)==b[i])
			{
				printf("%d ",num[k]);
				break;
			}

	printf("\n");
}

int main()
{
	int n,m,i=0,a[100];

	scanf("%d",&n);
	while(getchar()!='\n')
	{
		a[i++]=n;
		scanf("%d",&n);
	}
	a[i++]=n;

	len = i;

	scanf("%d",&m);

	calcTimes(a,m);

	return 0;
}