#include <iostream>  
using namespace std;  
  
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)  
{  
    bool flag[26] = {0};   
    int j = 0;  
    for(int i = 0;i < lInputLen;i++)  
    {  
        if(flag[pInputStr[i] - 'a'] == 0)//pInputStr[i]第一次出现.  
        {  
            pOutputStr[j++] = pInputStr[i]; 
            flag[pInputStr[i] - 'a'] = 1;  
        }  
    }  
    pOutputStr[j] = '\0';  
}  

  
int main()  
{  
    char input[20]; 
    char output[20];  

	while(cin>>input){

		stringFilter(input,strlen(input), output);  
		cout << output << endl <<endl;  
	}

	cout<<endl;
      
    return 0;  
}  