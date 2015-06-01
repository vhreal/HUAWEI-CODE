#include <iostream>  
using namespace std;  
  
int compare(const void *p,const void *q){
	return *(int *)p - *(int *)q;
}

void scheduler(int task[], int n, int system_task[], int user_task[])  
{ 
	int j=0,k=0,f;
	int sys_f=0;
	int user_f=0;

	int a[10];
	int b[10];

	for(int i=0;i<n;i++){
		if(task[i]<50)
			a[j++]=task[i];
		else if(task[i]>=50&&task[i]<=255)
			b[k++]=task[i];
	}

	qsort(a,j,sizeof(int),compare);
	qsort(b,k,sizeof(int),compare);

	for(i=0;i<j;i++){
		for(f=0;f<n;f++){
			if(a[i]==task[f]){
				system_task[sys_f++]=f;
				break;
			}
		}
	}

	for(i=0;i<k;i++){
		for(f=0;f<n;f++){
			if(b[i]==task[f]){
				user_task[user_f++]=f;
				break;
			}
		}
	}

	system_task[sys_f]=-1;
	user_task[user_f]=-1;

	for(i=0;i<=sys_f;i++){
		cout<<system_task[i]<<" ";
	}

	cout<<endl;

	for(i=0;i<=user_f;i++){
		cout<<user_task[i]<<" ";
	}

	cout<<endl;
      
}  
  
int main()  
{  
    int task[] = {0,30,155,1,80,300,170,40,99};  

    int system_task[10];  
    int user_task[10];  

    scheduler(task, 9, system_task, user_task);  
      
    return 0;  
}  