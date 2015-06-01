#include <iostream>
using namespace std;

void Decrease(char *input1, char*input2, char *output)
{
	int i;
	int n1=0;
	int n2=0;
	int m1=0;
	int m2=0;
	for(i=0;input1[i]!='.';i++)
	{
		if(input1[i]=='\0')
		{
			m1=-1;
			break;
		}
		++n1;
	}
	if(m1==-1)
		m1=0;
	else
	{
		for(++i;input1[i]!='\0';i++)
		{
			++m1;
		}
	}
	
	for(i=0;input2[i]!='.';i++)
	{
		if(input2[i]=='\0')
		{
			m2=-1;
			break;
		}
		++n2;
	}

	if(m2==-1)
		m2=0;
	else
	{
		for(++i;input2[i]!='\0';i++)
		{
			++m2;
		}
	}

	cout<<"n1="<<n1<<" "<<"n2="<<n2<<endl;
	cout<<"m1="<<m1<<" "<<"m2="<<m2<<endl;

	int m3=(m1>m2?m1:m2);
	int n3=(n1>n2?n1:n2);
	int len=n3+m3;
	char *s1=new char[len];
	char *s2=new char[len];
	char *s3=new char[len+1];
	for(i=0;i<n3;i++)
	{
		if(n3-i>n1)
			s1[i]='0';
		else
			s1[i]=input1[n1+i-n3];
		if(n3-i>n2)
			s2[i]='0';
		else
			s2[i]=input2[n2+i-n3];
	}
	
	for(i=n3;i<m3+n3;i++)
	{
		if(i-n3<m1)
			s1[i]=input1[n1+1+i-n3];
		else
			s1[i]='0';
		if(i-n3<m2)
			s2[i]=input2[n2+1+i-n3];
		else
			s2[i]='0';
	}

	s1[i]='\0';
	s2[i]='\0';

	cout<<s1<<endl;
	cout<<s2<<endl;

	int k=0;

	for(i=0;i<len;i++)
	{
		if(s1[i]>s2[i])
			break;
		else if(s1[i]<s2[i])
		{
			k=-1;
			break;
		}
	}
	
	int d=0;


	if(k==-1)
	{
		for(i=0;i<len;i++)
		{
			swap(s1[i],s2[i]);
		}
		output[d++]='-';
	}
	
	cout<<s1<<endl;
	cout<<s2<<endl;

	k=0;
	for(i=len-1;i>-1;i--)
	{
		if((k+s1[i]-s2[i])>=0)
		{
			s3[i]='0'+k+s1[i]-s2[i];
			k=0;
		}
		else
		{
			s3[i]='0'+10+k+s1[i]-s2[i];
			k=-1;
		}
		cout<<"s3[]	"<<i<<"	"<<s3[i]<<endl;
	}
	
	s3[len]='\0';
	cout<<s3<<endl;
	
	int start=0;
	for(i=0;i<n3;i++)
	{
		if(start==0 && s3[i]=='0')
			continue;
		start=1;
		
		output[d++]=s3[i];
	}
	if(start==0)
		output[d++]='0';
	
	start=0;
	

	for(i=len-1;i>n3-1;i--)
	{
		if(start==0&&s3[i]=='0')
			continue;
		start=1;
		break;
	}


	int a1=i;

	if(start==0)
	{
		output[d]='\0';
	}
	else
	{
		output[d++]='.';
		for(i=n3;i<a1+1;i++)
			output[d++]=s3[i];
		output[d]='\0';
	}

}


int main()
{
	char *input1="11.1" ;
	char *input2="112.2";
	char *output=new char[100];
	Decrease(input1, input2, output);
	cout<<output<<endl;
	
	return 0;
}