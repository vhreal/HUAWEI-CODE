#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct MyNode{
	int number;
	struct MyNode *next;
}MyNode;

int main()
{
	MyNode *head,*tail;
	srand( (unsigned)time( NULL ) ); //随机数发生器的初始化函数
	int n=rand()%9+1;//生成1-9的随机数
	int m=rand()%5+1;//生成1-5的随机数
	printf("%d %d\n",n,m);

	for(int i=0;i<n;i++)
	{
		if(i==0)   //第一个
		{
			MyNode *cur=(MyNode *)malloc(sizeof(MyNode));
			cur->number=rand()%9+1;
			head=cur;
			tail=cur;
			head->next=tail;
			tail->next=head;
		}
		else
		{
			MyNode *cur=(MyNode *)malloc(sizeof(MyNode));
			cur->number=rand()%9+1;
			tail->next=cur;
			cur->next=head;
			tail=cur;
		}
	}

	//输出当前的链表，看看数值
	MyNode *p=head;
	for(int j=0;j<n;j++)
	{
		printf("%d ",p->number);
		p=p->next;
	}
	printf("\n");

	//开始计数
	p=head;
	MyNode *q=tail;
	while(n--)    //不用n--省去后面
	{
		for(int k=1;k<m;k++)
		{
			p=p->next;
			q=q->next;
		}
		printf("%d ",p->number);
		m=p->number;
		//删除p节点
		q->next=p->next;
		free(p);
		p=q->next;
	}
	printf("\n");
	return 0;
}