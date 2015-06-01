#include <iostream>  
using namespace std;  
  
int cal_score(int score[], int judge_type[], int n)  
{  
    int result = 0;  
    int sum1 = 0.0;  
    int sum2 = 0.0;  
    int ans = 0;//×¨¼ÒÆÀÎ¯ 

    for(int i = 0;i < n;i++)  
    {  
        if(judge_type[i] == 1)  
        {  
            ans++;  
            sum1 += score[i];  
        }  
        else if(judge_type[i] == 2)  
            sum2 += score[i];  
    }  
    if(ans == n)  
        result = sum1/ans;  
    result = 0.6*(sum1/ans) + 0.4*(sum2/(n - ans));  
    return result;  
}  
  
int main()  
{  
    int n = 10;  
    int score[10] = {80,85,90,80,75,95,80,90,95,92};  
    int judge_type[10] = {1,1,1,1,1,1,2,2,2,2};  
	
    cout << cal_score(score,judge_type,n) << endl;  
    return 0;  
}  