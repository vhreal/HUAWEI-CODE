#include <stdio.h>

int gcd(int a,int b)
{
	return a%b?gcd(b,a%b):b;
}

int main()
{
	int N,a[20],k,i;
	while(~scanf("%d",&N))
	{
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);

		k=a[0];
		for(i=1;i<N;i++)
		{
			k=gcd(k,a[i]);
		}

		printf("%d\n",k);
	}
	return 0;
}