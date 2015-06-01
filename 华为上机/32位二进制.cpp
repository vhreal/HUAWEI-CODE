#include<stdio.h>

void DecToBin (unsigned int iDec, char pBin[32])
{
    int i,a[32],j=0;
    for(i = 0; i < 32; i++)
        pBin[i] = '0';

    while(iDec>0)
	{
		a[j++]=iDec%2;
		iDec/=2;
	}

	int k=j-1;
	for(i=32-j;i<32;i++)
		pBin[i]=a[k--]+'0';		
}

int main()
{    
    unsigned int idec;
    char pBin[32];

	while(~scanf("%d",&idec)){    
		DecToBin(idec, pBin);    
		for(int i = 0; i < 32; i++)
			printf("%c", pBin[i]);
		printf("\n");
	}
    
    return 0;
} 