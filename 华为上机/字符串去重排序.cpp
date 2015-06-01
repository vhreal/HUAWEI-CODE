#include <iostream>
#include <string>
using namespace std;

void sort(string s)
{
	 char tmp[100];
	 int len=s.size();
	 int count=0,i,j;
	 for (i=0;i<len;i++)
	 {
		 for (j=i+1;j<len;j++)
		 {
              if (s[i]==s[j])
              {
				  s[j]='0';
              }
		 }

	 }

	 for (i=0;i<len;i++)
	 {
		 if (s[i]>='a' && s[i]<='z')
		 {
			 tmp[count++]=s[i];
		 }
	 }

	 //Ã°ÅÝÅÅÐò
	 for (i=0;i<count;i++)
	 {
		 for (j=0;j<i;j++)
		 {
			 char temp;
			 if (strcmp(&tmp[j],&tmp[i])>0)
			 {
                 temp=tmp[j];
				 tmp[j]=tmp[i];
				 tmp[i]=temp;
			 }
		 }
	 }


	 for (i=0;i<count;i++)
		cout<<tmp[i];

	 cout<<endl;
}

void main()
{
	string s;
	cin>>s;
	sort(s);
}