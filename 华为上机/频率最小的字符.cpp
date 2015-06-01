#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int fre[26];
	memset(fre,0,sizeof(fre));

	for (int i=0;i<s.size();i++)
		fre[s[i]-'a']++;

	int min=9999,k=0;
	for (i=0;i<26;i++)
	{
		if (fre[i]<min&&fre[i]!=0)
		{
			min=fre[i];
			k=i;
		}
	}
	
	cout<<(char)(k+'a')<<endl;

	return 0;
}

