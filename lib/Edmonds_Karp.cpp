������Ҫ��Ҫע�� �������رߣ��ر�ֱ�Ӽ��Ͼ��С���

 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=205;
int p[maxn],a[maxn];//p��¼���׽ڵ� ��a��¼���ǵ�i��ǰ����С�������ҽ��б��
int cap[maxn][maxn],flow[maxn][maxn];//�ֱ𱣴������������͵�ǰ������
int n;
const int INF=1<<30;

int  maxflow(int s,int t) //sΪ��㣬tΪ�յ�
{
    memset(flow,0,sizeof(flow));  //��һ��ð���Ŀ�������ǵ�����ȫΪ0�����
    int f=0;     //��¼��s������������
    queue<int> q;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;  //��ʼ�����
        q.push(s);
        while(!q.empty())  // ʹ��bfsѰ��һ������·
        {
            int u=q.front();q.pop();
            for(int v=0;v<n;v++)
            {
                if(!a[v]&&cap[u][v]>flow[u][v]) //Ѱ��Ϊ��ǵĵ㲢�ұ��в���
                {
                    p[v]=u; //��¼���׽ڵ�
                    q.push(v);
                    a[v]=a[u]<(cap[u][v]-flow[u][v])?a[u]:(cap[u][v]-flow[u][v]);  //���µ���a[i]����С����
                }
            }
        }
        if(a[t]==0) break; //�Ҳ�������·��
        for(int u=t;u!=s;u=p[u])//�� ���������
        {
            flow[p[u]][u]+=a[t]; //������������
            flow[u][p[u]]-=a[t]; //���·�������
        }
        f+=a[t];   //���� ��s������������
    }
    return f;

}

int main()
{
    int m;
    while(scanf("%d%d",&m,&n)==2)
    {
        int a,b,c;
        memset(cap,0,sizeof(cap));//���������0
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            cap[a-1][b-1]+=c;//ע������������ر�
        }
        int max=maxflow(0,n-1);
        printf("%d\n",max);
    }
    return 0;
}

