    #include <iostream> 
    using namespace std;  
      
    int ishuiwen(char *p)  
    {  
        int len=strlen(p);  
        int flag=1;  
        for(int i=0;i<len/2;++i)  
        {  
            if(p[i]!=p[len-i-1])  
            {  
                flag=0;  
                break;  
            }  
        }  
        return flag;  
    }  
      
      
    int main()  
    {  
        char p[100];  
        while(gets(p)){   
			cout<<ishuiwen(p)<<endl;  
		}
		cout<<endl;
        return 0;  
    }  