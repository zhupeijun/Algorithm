#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1005;//点的最大数目
const int INF = 1 << 30;
struct edge
{
    int u,v,c,d;//u为前顶点，v为后节点，c为边的容量，d为两个点之间的距离
    int next;//邻接表指向下一个节点
}e[50005];
bool vit[maxn];//标记顶点是否在队列中
int dis[maxn];//源点到该点之间的最短距离
int head[maxn];//顶点的边链表的第一条边
int p[maxn];//标记父节点
int cnt,n,m;//cnt为边数
int addedge(int u,int v,int c,int d)//邻接表加边
{
    e[cnt].u = u;e[cnt].v = v;e[cnt].c = c;e[cnt].d = d;
    e[cnt].next = head[u]; head[u] = cnt ++;
    e[cnt].u = v;e[cnt].v = u;e[cnt].c = 0;e[cnt].d = -d;
    e[cnt].next = head[v]; head[v] = cnt ++;
    return 0;
}
bool SPFA(int s,int t,int n)
{
    int u,v;
    queue <int> q;
    for(int i=0;i<n;i++)
    {
        p[i] = -1;
        dis[i] = INF;
        vit[i] = false;
    }
    vit[s] = true;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        u = q.front();q.pop();
        vit[u] = false;
        for(int i = head[u];i!=-1;i=e[i].next)
        {
            if(e[i].c)
            {
                v = e[i].v;
                if(dis[v] > dis[u] + e[i].d)
                {
                    dis[v] = dis[u] + e[i].d;//松弛
                    p[v] = i;
                    if(!vit[v])//判断v是否在队列中，若不在就添加到队列中
                    {
                        vit[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    //如果走到了汇点返回true，否则返回false
    //如果为真dis[t]中的值就为找到的最短路的值
    return dis[t]!=INF;
}
int maxflow(int s,int t,int n)
{
    int ans = 0,flow = INF,i;
    while(SPFA(s,t,n))//当找不到从源点到汇点的路的时候停止
    {
	flow = INF;
        ans += dis[t];
        for(i=p[t];i!=-1;i=p[e[i].u])//查找这条路上的最小容量
        if(e[i].c<flow) flow = e[i].c;
        for(i=p[t];i!=-1;i=p[e[i].u])
        {
            e[i].c -= flow;
            e[i^1].c += flow;//i^1:i为基数-1，i为偶数+1，cnt 从0开始,i与i^1互为反向边
        }
    }
    return ans;
}
int main ()
{
  //  freopen("in.txt","r",stdin);
    int u,v,i,d;
    scanf("%d%d",&n,&m);
    for(i=0;i<n+2;i++)
    head[i] = -1;
    cnt = 0;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&d);
        addedge(u,v,1,d);//双向边
        addedge(v,u,1,d);
    }
    addedge(0,1,2,0);//添加源点
    addedge(n,n+1,2,0);//添加汇点
    printf("%d\n",maxflow(0,n+1,n+2));
    return 0;
}
