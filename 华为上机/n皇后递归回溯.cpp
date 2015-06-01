#include <stdio.h>
#include <math.h>   
#define N 15   
  
int n; //皇后个数   
int sum = 0; //可行解个数   
int x[N]; //皇后放置的列数   
  
/*  
 *判断函数，判断第k个皇后是否可以放在某一个位置  
 *如果与之前的皇后出现在同一列或同一对角线则放置失败，返回0，否则返回1  
*/  
int place(int k)   
{   
    int i;   
    for(i=1;i<k;i++)   
      if(abs(k-i)==abs(x[k]-x[i]) || x[k] == x[i])   
        return 0;   
    return 1;   
}   
  
/*  
 *求解可行解函数，当第t个皇后可以放置在t行的某一位置时，继续放置下一皇后，直到  
 *所有皇后放置结束，如果某一皇后不能放置，则移向下一列放置，如果这一列都不能放  
 *置或所有皇后放置结束，返回上一皇后重新放置，最终返回所有可行解个数。  
*/  
int queen(int t)   
{   
    if(t>n) //当放置的皇后超过n时，可行解个数加1
      sum++;   
    else  
      for(int i=1;i<=n;i++)   
      {   
          x[t] = i; //标明第t个皇后放在第i列   
          if(place(t)) //如果可以放在某一位置，则继续放下一皇后   
            queen(t+1);    
      }   
    return sum;   
}   
  
int main()   
{   
    int t;   
    while(~scanf("%d",&n)){   
		t = queen(1);   
		if(n == 0) //如果n=0，则可行解个数为0，这种情况一定不要忽略   
		  t = 0;   
		printf("%d\n",t); 
		sum=0;
	}
    return 0;   
} 