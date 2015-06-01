#include <stdio.h>

int main()
{
	char ch;
	
	FILE* fp;
	FILE* fp2;
	fp = fopen("f:\\11.txt","r"); //只供读取
	fp2 = fopen("f:\\12.txt","w"); //只供读取
	if(fp == NULL) //如果失败了
	{
		printf("ERROR");
		return 1;
	}

	//getc()用于在打开文件中获取一个字符
	while((ch = getc(fp)) != EOF)  //循环获取直至文件结束 EOF标志(End Of File)
		putchar(ch);  //打印获取到的字符

	//fgets(s, 2, fp); 

	int i=9;
	char *s="dfsffs";
	char chh='b';
	fprintf(fp2, "%d\n", i);
	fprintf(fp2,"%s\n",s);
	fprintf(fp2,"%c\n",chh);

	fscanf(fp2, "%d", &i);         /*读取整型数*/
    printf("%d\n", i); 

	fclose(fp); //关闭文件
	return 0;
}