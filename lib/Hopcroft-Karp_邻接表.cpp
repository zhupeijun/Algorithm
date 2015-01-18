#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

typedef long long LL;

const LL INF = 1LL << 60;
const int maxn = 105;
const int maxm = 1005;
const int E = 1000005;

LL dis[maxn][maxn];

int pnt[E],nxt[E];
int head[maxm];
int cnt;

int dx[maxm],dy[maxm],Mx[maxm],My[maxm],vis[maxm];
int dist,Nx,Ny;

inline void addedge(int u,int v)
{
    pnt[cnt] = v;nxt[cnt] = head[u];head[u] = cnt++;
}

void init()
{
    int i,j;
    cnt = 0;
    memset(head,-1,sizeof(head));
    for(i=0;i<maxn;i++)
    {
        dis[i][i] = 0;
        for(j=i+1;j<maxn;j++)
        {
            dis[j][i] = dis[i][j] = INF;
        }
    }
}

void floyd(int n)
{
    int i,j,v;
    for(v = 0;v < n;v++)
        for(i = 0;i< n;i++)
            for(j = 0;j < n;j++)
                if(dis[i][j] > dis[i][v] + dis[v][j])
                dis[i][j] = dis[i][v] + dis[v][j];
}

struct node
{
    int pi,ti;
}que[maxm];

bool SearchPath()
{
    int i,u,v;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    queue <int> q;
    for(u = 0;u < Nx;u++)
    if(Mx[u] == -1)
    {
        q.push(u);dx[u] = 0;
    }
    dist = (0xfffffff);
    while(!q.empty())
    {
        u = q.front();q.pop();
        if(dx[u] > dist) break;
        for(i = head[u];i!=-1;i=nxt[i])
        {
            v = pnt[i];
            if(dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if(My[v] == -1) dist = dy[v];
                else
                {
                    q.push(My[v]);
                    dx[My[v]] = dy[v] + 1;
                }
            }
        }
    }
    return dist != (0xfffffff);
}

bool DFS(int u)
{
    for(int i = head[u];i!=-1;i=nxt[i])
    {
        int v = pnt[i];
        if(!vis[v] && dy[v] == dx[u] + 1)
        {
            vis[v] = 1;
            if(My[v] != -1 && dy[v] == dist) continue;
            if(My[v] == -1 || DFS(My[v]))
            {
                Mx[u] = v;My[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMathch()
{
    int res = 0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(SearchPath())
    {
        memset(vis,0,sizeof(vis));
        for(int u = 0;u < Nx;u++)
            if(Mx[u] == -1 && DFS(u)) res++;
    }
    return res;
}
int main()
{
    int N,M,Q,i,j,u,v,c,cn,cas;
    scanf("%d",&cas);
    for(cn = 1;cn <= cas;cn ++)
    {
        scanf("%d%d%d",&N,&M,&Q);
        init();
        Nx = Ny = Q;
        for(i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(c < dis[u][v])
                dis[u][v] = dis[v][u] = c;
        }
        floyd(N);

        for(i=0;i<Q;i++)
        {
            scanf("%d%d",&que[i].pi,&que[i].ti);
        }

        for(i=0;i<Q;i++)
        {
            for(j=i+1;j<Q;j++)
            {
                u = que[i].pi;
                v = que[j].pi;

                if(que[i].ti - que[j].ti >= dis[u][v])
                addedge(j,i);

                if(que[j].ti - que[i].ti >= dis[v][u])
                addedge(i,j);
            }
        }

        int ans = MaxMathch();
        printf("Case %d: %d\n",cn,Q - ans - 1);
    }
    return 0;
}
