#include <iostream>
#include <string>
using namespace std;

int main()
{
	int len,i,l,r,k,flag,a[50];
	string s;
	while(cin>>s){

		len=s.length();
		l=0;
		r=0;
		k=0;
		flag=1;

		for(i=0;i<len;i++)
		{
			if(s[i]=='(')
			{
				l++;
				a[k++]=1;
			}
			else if(s[i]==')')
			{
				r++;
				if(a[k-1]==1&&k>0)
				{
					a[k-1]=0;
					k--;
				}
				else
					flag=0;
			}

			if((i==2&&s[i]!='(')||(i==len-1&&s[i]!=')'))//最外面至少有一对括号
				flag=0;
		}

		if(a[0]==0&&flag!=0)
			cout<<"RIGHT"<<" ";
		else
			cout<<"WRONG"<<" ";
		cout<<l<<" "<<r<<endl;
	}

	return 0;
}
