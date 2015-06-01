#include<iostream>  
#include<string>  
#include<stack>  
using namespace std;  
 
#define inf 1000  //定义无穷远距离   
#define stanum 35 //定义总站台数  
  
string staName[stanum] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10",  
                    "A11","A12","A13","A14","A15","A16","A17","A18",  
                    "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10",  
                    "B11","B12","B13","B14","B15","T1","T2"} ; //记录车站的名字  
  

//floyd算法找出最短路径  
void floyd(int dis[][stanum],int path[][stanum])  
{  
    //初始化path矩阵  
    for(int row=0;row<stanum;row++)  
        for(int col=0;col<stanum;col++)  
            path[row][col]=row;  
  
    //找最短路径  
    for(int k=0;k<stanum;k++)  
        for(int i=0;i<stanum;i++)  
            for(int j=0;j<stanum;j++)  
                if(dis[i][j]>dis[i][k]+dis[k][j])  
                {  
                    dis[i][j]=dis[i][k]+dis[k][j];  
                    path[i][j]=path[k][j];  
                } 
				
}  
  
//转换车站的名字到矩阵的索引
int string2int(string s)  
{  
	for(int i=0;i<stanum;i++) { 
		if(s==staName[i])
		{  
			return i;  
            break;
		}  
	}
	return 0;
}  
  
void printres(int dis[][stanum],int path[][stanum],string start,string dest)  
{        
    int s;  
    int d; 
    s=string2int(start);  
    d=string2int(dest);  
    cout<<"最少经过的车站数量: "<<dis[s][d]+1<<endl; //输出站树加1包括了起始站  
  
	cout<<"经过的车站路径编号: ";
    for(int i=0;i<stanum;i++)  
        for(int j=0;j<stanum;j++)  
        {  
            if(i==s&&j==d) //输出路径  
            {  
                stack<int> pathrout;  //压栈  
                int k=j;  
                do{  
                    k=path[i][k];  
                    pathrout.push(k);  
  
                }while(k!=i);  
  
                //弹栈  
                cout<<staName[pathrout.top()];  
                pathrout.pop();  
                  
                int length=pathrout.size();  
                for(int t=0;t<length;t++)  
                {  
                    cout<<"->"<<staName[pathrout.top()];  
                    pathrout.pop();  
                      
                }  
                cout<<"->"<<staName[d]<<endl;  
				break;  
            }                  
        }   
}  
  
int main()  
{  
    int distance[stanum][stanum];  
    int path[stanum][stanum];  
    string start;  
    string dest;  
      
    //初始化连接矩阵  
    for(int i=0;i<stanum;i++)  
    {  
        for(int j=0;j<stanum;j++)  
        {  
            if(i==j)  
                distance[i][j]=0;  
            else  
                distance[i][j]=inf;  
        }  
    } 
	
    //初始化技巧  
    int sa[21]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0};  
    for(i=0;i<20;i++)  
    {  
        distance[sa[i]][sa[i+1]]=1;  
        distance[sa[i+1]][sa[i]]=1;  
    }  

    int sb[17]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};  
    for(i=0;i<16;i++)  
    {  
        distance[sb[i]][sb[i+1]]=1;  
        distance[sb[i+1]][sb[i]]=1;  
    }  
  
  
    floyd(distance,path);
	
    cout<<"输入起点和终点: "<<endl;  
    
	while(cin>>start>>dest){
		printres(distance,path,start,dest); 
		printf("\n");
	}

    return 0;  
}  