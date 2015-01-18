#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

const int E = 40500;
const int V = 16500;

//原图
int pnt[E],nxt[E];
int head[V];
int tot;

//缩点之后的图
//ext[i]为与i对称的联通分量
int pnt_s[E],nxt_s[E];
int head_s[V],vis[V];
int tot_s;
int ext[V];

int dfn[V],low[V],sc[V];
int col[V],id[V];
int scnt,Index;

int stk[V],top;
bool instack[V];

void init(int n)
{
    int i;
    for(i = 1;i<=n;i++)
    {
        dfn[i] = low[i] = 0;
        stk[i] = false;
        head_s[i] = head[i] = -1;
        id[i] = vis[i] = 0;
    }
    scnt = tot_s = tot = Index = 0;top = -1;
}

inline void addedge(int u,int v)
{
    pnt[tot] = v;nxt[tot] = head[u];head[u] = tot++;
}

inline void addedge_s(int u,int v)
{
    pnt_s[tot_s] = v;nxt_s[tot_s] = head_s[u];head_s[u] = tot_s++;
}

void dfs(int u)
{
    int i,v;
    dfn[u] = low[u] = ++Index;
    stk[++top] = u,instack[u] = true;
    for(i = head[u];i!=-1;i=nxt[i])
    {
        v = pnt[i];
        if(!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else
        {
            if(instack[v])
            {
                low[u] = min(low[u],dfn[v]);
            }
        }
    }
    if(dfn[u] == low[u])
    {
        scnt++;
        do
        {
            v = stk[top--],instack[v] = false;
            sc[v] = scnt;
        }
        while(v != u);
    }
}

//缩点
void Tarjan(int n)
{
    int i;
    for(i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);
}

//当同一组的两个在同一连通分量里时无解
int check(int n)
{
    int i;
    for(i = 1;i<n;i+=2)
        if(sc[i] == sc[i+1]) return 0;
    return 1;
}

//求出一个解
void solve(int n)
{
    int u,v,i,j;
    //缩点构图
    for(u = 1;u <= n;u++)
    {
        //标记与联通分量sc[u]对称的联通分量
        ext[sc[u]] = sc[((u-1)^1) + 1];
        for(j = head[u];j != -1;j = nxt[j])
        {
            v = pnt[j];
            if(sc[u] != sc[v])
            {
                //要反向建图,统计入度,因为要选择已选择节点的父节点
                id[sc[u]]++;
                addedge_s(sc[v],sc[u]);
            }
        }
    }
    //拓扑排序,选择一个入度为0的节点,并删除对称的节点
    queue <int> q;
    for(i = 1;i<=scnt;i++)
        if(id[i] == 0) q.push(i);
    while(!q.empty())
    {
        u = q.front();q.pop();
		if(vis[u] == 0)
		{
			vis[u] = 1;vis[ext[u]] = -1;
		}
        for(j = head_s[u];j != -1;j = nxt_s[j])
        {
            v = pnt_s[j];
            if(vis[v] == 0 && (--id[v]) == 0)
                q.push(v);
        }
    }
}

int main()
{
    int n,m,i,u,v,N;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        N = n << 1;
        init(N);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,((v-1)^1)+1);
            addedge(v,((u-1)^1)+1);
        }
        Tarjan(N);
        if(check(N))
        {
            solve(N);
            for(i = 1;i <= N;i++)
            {
                if(vis[sc[i]] == 1) printf("%d\n",i);
            }
        }
        else printf("NIE\n");
    }
    return 0;
}
