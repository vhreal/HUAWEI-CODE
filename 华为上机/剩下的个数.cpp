#include <stdio.h>

int main()
{
	int n,i=0;
	int a[100];

	scanf("%d",&n);
	while(getchar()!='\n')
	{
		a[i++]=n;
		scanf("%d",&n);
	}
	a[i++]=n;

	int min=a[0];
	int max=a[0];
	for(int j=0;j<i;j++){
		if(min>a[j])
			min=a[j];
		if(max<a[j])
			max=a[j];
	}

	printf("%d %d\n",min,max);

	int count=0;
	for(j=0;j<i;j++){
		if(a[j]!=min&&a[j]!=max)
			count++;
	}

	printf("%d\n",count);

	return 0;
}
