#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 102;
const int INF = 0x3fffffff;
int g[maxn][maxn],f[1][maxn],mat[maxn][maxn],vis[1002],tot;
int mul(int a[maxn][maxn],int b[maxn][maxn],int n)
{
    int res[maxn][maxn],i,j,k;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        res[i][j] = INF;
        for(k=0;k<n;k++)
        {
            res[i][j] = min(a[i][k]+b[k][j],res[i][j]);
        }
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    a[i][j] = res[i][j];
    return 0;
}
int init()
{
    memset(vis,-1,sizeof(vis));
    tot = 0;
    for(int i=0;i<maxn;i++)
    {
        f[0][i] = INF;
        for(int j=0;j<maxn;j++)
        mat[i][j] = g[i][j] = INF;
        mat[i][i] = 0;
    }
    return 0;
}
int main()
{
    int n,m,s,e,l,u,v,i,ans;
    init();
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&l,&u,&v);
        if(vis[u] == -1) vis[u] = tot++;
        if(vis[v] == -1) vis[v] = tot++;
        u = vis[u];v = vis[v];
         g[u][v] = g[v][u] = l;
        if(u == vis[s]) f[0][v] = l;
        if(v == vis[s]) f[0][u] = l;
    }
    n--;
    while(n)
    {
        if(n&1) mul(mat,g,tot);
        mul(g,g,tot);
        n >>= 1;
    }
    ans = INF;
    for(i=0;i<tot;i++)
    {
        ans = min(ans,f[0][i] + mat[i][vis[e]]);
    }
    printf("%d\n",ans);
    return 0;
}

