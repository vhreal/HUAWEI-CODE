#include <iostream>
#include <string>
using namespace std;

//逆序
char * revs(char *s){
	int j = strlen(s)-1;
    int i=0;
	char t;
	while(i<j){
		t = s[i];
		s[i++]=s[j];
		s[j--]=t;
	}
	return s;
}

void process(const char *pInputStr, long lInputLen, char *pOutputStr)  
{  
    bool flag[10] = {0};   
    int j = 0;  
    for(int i = 0;i < lInputLen;i++)  
    {  
        if(flag[pInputStr[i] - '0'] == 0)//pInputStr[i]第一次出现.  
        {  
            pOutputStr[j++] = pInputStr[i]; 
            flag[pInputStr[i] - '0'] = 1;  
        }  
    } 

	pOutputStr[j] = '\0';

	for(i=0;i<j;i++)
	{
		if(pOutputStr[i]==0);
		else
			break;
	}

	for(int k=i;k<j;k++)
		printf("%c",pOutputStr[k]);

	printf("\n");
	
}  

int main()
{
	char *input=new char;
	char *output=new char;

	while(cin>>input){
		if(input[0]=='-')
			cout<<"-";
		process(revs(input),strlen(revs(input)),output);
	}

	return 0;
}