#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1005;//��������Ŀ
const int INF = 1 << 30;
struct edge
{
    int u,v,c,d;//uΪǰ���㣬vΪ��ڵ㣬cΪ�ߵ�������dΪ������֮��ľ���
    int next;//�ڽӱ�ָ����һ���ڵ�
}e[50005];
bool vit[maxn];//��Ƕ����Ƿ��ڶ�����
int dis[maxn];//Դ�㵽�õ�֮�����̾���
int head[maxn];//����ı�����ĵ�һ����
int p[maxn];//��Ǹ��ڵ�
int cnt,n,m;//cntΪ����
int addedge(int u,int v,int c,int d)//�ڽӱ�ӱ�
{
    e[cnt].u = u;e[cnt].v = v;e[cnt].c = c;e[cnt].d = d;
    e[cnt].next = head[u]; head[u] = cnt ++;
    e[cnt].u = v;e[cnt].v = u;e[cnt].c = 0;e[cnt].d = -d;
    e[cnt].next = head[v]; head[v] = cnt ++;
    return 0;
}
bool SPFA(int s,int t,int n)
{
    int u,v;
    queue <int> q;
    for(int i=0;i<n;i++)
    {
        p[i] = -1;
        dis[i] = INF;
        vit[i] = false;
    }
    vit[s] = true;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        u = q.front();q.pop();
        vit[u] = false;
        for(int i = head[u];i!=-1;i=e[i].next)
        {
            if(e[i].c)
            {
                v = e[i].v;
                if(dis[v] > dis[u] + e[i].d)
                {
                    dis[v] = dis[u] + e[i].d;//�ɳ�
                    p[v] = i;
                    if(!vit[v])//�ж�v�Ƿ��ڶ����У������ھ���ӵ�������
                    {
                        vit[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    //����ߵ��˻�㷵��true�����򷵻�false
    //���Ϊ��dis[t]�е�ֵ��Ϊ�ҵ������·��ֵ
    return dis[t]!=INF;
}
int maxflow(int s,int t,int n)
{
    int ans = 0,flow = INF,i;
    while(SPFA(s,t,n))//���Ҳ�����Դ�㵽����·��ʱ��ֹͣ
    {
	flow = INF;
        ans += dis[t];
        for(i=p[t];i!=-1;i=p[e[i].u])//��������·�ϵ���С����
        if(e[i].c<flow) flow = e[i].c;
        for(i=p[t];i!=-1;i=p[e[i].u])
        {
            e[i].c -= flow;
            e[i^1].c += flow;//i^1:iΪ����-1��iΪż��+1��cnt ��0��ʼ,i��i^1��Ϊ�����
        }
    }
    return ans;
}
int main ()
{
  //  freopen("in.txt","r",stdin);
    int u,v,i,d;
    scanf("%d%d",&n,&m);
    for(i=0;i<n+2;i++)
    head[i] = -1;
    cnt = 0;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&d);
        addedge(u,v,1,d);//˫���
        addedge(v,u,1,d);
    }
    addedge(0,1,2,0);//���Դ��
    addedge(n,n+1,2,0);//��ӻ��
    printf("%d\n",maxflow(0,n+1,n+2));
    return 0;
}
