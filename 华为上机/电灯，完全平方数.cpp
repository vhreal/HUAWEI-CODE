#include <iostream>
using namespace std;

int main(){
	int i;
	int N;
	int count;

	while(cin>>N){
		count=0;
		for(i=1;;i++){
			if(i*i>N)
				break;
			count++;
		}
		cout<<count<<endl;
	}

	return 0;
}