#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 3005;
const int INF = 0xfffffff;
struct point
{
    int x,y;
}unb[maxn],per[maxn];
int spd[maxn];
int g[maxn][maxn],vis[maxn],dx[maxn],dy[maxn],Mx[maxn],My[maxn];
int Nx,Ny,dis;
bool SearchPath()
{
    int i,u,v;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    queue <int> q;
    for(i=0;i<Nx;i++)
    if(Mx[i] == -1)
    {
        q.push(i),dx[i] = 0;
    }
    dis = INF;
    while(!q.empty())
    {
        u = q.front();q.pop();
	if(dx[u] > dis) break;
        for(v = 0;v<Ny;v++)
        {
            if(g[u][v] && dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if(My[v] == -1) dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool DFS(int u)
{
    for(int v = 0;v < Ny;v++)
    {
        if(!vis[v] && g[u][v] && dy[v] == dx[u] + 1)
        {
            vis[v] = 1;
            if(My[v] != -1 && dy[v] == dis) continue;
            if(My[v] == -1 || DFS(My[v]))
            {
                Mx[u] = v;My[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
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
    int m,n,i,j,t,cn,cas;
    scanf("%d",&cas);
    for(cn=1;cn <= cas;cn++)
    {
        scanf("%d%d",&t,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&per[i].x,&per[i].y,&spd[i]);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&unb[i].x,&unb[i].y);
        }
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(((per[i].x - unb[j].x) * (per[i].x - unb[j].x) +
                    (per[i].y - unb[j].y) * (per[i].y - unb[j].y)) <= (spd[i] * t) * (spd[i] * t))
                {
                    g[i][j] = 1;
                }
            }
        }
        Nx = m;Ny = n;
        int ans = MaxMatch();
        printf("Scenario #%d:\n%d\n\n",cn,ans);
    }
    return 0;
}
