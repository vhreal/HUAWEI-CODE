#include <stdio.h>
#include <string.h>

int a[50];
int f[50]={0};

int find(int n,int m)
{
	if(n==0)
		return 1;//¸ÕºÃµİ¹é½áÊø
	else if(n<0||n>0&&m==0)
		return 0;
	else 
	{
		if(find(n-a[m-1],m-1))
		{
			f[m-1]=1;
			return 1;
		}
		else
			find(n,m-1);
	}
}

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);

	for(i=0;i<m;i++)
		scanf("%d",&a[i]);

	if(find(n,m))
	{
		for(i=0;i<m;i++)
			printf("%d ",f[i]);
		printf("\n");
	}
	else
		printf("no\n");

	return 0;
}