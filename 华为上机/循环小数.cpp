#include<iostream>
#include<string>
using namespace std;

int maxn = 100; //设置字符串的最大位数
int reminder_exist[10000];
int reminder_pos[10000];

void div(const int a, const int b, char *str)
{
	int numerator,denominator,quotient, reminder, outcnt = 0;
	int flag = 0; //负数标志

	memset(reminder_exist, 0, sizeof(reminder_exist));
	memset(reminder_pos, 0, sizeof(reminder_pos));
  
	numerator = a; //定义const int，由于要改变分子分母，所以我们通过中间变量转化
	denominator = b;

	if(a*b < 0)
		flag = 1;//有负数

	//将分子和分母变成整数
	numerator = numerator < 0 ? -numerator:numerator; 
	denominator = denominator < 0 ? -denominator:denominator;

	quotient = numerator/denominator;
	reminder = numerator%denominator;   
	int integer = quotient;

	//找出循环
	int cycle_pos = maxn; //循环的位置
	int i = 0;
	for(i = 0; i <= maxn; i++)
	{
		//找出余数相等的情况，求出循环周期
		if(reminder_exist[reminder])
		{
			cycle_pos = reminder_pos[reminder];
			break;
		}
		else
		{
			reminder_exist[reminder] = 1;
			reminder_pos[reminder] = i;
		}

		numerator = reminder *10;
		quotient = numerator/denominator;
		reminder = numerator%denominator; 

		str[outcnt++] = quotient + '0'; //将更新的商存入字符串中
	}

	str[outcnt++] = '\0';
	
	if(!flag)
		cout << integer << "." ;
	else
		cout << "-" << integer << ".";


	for(int j = 0; j < cycle_pos; j++)
		cout << str[j];

	cout << "(";

	for(j = cycle_pos; j < i;j++)
		cout <<  str[j];

	cout << ")" << endl;
}


int main()
{
	int a,b;
	char s[100];
	while(cin >> a >> b){
		div(a,b,s);
	}
	cout<<endl;
	return 0;
}