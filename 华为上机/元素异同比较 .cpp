    #include <iostream>  
    using namespace std;  
      
    int diff_num(int arr1[],int len1,int arr2[],int len2)  
    {  
        int num=0;  
        int i=len1-1;  
        int j=len2-1;  
        int k=(len1<len2)?len1:len2;  
        k--;  
        while(k>=0)  
        {  
            if(arr1[i]!=arr2[j])  
            {  
                num++;  
                i--;  
                j--;  
                k--;  
            }  
            else  
            {  
                i--;  
                j--;  
                k--;  
            }  
        }  
        return num;  
    }  
      
      
    int main()  
    {  
        int arr1[100];  
        int arr2[100];  
        int a,k=0,b,l=0;  
      
        cin>>a;  
        while(getchar()!='\n')  
        {  
            arr1[k++]=a;  
            cin>>a;  
        }  
        arr1[k++]=a;  
      
        cin>>b;  
        while(getchar()!='\n')  
        {  
            arr2[l++]=b;  
            cin>>b;  
        }  
        arr2[l++]=b;  
      
        cout<<diff_num(arr1,k,arr2,l)<<endl;  
        return 0;  
    }  