/*
*��һ�����У�ÿ��ֻ�ܶԸ����е������������е�ÿ��ֵ��ȥ1
*��ʹ�����������еĳ�����̵������ 2 2 3 2 2 ����2
*2 2 3 2 2 -> 1 1 2 2 2 -> 0 0 1 1 1 -> 0 0 0 0 0 
*���a[i] <= a[i+1] ��ô����a[i+1] û����
*���a[i] > a[i+1] ��ô������a[i+1] �϶��кô�����Ϊ����
*����ʹ�����и���ƽ����
*���������ģ��ÿ������һ�����������
*��b[i]��Ϊ0��ʱ��
*���b[i+1] > b[i] ��b[i+1]�϶���ʣ�� b[i+1]-b[i] 
*���b[i+1] <= b[i] ��b[i+1]�϶�Ϊ0 
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
