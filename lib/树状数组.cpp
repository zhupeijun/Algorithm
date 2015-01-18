#include <iostream>

using namespace std;
const int N = 32005;
int ar[N];
int lev[N];
int lowb(int x)
{
    return x & (-x);
}
int add(int i)
{
    for(;i < N;ar[i]++,i+=lowb(i));
    return 0;
}
int sum(int i)
{
    int s = 0;
    for(;i > 0;s+=ar[i],i-=lowb(i));
    return s;
}
int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        x++;
        lev[sum(x)]++;
        add(x);
    }
    for(i=0;i<n;i++)
    printf("%d\n",lev[i]);
    return 0;
}
