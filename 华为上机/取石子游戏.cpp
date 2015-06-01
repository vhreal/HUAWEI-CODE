#include<iostream>
using namespace std;

int main()
{
	//计算到f[48]已经接近超出int的数据范围了
	int f[48];
	f[0] = 0, f[1] = 1;
	int i, n;
	for (i = 2; i < 48; i++)
		f[i] = f[i-1] + f[i-2];

	while(cin>>n && n!=0)
	{
		bool flags = 0;

		//根据题目意思，n>=2的，所以从f[3] = 2开始
		for (i = 3; i < 48; i++)
		{
			if (n == f[i]) 
			{
				flags = 1;
				break;
			}
		}

		if(flags) 
			cout<<"Second win"<<endl;
		else 
			cout<<"First win"<<endl;
	}

	return 0;
}