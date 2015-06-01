#include <iostream>
#include <string>
using namespace std;

int delete_sub_str(const char *str,const char *sub_str,char *result)
{
	const char *p,*q;
	char *t,*tmp;
	int n=0;
	int num=0;//相同子串个数
	p=str;
	q=sub_str;
	t=result;
	n=strlen(q);
	tmp =new char[n+1];
	memset(tmp,0,n+1);
	while (*p)
	{
	    memcpy(tmp,p,n);//从p的初始位置开始拷贝n个字符到tmp
		if (strcmp(tmp,q)==0)//tmp=q
		{
			num++;
			memset(tmp,0,n+1);
			p=p+n;
		}
		else
		{      
			*t = *p;
			p++;
			t++;
			memset(tmp,0,n+1);
		}
	}
	delete tmp;
	return num;
}

void main()
{
	char s[100] = {'\0'};
	int num = delete_sub_str("123abc123de1234fg1hi34j123k","123",s);
    cout<<num<<endl;
	cout<<s<<endl;
}