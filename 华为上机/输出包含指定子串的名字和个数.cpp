#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> result;
	string arrayStr[100];
	int i,j,k;
	int count=0;

	string s;
	int n;
	cin>>n;

	for(i=0;i<n;i++)
		cin>>arrayStr[i];

	cin>>s;

	/*
	//方法一
	for(i=0;i<n;i++)
	{
		for(j=0;j<arrayStr[i].length();)
		{
			if(s[0]==arrayStr[i][j])
			{
				for(k=1;k<s.length();)
				{
					if(s[k]!=arrayStr[i][j+1])
					{
						j++;
						break;
					}
					else
					{
						j++;
						k++;
					}
				}
				if(k==s.length())
				{
					count++;
					result.push_back(arrayStr[i]);
				}
			}
			else
				j++;
		}
	}
	*/

	//方法二
	for(i=0;i<n;i++)
	{
		if(arrayStr[i].find(s)!=-1)
		{
			count++;
			result.push_back(arrayStr[i]);
		}
	}

	if(count==0)
		cout<<0<<endl;
	else
	{
		cout<<count<<endl;
		for(i=0;i<result.size();i++)
			cout<<result[i]<<endl;
	}

	return 0;
}


