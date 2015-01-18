#include <iostream>
#include <queue>
using namespace std;
const int INF = 1 << 30;
const int maxn = 105;
int cap[maxn][maxn];
int flow[maxn][maxn];
int p[maxn];
int d[maxn];//记录i的标号
int num[maxn];//记录标号为i的个数用于GAP优化
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
int advance(int u)//判断u后面是否有允许边有就返回v
{
    for(int i=1;i<=n;i++)
    {
        if(cap[u][i]>flow[u][i] && d[u]==d[i]+1)
        return i;
    }
    return -1;
}
int recreat(int u)//修改标号
{
    int mind = n;
    for(int i=1;i<=n;i++)
    {
        if(cap[u][i] > flow[u][i])
        mind = min(mind,d[i]);
    }
    return mind+1;//返回下一个节点中最小标号加1
}
int ISAP()
{
    build();//给图标号
    int maxflow = 0;
    memset(p,-1,sizeof(p));
    p[s] = s;
    int u = s;
    while(d[s]<n)//源点的标号超过n则跳出循环
    {
        int next = advance(u);//找允许边
        if(next!=-1)
        {
            p[next] = u;
            u = next;
            if(next == t)//如果最后是汇点，更新flow的流量
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
        else //找不到允许边，则要重新标号
        {
            int x = recreat(u);
            num[x]++;
            num[d[u]]--;
            if(num[d[u]] == 0) return maxflow;//GAP优化判断时候有断层
            d[u] = x;
            if(u!=s) u = p[u];//回到上一个节
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
