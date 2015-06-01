#include <stdio.h>    
#include <string.h>    
 
#define MAX 100      
//100位大数相减   

int bigNumSub(char a[],char b[],char sub[])    
{  
    int i=0;    
    int c=0;//判断是否够减，0够减，1不够减 
  
    //清0  
    char m[MAX]={0};  //被减数大于减数
    char n[MAX]={0};  //减数
    memset(sub,0,100);    
        
    //字符串反转且字符串变数字    
    int lenA=strlen(a);    
    int lenB=strlen(b);  
             
    for (i=0;i<lenA;i++)    
    {    
       m[i]=a[lenA-i-1]-'0';  
	   //printf("%d",m[i]);   
    } 
    for (i=0;i<lenB;i++)    
    {    
       n[i]=b[lenB-i-1]-'0';
	   //printf("%d",n[i]); 
    }    
	
    //位运算：够减不借位，不够减借位，并且后一位减一   
    for (i=0;i<lenA;i++)    
    {  
		c=(m[i]-n[i])<0?1:0;
		sub[i]=m[i]+10*c-n[i]+'0';//加'0'转换
		if(i+1==lenA)
			break;
		m[i+1]-=c;
    } 

    return lenA;   
}     
  
  
void print(char sub[],int lenA)    
{    
    int i;
	int k;//第一个不为0的数字
 
    for(i=lenA-1; i>=0; i--)    
    { 
		if(sub[i]!='0'){
			k=i;
			break;
		}
	}
	for(i=k;i>=0;i--){
        printf("%c",sub[i]);    
    }     
}   
  
int main()    
{   
    char a[MAX];    
    char b[MAX];    
    char sub[MAX];    
    puts("input a:");    
    gets(a);    
    puts("input b:");    
    gets(b); 
    print(sub,bigNumSub(a,b,sub));   
	printf("\n");
    return 0;    
}    