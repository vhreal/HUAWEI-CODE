#include <iostream>
#include <vector>
using namespace std;

void Out(int n,int s,int m)
{
	vector<int> people;
	for (int i=1;i<=n;i++)
	{
		people.push_back(i);
	}
    int start = s-1;
	int tmp =1;
    int out;
	while (tmp <= n)
	{
        out=(start-1+m)%people.size();
		cout<<""<<tmp++<<"::"<<people[out]<<endl;
        people.erase(people.begin()+out);
		start=out;     
	}

}


int main()
{
	//n人数，s开始，m数多少个
	int n,s,m;
    cin>>n>>s>>m;
	Out(n,s,m);
	return 0;
}

