#include <iostream>  
#include <string>  
using namespace std;  
  
//10个名字，26个字符
char nameArray[10][26]={"wang fei","zhang man yu","zhang zhi yi","li li",  
"li xiao man","li yu cun","yang ni","xiao tong","li lei","zhang san"};  
  
//找出a，b中字母重复的次数
int findCount(bool a[],bool b[])  
{  
    int count=0;  
    for(int i=0;i<26;i++) {
		if(a[i]&&b[i])  
		count++; 
	}
    return count;  
}  
  
int main()  
{  
    char name[100];  
    gets(name); 
  
    bool flag_0[10][26]; //每个女士名字中记录出现的字母，出现为1，不出现为0
    memset(flag_0,0,sizeof(flag_0)); 
	
    int i,j;   
    for(i=0;i<10;i++)  
    {  
        for(j=0;nameArray[i][j]!='\0';j++)  
        {  
            if(nameArray[i][j]<='z' && nameArray[i][j]>='a')  
            {  
                flag_0[i][nameArray[i][j]-'a']=1;  
            }  
        }  
    }  

    bool flag_1[26];  //每个男士名字中记录出现的字母，出现为1，不出现为0
    memset(flag_1,0,sizeof(flag_1));  

    for(i=0;name[i]!='\0';i++)  
    {  
        if(name[i]<='z' && name[i]>='a')  
        {  
            flag_1[name[i]-'a']=1;  
        }  
    }  
  
  
    int count[10]; //记录每个女士名字中和输入的男士名字中的重复字母数
	int max =0;
    for(i=0;i<10;i++)  
    {  
        count[i]=findCount(flag_1,flag_0[i]); 
		if(count[i]>max)  
            max=count[i];  //输出匹配度最高的次数
    }       
  
    for(i=0;i<10;i++)  
    {  
        if(count[i]==max)  
        {  
            cout<<nameArray[i]<<endl; //输出最先匹配的女士名字 
            break;  
        }  
    }  
  
    return 0;  
}