#include <iostream>
using namespace std;

#define MAX 65536

int main()
{
	int i;//第几个学生
	int j;//每个学生遍历电灯
	int count;
	int N;

	while(cin>>N){
        int a[MAX]={0};//每个电灯经过的人数
		count=0;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(i*j>N)
					break;
				a[i*j]++;
			}
			/*
			for(j=i;j<=N;j++)
			{
				if(j%i==0)
					a[j]++;
			}*/
		}

		for(i=1;i<=N;i++){
			if(a[i]%2!=0)
				count++;
		}
        cout<<count<<endl;
	}
	cout<<endl;
	return 0;
}