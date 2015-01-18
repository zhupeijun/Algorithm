#include <iostream>

using namespace std;
int cost[101][101],lowc[101];
bool vis[101];
const int INF = 1 << 30;
int n;
int prim()
{
    int i,j,res = 0;
    memset(vis,false,sizeof(vis));
    vis[0] = true;
    for(i=1;i<n;i++) lowc[i] = cost[0][i];
    for(i=1;i<n;i++)
    {
        int minc = INF,p = -1;
        for(j=0;j<n;j++)
        {
            if(vis[j] == false && lowc[j] < minc)
            {
                minc = lowc[j];p = j;
            }
        }
        vis[p] = true;res += minc;
        for(j=0;j<n;j++)
        {
            if(vis[j] == false && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
        }
    }
    return res;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&cost[i][j]);
        printf("%d\n",prim());
    }
    return 0;
}
