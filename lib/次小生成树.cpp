/*
��С���������ò�����С�������еı��滻����С�������еı߶��õ�
Max��u��v��Ψһ��·���ϱ�Ȩֵ����ֵ
pre�ǵ�i������ʱ�丸�ڵ㣬Ҳ����˵pre[i]��i����С�������ϵı�
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int INF = 0xfffffff;
int cost[102][102];
int n,m;
int Max[102][102],lowc[102];
int visv[102],vise[102][102],pre[102];
int prim()
{
    int i,res,minc,j,p;
    memset(visv,0,sizeof(visv));
    res = 0;visv[0] = 1;
    for(i=1;i<n;i++) {lowc[i] = cost[0][i];pre[i] = 0;}
    for(i=1;i<n;i++)
    {
        minc = INF;p = -1;
        for(j=0;j<n;j++)
        if(0 == visv[j] && lowc[j] < minc)
        {
            minc = lowc[j];
            p = j;
        }
        res += minc;visv[p] = 1;
        vise[pre[p]][p] = vise[p][pre[p]] = 1;
        for(j=0;j<n;j++)
        if(0 == visv[j] && lowc[j] > cost[p][j])
        {
            lowc[j] = cost[p][j];
            pre[j] = p;
        }
        else if(1 == visv[j])
        Max[p][j] = Max[j][p] = max(Max[j][pre[p]],minc);
    }
    return res;
}
int init()
{
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            cost[i][j] = cost[j][i] = INF;
            Max[i][j] = Max[j][i] = 0;
            vise[i][j] = vise[j][i] = 0;
        }
    return 0;
}
int main()
{
    int u,v,i,j,c,ans,res,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            cost[u-1][v-1] = cost[v-1][u-1] = c;
        }
        res = prim();
		ans = INF;//��ʾ��С����������С�������Ĳ�ֵres+ans���Ǵ�С��������ֵ
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(vise[i][j] == 0 && Max[i][j] - cost[i][j] >= 0)
        ans = min(Max[i][j]-cost[i][j],ans);
        if(ans == 0) printf("Not Unique!\n");
        else printf("%d\n",res);
    }
    return 0;
}
