#include <stdio.h>   
  
//ÅĞ¶ÏÊÇ·ñÎªÈòÄê
int isleapyear(int year)  
{  
    if(year%4==0 && year%100!=0 || year%400==0)  
        return 1;  
    return 0;  
}  
  
int main()  
{  
	int year,month,day;
	char a[8];
	int leap[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
	int noleap[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

	while(scanf("%s",a)!=EOF){
			year = (a[3]-'0')+(a[2]-'0')*10+(a[1]-'0')*100+(a[0]-'0')*1000;
			month = (a[5]-'0')+(a[4]-'0')*10;
			day = (a[7]-'0')+(a[6]-'0')*10;

			if(isleapyear(year)){
				printf("%d\n",leap[month-1]+day);
			}else{
				printf("%d\n",noleap[month-1]+day);
			}
	}
	return 0;
}  
