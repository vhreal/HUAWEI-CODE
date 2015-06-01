#include <iostream>  
#include <string>  
using namespace std;  
  
#define N 10  
  
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)  
{   
    char ch;  
    int index1 = 0;  
    int index2 = 0;  
    int index3 = 0;   
    char op1[N];  
    char op[N];  
    char op2[N];  
      
    int cnt = 0; 
      
    for(int i = 0; i < lInputLen; i++)  
    {  
        ch = pInputStr[i];  
        if(ch == ' ')  
        {  
            cnt++;  
            if(cnt > 2)  
            {  
                cout << "空格多余！"<<endl <<endl;  
                return;  
            }  
            continue;  
        }  
          
        if(cnt == 0)        //操作数op1.  
            op1[index1++] = ch;
        else if(cnt == 1)   //操作符.  
        {   
            op[index2++] = ch;  
            if(index2 > 1)//判断类似++的情况.  
            {  
                cout << "格式错误！"<<endl <<endl;  
                return;  
            }  
        }  
        else if(cnt == 2)   //操作数op2.  
        {  
            op2[index3++] = ch;  
        }  
    }  
    op1[index1] = op[index2] = op2[index3] = '\0';  
      
    int iop1 = atoi(op1);  
    int iop2 = atoi(op2);  
    int temp = 0;  
    if(op[0] == '+')  
        temp = iop1 + iop2;  
    else if(op[0] == '-')  
        temp = iop1 - iop2;  

    cout << temp << endl <<endl;  
}  
  
int main()  
{  
   // char *pch1 = "4 + 7";  
   // int len1 = strlen(pch1);  
   // char result1[N];  
   // arithmetic(pch1,len1,result1);    
      
	char a[100];
	char result[100];

	while(gets(a)){
		arithmetic(a,strlen(a),result); 
	}   
     
	cout<<endl;
    return 0;  
}  