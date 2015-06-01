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
	int flag_0=0;
    for(int i = 0;i < lInputLen;i++)  
    {  
        if(flag[pInputStr[i] - '0'] == 0)//pInputStr[i]第一次出现.  
        {  
			if(pInputStr[i] - '0'==0 && flag_0==0);
			else{
				flag_0=1;
				pOutputStr[j++] = pInputStr[i]; 
				flag[pInputStr[i] - '0'] = 1;  
			}
        }  
    } 

	pOutputStr[j]='\0';

	for(i=0;i<j;i++)
		cout<<pOutputStr[i];

	cout<<endl<<endl;
	
}  

int main()
{
	char *input=new char[100];
	char *output=new char[100];
	char *s=new char[100];
	char *ss;

	int k=0;

	while(cin>>input){
		k=0;
		if(input[0]=='-')
		{
			cout<<"-";
			for(int i=1;i<strlen(input);i++)
				s[k++]=input[i];
			s[k]='\0';
			ss=revs(s);
			process(ss,strlen(ss),output);
		}
		else
		{
			ss=revs(input);
			process(ss,strlen(ss),output);
		}
	}

	delete input;
	delete output;
	delete s;

	return 0;
}