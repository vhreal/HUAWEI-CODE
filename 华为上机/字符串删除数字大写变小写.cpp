#include <string>
#include <iostream>
using namespace std;


int main()
{
	string s;
	while(cin>>s){
		int len=s.length();
		for (int i=0;i<len;i++)
		{
			if (s[i]>='0'&&s[i]<='9')
			{
				continue;
			}
			if (s[i]>='a' && s[i] <='z')
			{
				cout<<s[i];
			}
			if (s[i]>='A'&&s[i]<='Z')
			{
				cout<<char(s[i]+32);
			}
		}
		cout<<endl;
	}
	return 0;
}

