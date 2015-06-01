#include <iostream>
using namespace std;

int calculate(int len,char *expStr)
{
	int result =0;
    int*  datas = new int[len];   //用数组模拟操作数栈
    char* opers = new char[len];  //用数组模拟操作符栈

    int dataTop = -1;
    int operTop = -1;
    memset(datas,0,len*sizeof(int));
    memset(opers,0,len*sizeof(char));

    for(int i=0;i<len;++i)
	{
		if(expStr[i] >= '0' && expStr[i] <= '9')
			datas[++dataTop] = expStr[i]-'0';
		if(expStr[i] == '+' || expStr[i] == '-' || expStr[i] == '*' || expStr[i] == '/')
		{
			char oper = expStr[i];
			if(oper =='*' || oper =='/')
			{
				int num1 = datas[dataTop--];
				int num2 = expStr[++i]-'0';
				if(oper  =='*')
					num1*= num2;
				else if(oper =='/')
					num1/=num2;
				datas[++dataTop] = num1;
			}
			else
				opers[++operTop] = expStr[i];
		}
	}

	while(operTop!=-1)
	{
		char oper = opers[operTop--];
		int num1 = datas[dataTop--];
		int num2 = datas[dataTop--];
		if(oper == '+')
			num2+=num1;
		else if(oper =='-')
			num2-=num1;
		datas[++dataTop]=num2;
	}

	result = datas[dataTop];

	return result;
}

int main()
{
	char a[100];
	while(cin>>a){
		int len = strlen(a);
		cout<<calculate(len,a)<<endl;
	}
	cout<<endl;
	return 0;
}
