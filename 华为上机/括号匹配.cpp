#include <stdio.h>

int main()
{
	char a[100],c,i=0;
	int flag;
	scanf("%c",&c);
	while(c!='\n')
	{
		flag=0;
		switch(c){
		case('('):
			a[i++]=c;
			break;
		case('['):
			a[i++]=c;
			break;
		case(')'):
			if(a[i-1]=='(')
			{
				a[i-1]='\0';
				i--;
			}
			else
				flag=1;
			break;
		case(']'):
			if(a[i-1]=='[')
			{
				a[i-1]='\0';
				i--;
			}
			else
				flag=1;
			break;
		}
		scanf("%c",&c);
	}
	printf("%d\n",flag);

	return 0;
}