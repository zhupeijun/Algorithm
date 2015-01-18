/*求s到t的第k短路
*先反向求每个点到t的最短路，然后从s到t进行搜索
*每个点出队列K次就是到达每个点的K短路，加上从
*这个点到达t的最短路就是从从s经过该点到达点t的
*第K短路，当t出队K次的时候就是s到t的第K短路 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int V = 1002;
const int E = 100002;
int pnt[E],nxt[E],head[V],cost[E],pnt_r[E],head_r[V],nxt_r[E],cost_r[E],dist[V];
int vis[V];
int cnt,cnt_r;
struct qnode
{
    int v,c;
    qnode(int tv = 0,int tc = 0) {v = tv;c = tc;}
    bool operator < (const qnode & t) const {return c > t.c;}
};
inline int addedge(int u,int v,int c)
{
    pnt[cnt] = v;cost[cnt] = c;nxt[cnt] = head[u];head[u] = cnt++;
    pnt_r[cnt_r] = u;cost_r[cnt_r] = c;nxt_r[cnt_r] = head_r[v];head_r[v] = cnt_r++;
    return 0;
}
int init()
{
    cnt = cnt_r = 0;
    memset(head,-1,sizeof(head));
    memset(head_r,-1,sizeof(head_r));
    for(int i=0;i<V;i++) dist[i] = INF;
    return 0;
}
int dijkstra(int s,int t,int n)
{
    int p,i,j,v;
    priority_queue <qnode> q;
    memset(vis,0,sizeof(vis));
    q.push(qnode(s,0));
    vis[s] = 1;dist[s] = 0;
    for(p = s,i=1;i<n;i++)
    {
        for(j=head_r[p];j!=-1;j=nxt_r[j])
        {
            v = pnt_r[j];
            if(vis[v] == 0 && dist[p] + cost_r[j] < dist[v])
            {
                dist[v] = dist[p] + cost_r[j];
                q.push(qnode(v,dist[v]));
            }
        }
        while(!q.empty() && vis[q.top().v] == 1) q.pop();
        vis[p = q.top().v] = 1;q.pop();
    }
    return dist[t];
}
int A_star(int s,int t,int k)
{
    int j;
    qnode u,v;
    priority_queue <qnode> q;
    memset(vis,0,sizeof(vis));
    q.push(qnode(s,dist[s]));
    if(dist[t] == INF) return -1;
    while(!q.empty())
    {
        u = q.top();q.pop();
        vis[u.v]++;
        if(u.v == t && vis[t] == k) return u.c;
        if(vis[u.v] <= k)
        for(j=head[u.v];j!=-1;j=nxt[j])
        {
            v.v = pnt[j];
            v.c = u.c - dist[u.v] + cost[j] + dist[v.v];
            q.push(v);
        }
    }
    return -1;
}
int main()
{
    int n,m,u,v,c,i,s,t,k,ans;
    scanf("%d%d",&n,&m);
    init();
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        addedge(u-1,v-1,c);
    }
    scanf("%d%d%d",&s,&t,&k);
    if(s == t) k++;
    dijkstra(t-1,s-1,n);
    ans = A_star(s-1,t-1,k);
    printf("%d\n",ans);
    return 0;
}
