#include <stdio.h>
#include <stdlib.h>

int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int main()
{
	int n,i=0,a[100];
	scanf("%d",&n);
	while(getchar()!='\n'){
		a[i++]=n;
		scanf("%d",&n);
	}
	a[i++]=n;

	qsort(a,i,sizeof(int),compare);

	int ans=a[1]-a[0],k;
	for(int j=1;j<i-1;j++)
	{
		if(ans>=a[j+1]-a[j])
		{
			ans=a[j+1]-a[j];
			k=j;
		}
	}

	printf("%d %d\n",a[k],a[k+1]);
	 
	return 0;
}