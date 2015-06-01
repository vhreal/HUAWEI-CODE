#include <iostream>  
#include <string>  
using namespace std;  
  
int num_of_sub(char *str)  
{     
    int len = strlen(str);  
    int count = 0;  
    for(int i= 0;i < len;i++)  
	{
        if(str[i] != ' ')  
        {  
            for(int j = i;j < len;j++)  
                if(str[j] == ' '|| j == len - 1)  
                {  
                    count++; 
					i=j;
                    break;  
                }    
        }    
	}
          
    return count;  
}  
  
int main()  
{  
    char str[100]; 
	gets(str);
    cout <<num_of_sub(str)<< endl;  
      
    return 0;  
}  