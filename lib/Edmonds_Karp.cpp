这题主要是要注意 可能有重边，重边直接加上就行。。

 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=205;
int p[maxn],a[maxn];//p记录父亲节点 ，a记录的是到i点前的最小残量并且进行标记
int cap[maxn][maxn],flow[maxn][maxn];//分别保存的是最大容量和当前的流量
int n;
const int INF=1<<30;

int  maxflow(int s,int t) //s为起点，t为终点
{
    memset(flow,0,sizeof(flow));  //这一点得按题目来，这是当流量全为0的情况
    int f=0;     //记录从s流出的总流量
    queue<int> q;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;  //初始化起点
        q.push(s);
        while(!q.empty())  // 使用bfs寻找一次增广路
        {
            int u=q.front();q.pop();
            for(int v=0;v<n;v++)
            {
                if(!a[v]&&cap[u][v]>flow[u][v]) //寻找为标记的点并且边有残量
                {
                    p[v]=u; //记录父亲节点
                    q.push(v);
                    a[v]=a[u]<(cap[u][v]-flow[u][v])?a[u]:(cap[u][v]-flow[u][v]);  //更新到达a[i]的最小残量
                }
            }
        }
        if(a[t]==0) break; //找不着增广路了
        for(int u=t;u!=s;u=p[u])//从 汇点往回走
        {
            flow[p[u]][u]+=a[t]; //更新正向流量
            flow[u][p[u]]-=a[t]; //更新反向流量
        }
        f+=a[t];   //更新 从s流出的总流量
    }
    return f;

}

int main()
{
    int m;
    while(scanf("%d%d",&m,&n)==2)
    {
        int a,b,c;
        memset(cap,0,sizeof(cap));//最大容量是0
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            cap[a-1][b-1]+=c;//注意这里可能有重边
        }
        int max=maxflow(0,n-1);
        printf("%d\n",max);
    }
    return 0;
}

