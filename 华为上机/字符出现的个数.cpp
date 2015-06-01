#include <stdio.h> 
#include <string>  
    
void stringOut(const char *pInputStr, long lInputLen)    
{    
    int count[26] = {0}; 

    for(int i = 0;i < lInputLen;i++)
		count[pInputStr[i] - 'a']++;

	for(i = 0;i < 26;i++)
	{
		if(count[i]==0);
		else
			printf("%c %d\n",i+'a',count[i]);
	}

}    
  
    
int main()    
{    
    char input[20];    
  
    while(scanf("%s",input)){    
        stringOut(input,strlen(input));   
    } 
	
	return 0;    
}