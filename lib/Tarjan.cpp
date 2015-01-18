/*
*Tarjan��Ҫ��ά���������飬һ����DFN[u]����DFS��ʱ����
*����һ������Low[u]����u��u��������׷�ݵ��������ջ�н�
*��ı�ţ�Ҳ����˵Low[u]������u���ܵ����������ڵ��
*�ڵ㵱DFN[u] == Low[u]��ʱ��u��������������һ��ǿ��ͨ����
*Ҳ����˵u����ͨ��u�������������µ���u��������һ�������ڻ�
*�ϵĵ㶼�����໥���Ҳ����һ��ǿ��ͨ����
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
            Bnum[Bcnt]++;//��¼ǿ��ͨ�����е����Ŀ
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
