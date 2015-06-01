// 5.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int sum=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&& s[i]<='9')
		{
			int tmp;
			tmp=s[i]-'0';
			sum=sum+tmp;
		}
	}
	cout<<sum;
	return 0;
}

