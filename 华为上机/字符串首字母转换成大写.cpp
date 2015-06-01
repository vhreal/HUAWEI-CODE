#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char input[]="this is a book";
	char output[256]={'\0'};
	int i,len;
	len=strlen(input);
	printf("变换前的字符串为:%s\n",input);
	for(i=0;i<len;i++)
	{
		if(input[0]!=' ')
			input[0]-=32;
		if(input[i]==' ')
			input[i+1]-=32;
		output[i]=input[i];
	}
	printf("变换后的字符串为:%s\n",output);
	return 0;
}
