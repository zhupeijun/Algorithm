#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxn  = 405;
const int INF = 1 << 30;
int cap[maxn][maxn];
int n,f,d;
int level[maxn];
int p[maxn];//��¼���ڵ�
bool BFS()//BFS�����ֲ�����
{
    queue<int> q;
    bool flag = false;
    memset(level,0,sizeof(level));
    level[0] = 1;
    q.push(0);
    int maxv = f + n + n + d + 2;//���нڵ�
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0;v<maxv;v++)
        {
            if(cap[u][v]>0 && level[v]==0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        if(u == maxv - 1) flag = true;//�ҷֲ��������Ƿ��л�㣬�з���true
    }
    return flag;
}
int outdegree(int u)//���ȣ�Ҳ���ǲ����Ƿ�����һ�����нڵ㣬����з�������
{
    int maxv = f + n + n + d + 2;
    for(int i=0;i<maxv;i++)
    {
        if(cap[u][i]!=0 && level[i]-1 == level[u])
        return i;
    }
    return 0;//û���򷵻�0
}
int Dinic()
{
    int maxv = f + n + n + d + 2;
    int maxflow = 0;
    while(BFS())//����ֲ������л��л��
    {
        p[0] = 0;
        stack <int> s;
        s.push(0);
        while(outdegree(0) > 0)//�ֲ�������Դ��û����һ�����нڵ�
        {
            int u = s.top();
            int v;
            if(u!=maxv-1)//���ǻ��
            {
                if((v = outdegree(u))!=0)
                {
                    s.push(v);
                    p[v] = u;
                }
                else
                {
                    s.pop();
                    level[u] = 0;//ɾ��u�ڵ㣬���ضϵ�u������·��
                }
            }
            else//�����㣬���������������
            {
                int i;
                int minflow = INF;
                for(i=maxv-1;i!=0;i=p[i])//�ӻ�㵽Դ��Ѱ������·�ϵ���С������ֵ
                {
                    if(cap[p[i]][i]<minflow) minflow = cap[p[i]][i];
                }
                maxflow += minflow;
                int last = -1;
                for(i=maxv-1;i!=0;i=p[i])//��������
                {
                    cap[p[i]][i] -= minflow;
                    cap[i][p[i]] += minflow;
                    if(cap[p[i]][i] == 0) last = p[i];//�ҵ���Դ�㵽���֮���һ�����ͱ�
                }
                while(s.top()!=last)
                s.pop();//��Ϊlast����һ���㲻���ٴ�
                //last��ȥ������ȥ��last�Ժ�ĵ�ӵ�ǰλ�ü���������·
            }
        }
    }
    return maxflow;
}
int main()
{
 //   freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int i,j,x,a,b;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        memset(cap,0,sizeof(cap));
        //cin >> n >> f >> d;
        int maxv = f + n + n + d + 1;
        for(i=1;i<=f;i++)
        cap[0][i] = 1;
        for(i=f+n+n+1;i<=f+n+n+d;i++)
        cap[i][maxv] = 1;
        for(i=1;i<=n;i++)
        {
            cap[f+i][f+n+i] = 1;
        }
        for(i=1;i<=n;i++)
        {
            cin >> a >> b;
            for(j=0;j<a;j++)
            {
                cin >> x;
                cap[x][f+i] = 1;
            }
            for(j=0;j<b;j++)
            {
                cin >> x;
                cap[f+n+i][f+n+n+x] = 1;
            }
        }
        cout << Dinic() << endl;
    }
    return 0;
}
