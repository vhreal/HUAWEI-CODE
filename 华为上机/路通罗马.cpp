#include<stdio.h>
#include<string.h>

int main()
{
	const int N = 10;
	int map[N][N];
	int stack[N];
	bool visited[N];

	int n,a,b;
	int Begin;
	int i,j;
	while(scanf("%d %d %d", &n, &a, &b) != EOF)
	{
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i = 0; i < n; ++i)
		{
			int index = 0;
			map[i][0] = 1;
			for(j = 0; j < n; ++j)
			{
				if(map[i][j] && i != j)
					map[i][++index] = j;//记录下可达的点				
			}
			map[i][++index] = -1;//-1结束
		}

		//深搜
		memset(visited, 0, N * sizeof(bool));
		int top = -1;
		int ans = 0;
		stack[++top] = a;//a入栈
		visited[a] = true;
		while(top > -1)//栈不空
		{
			Begin = stack[top];//取栈顶元素
			for(i = map[Begin][0]; map[Begin][i] != -1; ++i)
			{
				if(map[Begin][i] != b && !visited[map[Begin][i]])//未访问过
				{
					stack[++top] = map[Begin][i];
					visited[map[Begin][i]] = true;
					map[Begin][0] = i + 1;
					break;
				}
				if(map[Begin][i] == b)
					++ans;
			}
			if(map[Begin][i] == -1)//这个点的所有路径都走过了，退栈
			{
				--top;
			}
		}// end for while
		
		printf("%d\n", ans);		
	}

	return 0;
}
