#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Bracket(char* src, char* dst)
{
	int nleft=0;
	int nright=0;
	int i=0;
	char c;
	if(src!=NULL)
	{
		while((c=src[i++])!='\0')
		{
			if(c=='(') nleft++;
			if(c==')') nright++;
		}
		int nmin=nleft>nright?nright:nleft;
		nleft=nmin;
		nright=nmin;
		i=0;
		int ldst=0;
		while ((c=src[i++])!='\0')
		{
			if (c=='(' && nleft-- >0)
			{
				dst[ldst++]=c;
			}
			if (c==')' && nright-- >0)
			{
				dst[ldst++]=c;
			}
			if(c!='(' && c!=')')
			{
				dst[ldst++]=c;
			}
		}
		dst[ldst]='\0';
		puts(dst);
	}
}

int main()
{
	char src[60];
	char dst[60];
	gets(src);
	Bracket(src,dst);
	return 0;
}