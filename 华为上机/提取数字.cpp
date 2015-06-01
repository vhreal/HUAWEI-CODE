#include <iostream>
#include <string>
using namespace std;

int main()
{
	string in;
    cin>>in;
	int len=in.size();
	
	for(int i=0;i<len;i++)
		if(in[i]>='0'&& in[i]<='9')
			cout<<in[i];

	cout<<endl;
	return 0;
}

