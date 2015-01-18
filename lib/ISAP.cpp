#include <iostream>
#include <queue>
using namespace std;
const int INF = 1 << 30;
const int maxn = 105;
int cap[maxn][maxn];
int flow[maxn][maxn];
int p[maxn];
int d[maxn];//��¼i�ı��
int num[maxn];//��¼���Ϊi�ĸ�������GAP�Ż�
int s,t;
int m,n;
queue <int> cal;
int build()
{
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));
    d[t] = 0;
    num[0]++;
    queue<int> q;
    q.push(t);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(cap[i][u]>0&&d[i] == -1)
            {
                d[i] = d[u] + 1;
                num[d[i]]++;
                q.push(i);
            }
        }
    }
    return 0;
}
int advance(int u)//�ж�u�����Ƿ���������оͷ���v
{
    for(int i=1;i<=n;i++)
    {
        if(cap[u][i]>flow[u][i] && d[u]==d[i]+1)
        return i;
    }
    return -1;
}
int recreat(int u)//�޸ı��
{
    int mind = n;
    for(int i=1;i<=n;i++)
    {
        if(cap[u][i] > flow[u][i])
        mind = min(mind,d[i]);
    }
    return mind+1;//������һ���ڵ�����С��ż�1
}
int ISAP()
{
    build();//��ͼ���
    int maxflow = 0;
    memset(p,-1,sizeof(p));
    p[s] = s;
    int u = s;
    while(d[s]<n)//Դ��ı�ų���n������ѭ��
    {
        int next = advance(u);//�������
        if(next!=-1)
        {
            p[next] = u;
            u = next;
            if(next == t)//�������ǻ�㣬����flow������
            {
                int minflow = INF;
                for(int i=t;i!=s;i=p[i])
                {
                    if(cap[p[i]][i]-flow[p[i]][i]<minflow)
                    minflow = cap[p[i]][i]-flow[p[i]][i];
                }
                for(int i=t;i!=s;i=p[i])
                {
                    if(p[i]!=s&&i!=t)
                    {
                        cal.push(p[i]);
                        cal.push(i);
                    }
                    flow[p[i]][i] += minflow;
                    flow[i][p[i]] -= minflow;
                }
                maxflow += minflow;
                u = s;
            }
        }
        else //�Ҳ�������ߣ���Ҫ���±��
        {
            int x = recreat(u);
            num[x]++;
            num[d[u]]--;
            if(num[d[u]] == 0) return maxflow;//GAP�Ż��ж�ʱ���жϲ�
            d[u] = x;
            if(u!=s) u = p[u];//�ص���һ����
        }
    }
    return maxflow;
}
int main()
{
    int a,b,x,y;
    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
    scanf("%d%d",&a,&b);
    n = b+a+2;
    s = 0;t = a + b;
    while(1)
    {
        scanf("%d%d",&x,&y);
        if(x == -1 && y == -1) break;
        cap[x][y] = 1;
    }
    for(int i=1;i<=a;i++)
    cap[0][i] = 1;
    for(int j=a+1;j<=n;j++)
    cap[j][t] = 1;
    printf("%d\n",ISAP());
    while(!cal.empty())
    {
        cout << cal.front() << " ";
        cal.pop();
        cout << cal.front() << " ";
        cal.pop();
        cout << endl;
    }
    return 0;
}
