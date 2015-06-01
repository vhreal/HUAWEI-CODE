#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];

	gets(a);

	int len = strlen(a);

	for(int i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<'z'||a[i]>='A'&&a[i]<'Z')
			a[i]=a[i]+1;
		else if(a[i] =='z'||a[i] =='Z')
			a[i]=a[i]-25;
	}

	puts(a);

	return 0;
}



