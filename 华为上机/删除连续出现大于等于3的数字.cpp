#include <iostream>
#include <vector>
using namespace std;

int kk=1;

void delete_num(vector<int> a)
{
	int len = a.size();

	int i,j;
	int flag=0;

	for(i=0;i<len;i++)
	{
		int k=i;
		for(j=k+1;j<len;)
		{
			if(a[k]==a[j]) j++;
			else
			{
				if(j-k>=3)
				{
					a.erase(a.begin()+k,a.begin()+j);
					flag=1;
					break;
				}
				else
				{
					k=j;
					j=k+1;
				}
			}
		}
		if(flag)
			break;
		if(j-k>=3){
			a.erase(a.begin()+k,a.begin()+j);
			break;
		}
	}

	cout<<"第"<<kk<<"次除重: ";
	for(i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;

	if(a.size()==len){
		cout<<"最后结果: ";
		for(i=0;i<a.size();i++)
			cout<<a[i]<<" ";
	}
	else{
		if(a.size()!=0){
			kk++;
			delete_num(a);
		}
		else
			cout<<"最后结果: none"<<endl;
	}

}

void main()
{
	int n;
	vector<int> a;
	cin>>n;
	while(getchar()!='\n')
	{
		a.push_back(n);
		cin>>n;
	}
	a.push_back(n);
	
	delete_num(a);
	cout<<endl;
}
