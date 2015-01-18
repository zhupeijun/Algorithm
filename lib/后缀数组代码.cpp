#include <iostream>
#include <algorithm>
using namespace std;
const int len = 20005;
int a[len];
int sa[len];//第i大的后缀所在的位置
int rank[len];//第i个位置的后缀排第几
int height[len];//第i个位置的后缀和第i-1的位置的后缀的LCP
int temp[len];//暂存rank
int pow,n;
int cmp1(const void * i,const void * j)
{
    return a[*(const int *)i]-a[*(const int *)j];
}
int cmp2(const void * i,const void * j)
{
    const int  x = *(const int * )i;
    const int  y = *(const int * )j;
    if(temp[x]!=temp[y])
    return temp[x]-temp[y];
    else
    return temp[x+pow]-temp[y+pow];
}
int makesa()
{
    int i,p;
    for(i=1;i<=n;i++)//对sa进行初始化，即后缀的前缀长度为1
    sa[i] = i;
    qsort(sa+1,n,sizeof(int),cmp1);//对最开始的sa函数排序
    p = 0;
    for(i=1;i<=n;i++)//求rank数组
    {
        if(i==1||a[sa[i]]!=a[sa[i-1]]) p++;//如果有大小相等的则p不加
        rank[sa[i]] = p;
    }
    for(pow=1;pow<=n;pow<<=1)
    {
        for(i=0;i<=n;i++)
        temp[i] = rank[i];
        qsort(sa+1,n,sizeof(int),cmp2);
        p=0;
        for(i=1;i<=n;i++)
        {
            if(i==1||cmp2(&sa[i],&sa[i-1])!=0) p++;
            rank[sa[i]] = p;
        }
    }
    return 0;
}
int makeheight()
{
    int i,j,k = 0;
    for(i=1;i<=n;i++)
    {
        if(rank[i] == 1)
        height[rank[i]] = k = 0;
        else
        {
            if(k>0) k--;
            j = sa[rank[i]-1];
            while(a[i+k]==a[j+k]) k++;
            height[rank[i]] = k;
        }
    }
    return 0;
}
bool check(int k,int len)
{
    int count = 1 ,i;
    for(i=1;i<=n;i++)
    {
        if(height[i]>=len) count++;
        else count = 1;
        if(count >= k) return true;
    }
    return false;
}
int main ()
{
    int k,i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    makesa();
    makeheight();
    int l = 1,r = n;
    while(l<r)
    {
        int mid = ((l+r+1)>>1);
        if(check(k,mid))
        l = mid;
        else r = mid-1;
    }
    printf("%d\n",r);
    return 0;
}

