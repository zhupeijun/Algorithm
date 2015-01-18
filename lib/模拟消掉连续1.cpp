/*
*给一个序列，每次只能对该序列的连续的子序列的每个值减去1
*求使得消掉的序列的长度最短的最长，如 2 2 3 2 2 就是2
*2 2 3 2 2 -> 1 1 2 2 2 -> 0 0 1 1 1 -> 0 0 0 0 0 
*如果a[i] <= a[i+1] 那么消掉a[i+1] 没坏处
*如果a[i] > a[i+1] 那么不消掉a[i+1] 肯定有好处，因为这样
*可以使得序列更加平均。
*所以这就是模拟每次消掉一个最长不降序列
*当b[i]减为0的时候
*如果b[i+1] > b[i] 则b[i+1]肯定还剩下 b[i+1]-b[i] 
*如果b[i+1] <= b[i] 则b[i+1]肯定为0 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10002],b[10002];
int main()
{
    int n,i,delta,l,r,ans,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        b[n] = a[n] = 0;ans = 10002;l = r =  0;
        while(r < n)
        {
            while(r < n && a[r] <= a[r+1]) r++;
            delta = a[r] - a[r+1];
            while(delta > a[l])
            {
                delta -= a[l];
                a[l+1] = max(0,b[l+1]-b[l]);
                l++;
            }
            ans = min(ans,r - l + 1);
            a[l] -= delta;
            r++;
        }
        if(ans == 10002) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
