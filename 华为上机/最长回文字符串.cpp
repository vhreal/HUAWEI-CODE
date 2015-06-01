#include <iostream>
#include <string>
using namespace std;

#define N 100

string convert(string s)
{
	string out="";
    int len=s.length();
	for (int i=len-1;i>=0;i--)
	{
         out.insert(out.length(),1,s[i]);
	}
	return out;
}

void process(string r)
{
	int len=r.length();
	string *str = new string[N];
	for (int i=0;i<N;i++)
	{
		str[i]="\0";
	}
	int m=0;
	for (i=0;i<len;i++)
	{
		for (int j=len-1;j>=(i+1);j--)
		{
             if (r.substr(i,j-i+1)==convert(r.substr(i,j-i+1)))
             {
                 str[m++]=r.substr(i,j-i+1);
             }
		}
	}

	for(int k=0;k<m;k++)
		cout<<str[k]<<endl;
	cout<<endl;

	int maxlen=str[0].length();
	for(k=1;k<m;k++)
		if(maxlen<str[k].length())
			maxlen=str[k].length();

	for(k=0;k<m;k++)
		if(maxlen==str[k].length())
			cout<<str[k]<<endl;
}



void main()
{
	string in;
    getline(cin,in);
	process(in);
}