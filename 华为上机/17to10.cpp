#include <iostream> 
#include<math.h>   
using namespace std;  
      
void convert(char* p)  
{  
	int len=strlen(p);  
    int sum=0;  
    int num=0;  
    for(int i=0;i<len;i++)  
    {  
		if(p[i]>='0'&&p[i]<='9')  
            num=p[i]-'0';  
        else  
            num=p[i]-55;
	
        sum=sum*17+num;
    }  
    cout<<sum<<endl;  
}  
      
      
int main()  
{  
	char p[100];  
    //gets(p); 

	while (cin>>p){     
        convert(p);    
    }  
	cout<<endl;
    return 0;  
}  