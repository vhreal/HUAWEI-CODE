#include <iostream>
#include <string>
using namespace std;

void convert(char *input,char *output)
{
	char *p=output;

	int len = strlen(input);
	int i=0;
	for(int j=i+1;j<=len;)
	{
		if(input[i]==input[j])
		{
			if(input[i]=='y')
			{
				*p++=input[i]+1;
				*p++=input[i]-24;
			}else if(input[i]=='z')
			{
				*p++=input[i]-25;
				*p++=input[i]-24;
			}else{
				*p++=input[i]+1;
				*p++=input[i]+2;
			}
			i=j+1;
			j=i+1;
		}
		else
		{
			*p++=input[i]+1;
			i=j;
			j=i+1;
		}
	}
	*p='\0';
}

void main()
{
	char a[1024];
	char result[1024]={'\0'};
	while(cin>>a){
		convert(a,result);
		cout<<result<<endl<<endl;
	}
}



