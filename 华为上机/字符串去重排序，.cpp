#include <iostream>
using namespace std;

int foo(char * input,char * output)
{
	int book[26]={0};
	if(input==NULL)
		return -1;

	int len=strlen(input);
	int k=0;

	for(int i=0;i<len;i++)
	{
		if(input[i]>='a'&& input[i]<='z')
		{
			book[input[i]-'a']++;
			if(book[input[i]-'a']==1)
				output[k++]=input[i];
		}
		else if(input[i]>='A'&& input[i]<='Z')
		{
			book[input[i]-'A']++;
			if(book[input[i]-'A']==1)
				output[k++]=input[i];
		}
	}
	output[k]='\0';

	for(i=0;i<k-1;i++)
		for(int j=0;j<k-i-1;j++)
		{
			if(output[j]>output[j+1])
			{
				char tmp=output[j];
				output[j]=output[j+1];
				output[j+1]=tmp;
			}
		}

	for(i=0;i<k;i++)
		cout<<output[i];

	cout<<endl;

	return 0;
}

int main()
{
	char * input = "fffffABBdkfgjsksfsvxcxcx";
	char output[100];

	foo(input,output);

	return 0;
}

	





