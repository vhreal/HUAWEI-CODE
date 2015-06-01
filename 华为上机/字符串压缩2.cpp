    #include <iostream>    
    using namespace std;    
      
	int foo(int n)
	{
		int f=0;
		int m=n;
		while(m!=0)
		{
			f=f*10+m%10;
			m/=10;
		}
		
		return f;
	}


    void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)    
    {    
        int count = 1;    
        int j = 0;    
            
        for(int i = 0;i < lInputLen - 1;i++)    
        {  
            if(pInputStr[i] == pInputStr[i+1])    
                count++;  
            else    
            {    
                if(count > 1)  
                {
					int n=foo(count);
					int m;
					while(n!=0)
					{
						m=n%10;
						pOutputStr[j++] = (char)(m + '0');//注意将int型转化为char型表示.  
						n=n/10;
					}
                     
                    pOutputStr[j++] = pInputStr[i];    
                    count = 1;    
                }    
                else   
                    pOutputStr[j++] = pInputStr[i];  //count等1的情况.    
            }    
        }    
        pOutputStr[j] = '\0';    
    } 
	
	void foo1(char &a,char &b)
	{
		char tmp=a;
		a=b;
		b=tmp;
	}
        
    int main()    
    {    
        char input[20];   
        char output[20];    
      /*
        while(cin>>input){
			long len=strlen(input);
			cout<<len<<endl;
            stringZip(input,len+1, output);    
            cout << output << endl <<endl;    
        }  
      */

		char a,b;
		cin>>a>>b;
		foo1(a,b);
		cout<<a<<" "<<b<<endl;
        cout<<endl;  
            
        return 0;    
    }    