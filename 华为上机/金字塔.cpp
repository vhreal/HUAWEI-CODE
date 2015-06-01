#include <stdio.h>
#include <stdlib.h>

int compare(const void *p,const void *q){
	return *(int *)q - *(int *)p;
}

int main()
{
	int i,j,a,k=0;
	int input[100];
	int output[100];
	
	scanf("%d",&a);
    while(getchar()!='\n')  
    {  
        input[k++]=a;  
        scanf("%d",&a); 
    } 
	input[k]=a;

	qsort(input,k+1,sizeof(int),compare);

	int f= (k+1)/2;

	output[f]=input[0];
    for(i=1,j=1;i<=k;){
		output[f-j]=input[i];
		if((f+j)>k)
			break;
		output[f+j]=input[i+1];
		i+=2;
		j++;
	}

	for(i=0;i<=k;i++)
		printf("%d ",output[i]);

	printf("\n");
	
	return 0;
}
