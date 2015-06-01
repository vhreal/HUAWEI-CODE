#include <iostream>
#include <string>
using namespace std;

//ÄæĞò
string revs(string s){
	int j = s.length()-1;
    int i=0;
	char t;
	while(i<j){
		t = s[i];
		s[i++]=s[j];
		s[j--]=t;
	}
	return s;
}

//¸öÎ»³Ë»ı
int chen(string s){
	int ans =1;
	for(int i=0;i<s.length();i++){
		ans = ans*(s[i]-'0');
	}
	return ans;
}

int main()
{
	string s;
	cin>>s;
	string ss = revs(s);
	int n=chen(s);
	cout<<ss<<" "<<n<<endl;

	return 0;
}
