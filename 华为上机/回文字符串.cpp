#include <iostream>
#include <cstring>
using namespace std;

int huiwen(char *a){
	int len = strlen(a);
	int i,j=len-1;

	for(i=0;i<len/2;i++,j--){
		if(a[i]!=a[j]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char a[1001];
	while(cin>>a){
		if(huiwen(a))
			cout<<"Yes!"<<endl;
		else 
			cout<<"No!"<<endl;
	}
	cout<<endl;
	return 0;
}
			
