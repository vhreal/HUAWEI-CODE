#include <iostream>
#include <string>
using namespace std;


int main()
{
	int s;
	cin>>s;
	int sum=0;
	while (s!=0)
	{
		sum=sum+s%10;
		s=s/10;
	}
	cout<<sum;
	return 0;
}

