#include <iostream>  
#include <string>  
using namespace std;  
  
//连续不能超过3个
void convert(char *input,char *output)  
{  
    char *p=output;  
  
    int len = strlen(input);  
    int i=0;
	int count=1;
    for(int j=i+1;j<=len;)  
    {  
        while(input[i]==input[j])  
        {  
			count++;
			j++;
		}
		
		if(count==1)
		{
			if(input[i]=='z')
				*p++=input[i]-25;
			else
				*p++=input[i]+1;  
		}
		else if(count==2)
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
			
			count=1;
        }  
        else if(count==3)
        {  
           if(input[i]=='x')  
            {  
                *p++=input[i]+1;
				*p++=input[i]+2;
                *p++=input[i]-23;  
            }else if(input[i]=='y')  
            {  
				*p++=input[i]+1;
                *p++=input[i]-24;  
                *p++=input[i]-23;  
            }else if(input[i]=='z')  
			{  
                *p++=input[i]-25;  
                *p++=input[i]-24;  
				*p++=input[i]-23; 
            } else{
				*p++=input[i]+1;  
                *p++=input[i]+2; 
				*p++=input[i]+3;
			}

			count=1;
		}
        i=j;  
        j=i+1;   
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