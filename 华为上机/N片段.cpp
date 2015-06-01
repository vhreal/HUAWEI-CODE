#include <stdio.h>
#include <string.h>

int main()
{
	char c[100];
	int m,n,i,j,k;

	scanf("%d%d",&m,&n);

	for(k=0;k<m;i++)
	{
		scanf("%s",c);

		int len = strlen(c);

		for(i=1;i<=len;i++)
		{
			j=i%n;
			printf("%c",c[i-1]);
			if(j==0)
				printf(",");
		}

		for(i=j+1;i<=n;i++)
			printf("0");
		printf("\n");
	}

	printf("\n");

	return 0;
}