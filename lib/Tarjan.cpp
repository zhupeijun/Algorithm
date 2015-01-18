/*
*Tarjan主要是维护两个数组，一个是DFN[u]代表DFS的时候标号
*还有一个数组Low[u]代表u或u的子树能追溯到的最早的栈中节
*点的编号，也就是说Low[u]代表了u所能到达的最靠近根节点的
*节点当DFN[u] == Low[u]的时候u的生成子树就是一个强连通分量
*也就是说u可以通过u的生成子树重新到达u，即类似一个环，在环
*上的点都可以相互到达，也就是一个强连通分量
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int E = 50002;
const int V = 10002;
int pnt[E],nxt[E];
int head[V],DFN[V],Low[V],Instack[V],Belong[V],deg[V],Bnum[V];
int cnt,Index,Bcnt,Ncnt;
int Stack[V],top;
void init()
{
    cnt = Bcnt = Index = 0;top = -1;
    for(int i=0;i<V;i++)
    {
        head[i] = -1;
        DFN[i] = Instack[i] = Belong[i] = deg[i] = Bnum[i]  = 0;
    }
}
inline void addedge(int u,int v)
{
    pnt[cnt] = v;nxt[cnt] = head[u];head[u] = cnt++;
}
int Tarjan(int u)
{
    int i,v;
    DFN[u] = Low[u] = ++Index;
    Instack[u] = true;
    Stack[++top] = u;
    for(i = head[u];i!=-1;i=nxt[i])
    {
        v = pnt[i];
        if(!DFN[v])
        {
            Tarjan(v);
            Low[u] = min(Low[u],Low[v]);
        }
        else
        {
            if(Instack[v])
            Low[u] = min(Low[u],DFN[v]);
        }
    }
    if(DFN[u] == Low[u])
    {
        Bcnt++;
        do
        {
            v = Stack[top--];
            Instack[v] = false;
            Belong[v] = Bcnt;
            Bnum[Bcnt]++;//记录强连通分量中点的数目
        }
        while(v != u);
    }
    return 0;
}
int main()
{
    int n,m,i,j,u,v,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for(i=1;i<=n;i++)
        if(!DFN[i]) Tarjan(i);
        for(u=1;u<=n;u++)
        {
            for(j=head[u];j!=-1;j=nxt[j])
            {
                v = pnt[j];
                if(Belong[u] != Belong[v]) deg[Belong[u]]++;
            }
        }
        int num = 0;
        for(i=1;i<=Bcnt;i++)
        {
            if(deg[i] == 0) {ans = Bnum[i];num++;}
            if(num == 2) break;
        }
        if(num > 1) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}
