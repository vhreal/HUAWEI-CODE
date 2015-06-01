#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int len,factor=17,num;
	bool sign;//用来标志输入字符串是否非法
	while(cin>>s)
	{
		len = s.size();
		sign =1;
		num=0;

		for(int i=0;i<len;i++)
		{
			if(s[i]>='0'&&s[i]<='9')			
				num=num*factor+(s[i]-'0');

			else if(s[i]>='A'&&s[i]<='H')
				num=num*factor+(s[i]-'A'+10);

			else
            {
				sign=0;
                break;
            }
		}

		if (sign)
            cout<<num<<endl;
        else
            cout<<"Error Input!"<<endl;
	}
	return 0;
}
