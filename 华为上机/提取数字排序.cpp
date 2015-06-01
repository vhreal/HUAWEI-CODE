#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int compare (const void *p,const void *q){
	return *(int *)q-*(int *)p;
}

int ss(string s)
{
	int len=s.length();
	int ans=0;
	for (int i=0;i<len;i++)
	{
         if (s[i]>='0'&& s[i]<='9')
         {
			 ans = ans*10;
			 ans = ans+(s[i]-'0');
         }
	}
    return ans;
}


int main()
{
	int n;
	cin>>n;
	string *s=new string[n];
	int *in=new int[n];
    for (int i=0;i<n;i++)
    {
		cin>>s[i];
		in[i]=ss(s[i]);
    }

	qsort(in,n,sizeof(int),compare);

	for (i=0;i<n;i++)
		cout<<in[i]<<" ";
	cout<<endl;
	return 0;
}

