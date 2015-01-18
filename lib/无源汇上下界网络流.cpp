#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int V = 250;
const int E = 85000;
const int INF = 0xfffffff;

int pnt[E],nxt[E],cap[E];
int head[V],cur[V],gap[V],dis[V],pre[V];
int cb[E],fb[E];
int In[V],Out[V];
int cnt;
void init(int n)
{
    int i;
    cnt = 0;
    for(i=0;i<n;i++)
        In[i] = Out[i] = 0,head[i] = -1;
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
    int u = s,ang = INF,maxflow = 0,i,v;
    gap[0] = n;pre[s] = s;
    for(i=0;i<n;i++) cur[i] = head[i];
    while(dis[s] < n)
    {
        bool flag = false;
        for(i = cur[u];i != -1;i = nxt[i])
        {
            v = pnt[i];
            if(cap[i] && dis[u] == dis[v] + 1)
            {
                cur[u] = i;
                pre[v] = u;

                ang = min(ang,cap[i]);
                u = v;
                if(v == t)
                {
                    maxflow += ang;
                    for(u = pre[v];v != s;v = u,u = pre[u])
                        cap[cur[u]] -= ang,cap[cur[u]^1] += ang;
                    ang = INF;
                }
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            int mindis = n - 1;
            for(i = head[u];i != -1;i = nxt[i])
                if(cap[i] && dis[pnt[i]] < mindis)
                    mindis = dis[pnt[i]],cur[u] = i;
            if(--gap[dis[u]] == 0) break;
            gap[dis[u] = mindis + 1]++;
            u = pre[u];
        }
    }
    return maxflow;
}
int check(int s)
{
    int i;
    for(i=head[s];i != -1;i = nxt[i])
        if(cap[i]) return 0;
    return 1;
}
int main()
{
    int n,m,u,v,c,b,i,M;
    int s,t;
    scanf("%d%d",&n,&m);
    s = 0;t = n+1;
    init(n+2);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&u,&v,&b,&c);
        addedge(u,v,c-b);
        cb[i] = c;fb[i] = b;
        In[v] += b;Out[u] += b;
    }
    for(i=1;i<=n;i++)
    {
        M = In[i] - Out[i];
        if(M >= 0) addedge(s,i,M);
        else addedge(i,t,-M);
    }
    sap(s,t,n+2);
    if(check(s))
    {
        printf("YES\n");
        for(i=0;i<m;i++)
            printf("%d\n",fb[i] + cap[i*2+1]);
    }
    else printf("NO\n");
    return 0;
}
