#include <stdio.h>

void print_array(int len, int array[])  
{  
    for(int i=0; i<len; i++)  
        printf("%d ", array[i]);  
    printf("\n");  
}  
 
void array_iterate(int len, int input_array[], int m, int output_array[])  
{  
    int startPos=0;  
    int outPos;  
    int nIter=len-1;  
    int num=len;  
    for(; nIter>=0; nIter--)  
    {  
        outPos=(m+startPos-1)%num;//难点，计算输出的位置  
        m=input_array[outPos];  
        startPos=outPos;  
        printf("outPos is %d, m变为 %d\n", outPos, m);  
        output_array[len-nIter-1]=m;  
        for(int i=outPos; i<num-1; i++)  
            input_array[i]=input_array[i+1];  
        num--;  
        print_array(num, input_array); //输出每次删除后的数列 
    }  
}  
void main()  
{  
    int input_array[]={3,1,2,4};  
    int output_array[4]={0};  
    array_iterate(4, input_array, 7, output_array);  
	printf("出列顺序为\n");
    print_array(4, output_array);  //最后输出output_array
} 
