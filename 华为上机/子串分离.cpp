#include <iostream>
#include <string>
using namespace std;

//子串分离
void DivideString(const char* pInputStr , long lInputLen , char* pOutputStr)  
{  
	int i,j=0;  
    bool flag;  
    for(i = 0 ; pInputStr[i] == ' ' ; ++i)   //跳过字符串前面的空格  
            continue;  
    flag = true;  
    for(;i < lInputLen ; ++i)  
    {  
		if(pInputStr[i] != ' ')  
        {  
			if(!flag)
				flag = true; 
			pOutputStr[j++] = pInputStr[i];    //将各个子串分离保存下来  
        }  
        else  
        {  
			if(flag)
				pOutputStr[j++] = ',';  
            flag = false;  
        }  
    }  
    pOutputStr[j++] = ',';  
    pOutputStr[j++] = '\0';  
} 

void main()
{
	char s[100];
	char result[100];
	while(gets(s))
	{
		DivideString(s,strlen(s),result);
		cout<<result<<endl<<endl;
	}
	cout<<endl;
}
