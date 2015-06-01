#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction (const string &str1,const string &str2){	
	return(str2.length()< str1.length());
}

void my_word(char input[],char output[]){
	
	vector<string> str;
	char*cur = input;
	char*p = input;
	int len;
	bool flag =false;
	//去除杂质，取单词
	while(*p !='\0'){
		if((*p >='a'&&*p <='z')||(*p >='A'&&*p <='Z'))
			p++;
		else{
			len = p-cur;
			if(len >1){
				string tmp(cur,len);

				for(int i=0;i<str.size();i++)
					if(tmp == str[i])
						flag =true;
				if(flag !=true)
					str.push_back(tmp);
			}
			cur = p+1;
			p++;
			flag =false;
		}
	}

	len = p-cur;
	if(len >1){
		string tmp(cur,len);

		for(int i=0;i<str.size();i++)
			if(tmp == str[i])
				flag =true;
		if(flag !=true)
			str.push_back(tmp);
	}

	//sort
	sort(str.begin(),str.end(),myfunction);
	//拼接字符串
	*output='\0';
	int i;
	for(i=0;i<str.size()-1;i++){
		strcpy(output+strlen(output),(str[i]+" ").c_str());
		
	}
	strcpy(output+strlen(output),(str[i]).c_str());
	cout<<output<<endl;
}

int main(){

	char input[]="some ninja local buses, somes1234123drivers";
	char output[500];
	my_word(input, output);

	return 0;
}
