#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main()
{
    string str1,str2;
    cin  >> str1 >> str2;
    int i = 0 ,j =0;
 
    vector<int> status1(26,0);
    vector<int> status2(26,0);
    vector<int> diff(26,0);
    vector<int> negative(26,0);   
    vector<int> positive(26,0);   
	
    int cntNeg = 0 , cntPos = 0;
    for( i = 0; i< str1.size(); i++)//字符串字符的哈希存储，存储每个字符的次数
    {
        char c = str1[i];
        if( 'a'<=c && c <= 'z' ){
            status1[c -'a' + 0]++;
        }
        if( 'A'<=str1[i] && str1[i] <= 'Z' ){
            status1[c-'A'+ 0]++;
        }
    }
    for( i = 0; i< str2.size(); i++)
    {
        char c = str2[i];
        if( 'a'<=str2[i] && str2[i] <= 'z' ){
            status2[c -'a' + 0]++;
        }
        if( 'A'<=str2[i] && str2[i] <= 'Z' ){
            status2[c -'A' + 0]++;
        }
    }

 
    for( i = 0; i< 26; i++)
	{
        diff[i] = status2[i] - status1[i];
        if(diff[i]<0)
        {
            negative[i] = -diff[i];
            cntNeg += negative[i];
        }
        else
        {
            positive[i] = diff[i];
            cntPos += positive[i];
        }
    }

    for( i = 0; i< 26; i++)
        cout << status1[i] <<' '<< status2[i] <<' '<< diff[i] << endl;
 
    int tmp= 0;
    int a[26],b[26];
    cout << cntNeg <<' '<< cntPos<<endl;

    for( i = 0 ; i < 26;i++ )
    {
        a[i] = 26-i;
        b[i] = i+1;
    }
 
    for( i = 0 ; i < 26;i++ )//对单词差值剩余的字符次数排序
        for(j = i+1 ;j <26;j++)
        {
            if( negative[i] < negative[j] ){
                tmp = negative[i];
                negative[i] = negative[j];
                negative[j] = tmp;
            }
        }
    for( i = 0 ; i < 26;i++ )
        for(j = i+1 ;j <26;j++)
        {
            if( positive[i] < positive[j] ){
                tmp = positive[i];
                positive[i] = positive[j];
                positive[j] = tmp;
            }
        }
 
    int out=0 , large = 0, small =0 ;
    for( i = 0 ; i < 26;i++ )
    {
        if( cntNeg >= cntPos  ) {
            large += a[i]*negative[i];   
            small += b[i]*positive[i];
        }           
        else{
            large += a[i]*positive[i];
            small += b[i]*negative[i];
        }
    }
 
    out = large - small;
    cout << "权重差值："<<out <<endl;
 
    return 0;
}