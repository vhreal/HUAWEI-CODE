#include<iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while(cin>>s){
		int len=s.size();
		int m=0;
		for (int i=0;i<len;i++)
		{
			for (int j=i+1;j<len;j++)
			{
				if (s[i]==s[j] && s[i+1]==s[j+1])
				{
					m=1;
					break;
				}
			}
			if(m==1)
				break;
		}
		cout<<m<<endl;
	}
	cout<<endl;

	return 0;
}