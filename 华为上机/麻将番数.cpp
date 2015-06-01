#include <iostream>
#include <string>
using namespace std;

int main()  
{  
    int fan;  
    int i;  
    int gang;  
    int ka,lian3,ka2tiao; 

    char s[42];  
       
	while(cin>>s){

		fan=gang=ka=lian3=ka2tiao=0;
		int len = strlen(s);
  
		for(i=0;i<len;i++)  
		{ 
			if(s[i]<='9'&&s[i]>='1')
			{
				if(s[i]==s[i+2]&&s[i+2]==s[i+4]&&s[i+4]==s[i+6]&&(s[i+8]==','||s[i+8]=='.'))//判断是否有杠并计数，即四归一如1D1D1D1D
					gang++;  
				else if((s[i]==s[0]||s[i-1]==',')&&s[i]==s[i+2]&&s[i+2]==s[i+4]&&(s[i+6]==','||s[i+6]=='.'))//判断是否有连3，即如2D2D2D  
					lian3=1;  
				else if((s[i]+2)==(s[i+2]+1)&&(s[i+2]+1)==(s[i+4])&&(s[i+6]==','||s[i+6]=='.'))//判断是否有卡，即nT(n+1)T(n+2)T  
				{
					ka=1;  
					if(s[i]=='1'&&s[i+1]=='T')  
						ka2tiao++;//判断卡2条-----1T2T3T 个数
				}  
		   }  
		}
              
		if(ka||lian3||gang==4)//存在nT(n+1)T(n+2)T或2D2D2D的或者4个“四归一”情况，必定是第2种和牌方式  
			fan=ka2tiao*1+gang*2;  
		else  
			fan=2+gang*2;//巧七对的和牌方式  
  
		cout<<fan<<endl; 
	}

    return 0;  
} 