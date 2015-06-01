#include <iostream>
#include <string>
#define len 11
using namespace std;

int cmp(const void *p,const void *q)
{
	return *(int *)p-*(int *)q;
}

int cmp2(const void *p,const void *q)
{
	return *(int *)q-*(int *)p;
}

int main()
{
	int a[]={2,1,4,3,6,5,9,8,7,0,111};

	int arryJi[len];
	int arryOu[len];

	int i=0,j=0,k;
	for(k=0;k<len;k++)
	{
		if(a[k]%2==0)
			arryOu[j++]=a[k];
		else
			arryJi[i++]=a[k];
	}

	qsort(arryJi,i,sizeof(int),cmp);
	qsort(arryOu,j,sizeof(int),cmp2);

	int result[len],flag=0;
	k=0;
	int ii=0,jj=0;
		
	while(ii<i && jj<j)
	{
		if(!flag)
		{
			result[k++]=arryJi[ii++];
			flag=1;
		}
		else
		{
			result[k++]=arryOu[jj++];
			flag=0;
		}		
	}

	while(ii<i)
	{
		result[k++]=arryJi[ii++];
	}

	while(jj<j)
	{
		result[k++]=arryOu[jj++];
	}

	for(i=0;i<len;i++)
		cout<<result[i]<<" ";

	cout<<endl;
	return 0;
}
