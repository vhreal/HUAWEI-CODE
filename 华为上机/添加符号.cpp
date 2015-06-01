#include <iostream>
#include <string>
using namespace std;

int n;

int isresult(string s)
{
	int tmp=0;//判断每位的值
	int pre=0;//0+ 1-
	int num=0;//存放计算结果

	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&& s[i]<='9')
		{
			tmp=tmp*10+s[i]-'0';
		}
		else
		{  
			if(pre == 0)
				num = num+tmp;
			else
				num = num-tmp;
			tmp =0;
			if(s[i]=='+')
				pre = 0;
			else
				pre = 1;
	
		}
	}
	if (pre==0)//最后一位
		num=num+tmp;
	else
		num=num-tmp;

	if(num==n)
	{
		cout<<s<<endl;
		return true;
	}
	else
		return false;
}

void main()
{
	int count;//结果个数

	while(cin>>n){
		count=0;
		string symbol[3]={"+","-",""};
		for (int a=0;a<3;a++)
		{
			for (int b=0;b<3;b++)
			{
				for (int c=0;c<3;c++)
				{
					for (int d=0;d<3;d++)
					{
						for (int e=0;e<3;e++)
						{
							for (int f=0;f<3;f++)
							{
								for (int g=0;g<3;g++)
								{
									for (int h=0;h<3;h++)
									{
										string ll="";
										ll.insert(0,"1");
										ll.insert(ll.length(),symbol[a]);
										ll.insert(ll.length(),"2");
										ll.insert(ll.length(),symbol[b]);
										ll.insert(ll.length(),"3");
										ll.insert(ll.length(),symbol[c]);
										ll.insert(ll.length(),"4");
										ll.insert(ll.length(),symbol[d]);
										ll.insert(ll.length(),"5");
										ll.insert(ll.length(),symbol[e]);
										ll.insert(ll.length(),"6");
										ll.insert(ll.length(),symbol[f]);
										ll.insert(ll.length(),"7");
										ll.insert(ll.length(),symbol[g]);
										ll.insert(ll.length(),"8");
										ll.insert(ll.length(),symbol[h]);
										ll.insert(ll.length(),"9");

										if (isresult(ll))
										{
											count++;
										}

									}
								}
							}
						}
					}
				}
			}
		}
		cout<<count<<"种"<<endl<<endl;
	}
}