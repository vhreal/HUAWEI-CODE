#include <stdio.h>
#include <stdlib.h>

int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int main()
{
	int n,m,i=0,k=0;
	int sort[100],a[100];

	scanf("%d",&n);
	while(getchar()!='\n')
	{
		a[i++]=n;
		scanf("%d",&n);
	}
	a[i++]=n;

	scanf("%d",&m);// ‰»Î23

	for(int j=0;j<i;j++)
	{
		int temp = a[j];
		while(temp>0)
		{
			if(temp%100==m)
			{
				sort[k++]=a[j];
				break;
			}
			else
				temp=temp/10;
		}
	}

	qsort(sort,k,sizeof(int),compare);

	for(j=0;j<k;j++)
		printf("%d ",sort[j]);
	printf("\n");

	return 0;
}

