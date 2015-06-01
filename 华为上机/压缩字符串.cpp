#include <iostream>  
using namespace std;  
  
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)  
{  
    int count = 1;  
    int j = 0;  
      
    for(int i = 0;i < lInputLen - 1;i++)  
    {
        if(pInputStr[i] == pInputStr[i+1])  
			count++;
        else  
        {  
            if(count > 1)
            {  
                pOutputStr[j++] = (char)(count + '0');//注意将int型转化为char型表示.  
                pOutputStr[j++] = pInputStr[i];  
                count = 1;  
            }  
            else 
				pOutputStr[j++] = pInputStr[i];  //count等1的情况.  
        }  
    }  
    pOutputStr[j] = '\0';  
}  
  
int main()  
{  
    char input[20]; 
    char output[20];  

	while(cin>>input){
		stringZip(input,20, output);  
		cout << output << endl <<endl;  
	}

	cout<<endl;
      
    return 0;  
}  