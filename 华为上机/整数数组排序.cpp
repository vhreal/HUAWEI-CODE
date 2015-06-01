#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

int main()
{
	int a[1024];
	int i=0;
	int n;
	cin>>n;
	while(getchar()!='\n')
	{
		a[i++]=n;
		cin>>n;
	}
	a[i++]=n;

	qsort(a,i,sizeof(int),compare);

	for(int j=0;j<i;j++){
		if(j!=0)
			cout<<",";
		cout<<a[j];
	}

	cout<<endl;
	return 0;
}
