#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q){  
	return *(int *)p - *(int *)q;  
}  

int main()
{
	int a[10];
	int i;

	int n;
	while(~scanf("%d",&n)&&n!=0){

		for(i=0;i<10;i++)
			scanf("%d",&a[i]);

		qsort(a,10,sizeof(int),compare);

		for(i=0;i<10;i++)
			printf("%d ",a[i]);
		printf("\n");

		if(a[0]>=60)
			printf("60\n");
		else
			printf("%d\n",(a[4]/10%10)*10);
	}
		
	return 0;
}


