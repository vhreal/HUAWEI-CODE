#include <iostream>
#include <string>  
using namespace std;  
  
void filter(string str)  
{  
    //各字符串的下标即为其对应的阿拉伯数字  
    char *ch[]={"Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba","Jiu"};  
	int a=0;//存储数字
    int i,j=1,k,len,sum=0,flag;  
    string substr;  
    len=str.length(); 
    for(i=0;i<len;)  
    {    
        //遇到下一个大写字母的停下来
		if(str[j]<'a'||j==len)
		{
			flag=0;//标记最后是数字还是wan,qian,bai,shi

			substr=str.substr(i,j-i);

			if(!substr.compare("Wan")){
				sum+=a*10000;
			}else if(!substr.compare("Qian")){
				sum+=a*1000;
			}else if(!substr.compare("Bai")){
				sum+=a*100;
			}else if(!substr.compare("Shi")){
				sum+=a*10;
			}else{
				for(k=0;k<10;k++) {              
					if(!substr.compare(ch[k]))  
					{
						flag=1;
						a=k;
						//printf("%d",k);//相等则打印出数字  
						break;  
					} 
				}
			}
            i+=(j-i);//i跳到下一个大写字母开始
			j=i+1;
		}else{
			j++;
		}
    } 
	if(flag)
		printf("%d\n",sum+a);
	else
		printf("%d\n",sum);
}  
  
int main()  
{  
    string str;  
    while(cin>>str){ 
    //cin>>str;
		filter(str);  }
    return 0;  
}  