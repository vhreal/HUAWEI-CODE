#include <iostream>
#include <string>  
using namespace std;  
  
void filter(string str)  
{   
    int i,len;  
    len=str.length(); 
    for(i=0;i<len;i++)  
    {   
		if(str[i]>=65 && str[i]<=90)
			printf("%c",str[i]);        
    } 
	printf("\n");
}  
  
int main()  
{  
    char s[100];  
    while (getchar()!='\n'){
        gets (s);   
		filter(s);
	}
    return 0;  
}  