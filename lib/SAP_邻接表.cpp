#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0xfffffff;
const int E = 45000;
const int V = 405;
int pnt[E],nxt[E],cap[E];
int head[V],cur[V],gap[V],dis[V],pre[V];
int cnt;
void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int c)
{
    pnt[cnt] = v;cap[cnt] = c;nxt[cnt] = head[u];head[u] = cnt++;
    pnt[cnt] = u;cap[cnt] = 0;nxt[cnt] = head[v];head[v] = cnt++;
}
int sap(int s,int t,int n)
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    int u = s,aug = INF,maxflow = 0,i,v;
    gap[0] = n;pre[s] = s;
    for(i=0;i<n;i++) cur[i] = head[i];
    while(dis[s] < n)
    {
        bool flag = false;
        for(i = cur[u];i!=-1;i=nxt[i])
        {
            v = pnt[i];
            if(cap[i] && dis[u] == dis[v] + 1)
            {
                cur[u] = i;
                pre[v] = u;
                aug = min(aug,cap[i]);
                u = v;
                if(v == t)
                {
                    maxflow += aug;
                    for(u = pre[u];v!=s;v=u,u=pre[u])
                        cap[cur[u]] -= aug,cap[cur[u]^1] += aug;
                    aug = INF;
                }
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            int mindis = n-1;
            for(i=head[u];i!=-1;i=nxt[i])
                if(cap[i] && dis[pnt[i]] < mindis)
                    cur[u] = i,mindis = dis[pnt[i]];
            if(--gap[dis[u]] == 0) break;
            gap[dis[u] = mindis + 1]++;
            u = pre[u];
        }
    }
    return maxflow;
}
int main()
{
    int f,d,n,fi,di,fn,dn,i,j,ans,s,t;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        init();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&fn,&dn);
            for(j=0;j<fn;j++)
            {
                scanf("%d",&fi);
                addedge(fi,f+i,1);
            }
            for(j=0;j<dn;j++)
            {
                scanf("%d",&di);
                addedge(f+n+i,f+n+n+di,1);
            }
        }
        s = 0; t = f+n+n+d+1;
        for(i=1;i<=f;i++) addedge(s,i,1);
        for(i=1;i<=n;i++) addedge(f+i,f+n+i,1);
        for(i=1;i<=d;i++) addedge(f+n+n+i,t,1);
        ans = sap(s,t,t+1);
        printf("%d\n",ans);
    }
    return 0;
}
