#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0xfffffff;
const int N = 410;
int graph[N][N];
int cur[N],dis[N],gap[N],pre[N];
int sap(int source,int sink,int n)
{
    memset(dis,0,sizeof(dis));
    memset(cur,0,sizeof(cur));
    memset(gap,0,sizeof(gap));
    int u = source,maxflow = 0,aug = INF,v;
    gap[0] = n;pre[source] = source;
    while(dis[source] < n)
    {
        bool flag = false;
        for(v = cur[u];v < n;v++)
        if(graph[u][v] > 0 && dis[u] == dis[v] + 1)
        {
            cur[u] = v;
            pre[v] = u;
            aug = min(aug,graph[u][v]);
            u = v;
            if(v == sink)
            {
                maxflow += aug;
                for(u = pre[u];v!=source;v = u,u = pre[u])
                    graph[u][v] -= aug,graph[v][u] += aug;
                aug = INF;
            }
            flag = true;
            break;
        }
        if(flag == false)
        {
            int mind = n-1;
            for(v = 0;v<n;v++)
                if(graph[u][v] > 0 && mind > dis[v])
                    cur[u] = v,mind = dis[v];
            if(--gap[dis[u]] == 0) break;
                gap[dis[u] = mind +1]++;
            u = pre[u];
        }
    }
    return maxflow;
}
int main()
{
    int f,d,n,i,j,fn,dn,fi,di,source,sink,ans;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&fn,&dn);
            for(j=1;j<=fn;j++)
            {
                scanf("%d",&fi);
                graph[fi][f+i] = 1;
            }
            for(j=1;j<=dn;j++)
            {
                scanf("%d",&di);
                graph[f+n+i][f+n+n+di] = 1;
            }
        }
        source = 0; sink = f + n + n + d + 1;
        for(i=1;i<=f;i++) graph[source][i] = 1;
        for(i=1;i<=d;i++) graph[f+n+n+i][sink] = 1;
        for(i=1;i<=n;i++) graph[f+i][f+n+i] = 1;
        ans = sap(source,sink,sink+1);
        printf("%d\n",ans);
    }
    return 0;
}
