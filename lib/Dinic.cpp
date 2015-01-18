#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxn  = 405;
const int INF = 1 << 30;
int cap[maxn][maxn];
int n,f,d;
int level[maxn];
int p[maxn];//记录父节点
bool BFS()//BFS建立分层网络
{
    queue<int> q;
    bool flag = false;
    memset(level,0,sizeof(level));
    level[0] = 1;
    q.push(0);
    int maxv = f + n + n + d + 2;//所有节点
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0;v<maxv;v++)
        {
            if(cap[u][v]>0 && level[v]==0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        if(u == maxv - 1) flag = true;//找分层网络中是否有汇点，有返回true
    }
    return flag;
}
int outdegree(int u)//出度，也就是查找是否有下一个可行节点，如果有返回其编号
{
    int maxv = f + n + n + d + 2;
    for(int i=0;i<maxv;i++)
    {
        if(cap[u][i]!=0 && level[i]-1 == level[u])
        return i;
    }
    return 0;//没有则返回0
}
int Dinic()
{
    int maxv = f + n + n + d + 2;
    int maxflow = 0;
    while(BFS())//如果分层网络中还有汇点
    {
        p[0] = 0;
        stack <int> s;
        s.push(0);
        while(outdegree(0) > 0)//分层网络中源点没有下一个可行节点
        {
            int u = s.top();
            int v;
            if(u!=maxv-1)//不是汇点
            {
                if((v = outdegree(u))!=0)
                {
                    s.push(v);
                    p[v] = u;
                }
                else
                {
                    s.pop();
                    level[u] = 0;//删除u节点，即截断到u的所有路径
                }
            }
            else//到达汇点，更新流量和最大流
            {
                int i;
                int minflow = INF;
                for(i=maxv-1;i!=0;i=p[i])//从汇点到源点寻找增广路上的最小的流的值
                {
                    if(cap[p[i]][i]<minflow) minflow = cap[p[i]][i];
                }
                maxflow += minflow;
                int last = -1;
                for(i=maxv-1;i!=0;i=p[i])//更新流量
                {
                    cap[p[i]][i] -= minflow;
                    cap[i][p[i]] += minflow;
                    if(cap[p[i]][i] == 0) last = p[i];//找到从源点到汇点之间第一个饱和边
                }
                while(s.top()!=last)
                s.pop();//以为last的下一个点不会再从
                //last过去了所以去掉last以后的点从当前位置继续找增广路
            }
        }
    }
    return maxflow;
}
int main()
{
 //   freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int i,j,x,a,b;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        memset(cap,0,sizeof(cap));
        //cin >> n >> f >> d;
        int maxv = f + n + n + d + 1;
        for(i=1;i<=f;i++)
        cap[0][i] = 1;
        for(i=f+n+n+1;i<=f+n+n+d;i++)
        cap[i][maxv] = 1;
        for(i=1;i<=n;i++)
        {
            cap[f+i][f+n+i] = 1;
        }
        for(i=1;i<=n;i++)
        {
            cin >> a >> b;
            for(j=0;j<a;j++)
            {
                cin >> x;
                cap[x][f+i] = 1;
            }
            for(j=0;j<b;j++)
            {
                cin >> x;
                cap[f+n+i][f+n+n+x] = 1;
            }
        }
        cout << Dinic() << endl;
    }
    return 0;
}
