#include <string>  
#include <iostream>  
using namespace std;  
  
void filter(string str)  
{  
    //各字符串的下标即为其对应的阿拉伯数字  
    char *ch[]={"Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba","Jiu"};  
    int i,j,k,len;  
    string substr;  
    len=str.length();   
    for(i=0;i<len;i++)  
    {    
        //可以看出拼音最短为2个字符，最长为4个字符  
        for(j=i+1;j<len&&(j-i)<4;j++)  
        {  
            substr=str.substr(i,j-i+1);  

            for(k=0;k<10;k++)  
              
                if(!substr.compare(ch[k]))  
                {  
                    printf("%d",k);//相等则打印出数字  
                    break;  
                }               
        }          
    } 
	printf("\n");
}  
  
int main()  
{  
    string str;  
    while(cin>>str){ 
    //cin>>str;
		filter(str);  }
    return 0;  
}  