#include<stdio.h>

typedef struct MyType
{
	int number[3][3];int level;
}MyType;

MyType queue[10000];

MyType GetHead(int n)
{
	return queue[n];
}

//是否为最终结果状态
int IsFind(MyType cur)
{
	int flag=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(cur.number[i][j]!=3*i+j+1)
			{
				flag=0;
				break;
			}
		}
	return flag;
}

int main()
{
	
	int cnt=0;//队列中数量
	int flag=0;//是否寻找到标记
	int ans=0;//最小步数,也是扩展的层数
	int head=0;//因为不是链表，用head来表示第一个
	for(int m=0;m<3;m++)
	{
		for(int n=0;n<3;n++)
		{
			scanf("%d",&queue[cnt].number[m][n]);
		}
	}
	queue[cnt].level=0;
	cnt++;
	while(cnt!=0)
	{
		//出站
		MyType cur=GetHead(head++);
		//判断是否为最终状态
		flag=IsFind(cur);
		if(flag==1)
		{
			printf("最小步数为:%d\n",cur.level);
			break;
		}
		else      //不为最终状态，进行扩展
		{
			for(int row=0;row<3;row++)
				for(int col=0;col<3;col++)
				{
					if(cur.number[row][col]==1)    //找到1,进行扩展
					{
						//将1向上移
						if(row!=0)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row-1][col];
							temp.number[row-1][col]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//将1向右移动
						if(col!=2)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row][col+1];
							temp.number[row][col+1]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//将1向下移动
						if(row!=2)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row+1][col];
							temp.number[row+1][col]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//将1向左移动
						if(col!=0)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row][col-1];
							temp.number[row][col-1]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
					}
				}
		}
	}
	return 0;
}