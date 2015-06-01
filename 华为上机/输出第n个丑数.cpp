#include <stdio.h>

//判断一个数是否为丑数
bool IsChou(__int64 num)
{
	while(num!=0)
	{
		if(num == 1)
			return 1;
		else if(num % 2 == 0)
			num /= 2;
		else if(num % 3 == 0)
			num /= 3;
		else if(num % 5 == 0)
			num /=5;
		else
			return 0;
	}
}

int findUglyNumber(int n)
{
	__int64 a[501];
	int count=0;

	for(__int64 num=1;count<501;num++)
	{
		if(IsChou(num))
			a[count++]=num;
	}

	if(n<1||n>500)
		printf("-1\n");
	else
		printf("%d\n",a[n-1]);

	return 0;
}


int main()
{
	int n;
	while(~scanf("%d",&n)){
		findUglyNumber(n);
	}
	return 0;
}