#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 50005;
const int M = 20;
int a[N], d[M];
int stMax[N][M];
int stMin[N][M];

void InitRMQ(const int & n)
{
    int i,j;
    for(d[0] = 1,i = 1;i < M; ++i) d[i] = d[i - 1] * 2;
    for(i = 0;i < n; ++i) stMax[i][0] = stMin[i][0] = a[i];
    int k = (int) (log(double(n)) / log(2.0)) + 1;
    for(j = 1;j < k; ++j)
        for(i = 0;i < n; ++i)
            if(i + d[j] - 1 < n)
            {
                stMax[i][j] = max(stMax[i][j-1],stMax[i + d[j-1]][j-1]);
                stMin[i][j] = min(stMin[i][j-1],stMin[i + d[j-1]][j-1]);
            }
            else break;
}
int askMax(int x,int y)
{
    int k = (int) (log(double(y - x + 1)) / log(2.0));
    return max(stMax[x][k],stMax[y - d[k] + 1][k]);
}
int askMin(int x,int y)
{
    int k = (int) (log(double(y - x + 1)) / log(2.0));
    return min(stMin[x][k],stMin[y - d[k] + 1][k]);
}
int main()
{
    int n,i,q,x,y;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    InitRMQ(n);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        x--,y--;
        printf("%d\n",askMax(x,y) - askMin(x,y));
    }
    return 0;
}
