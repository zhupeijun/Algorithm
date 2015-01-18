#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;
LL ans;
LL gcd(LL a,LL b)
{
    LL t;
    while(b){t = b;b = a % b;a = t;}
    return a;
}
LL multi(LL a,LL b,LL n)
{
    LL ret = 0;
    while(b)
    {
        if(b&1)
        {
            ret = ret + a;
            if(ret >= n) ret -= n;
        }
        a = a + a;
        if(a >= n) a -= n;
        b = b >> 1;
    }
    return ret;
}
LL Pow(LL a,LL b,LL n)
{
    LL ret = 1;
    while(b)
    {
        if(b&1) ret = multi(ret,a,n);
        a = multi(a,a,n);
        b = b >> 1;
    }
    return ret;
}
int witness(LL a,LL n)
{
    LL u = n - 1,t = 0,x,y,i;
    while(!(u&1)) u >>= 1,t++;
    x = Pow(a,u,n);
    for(i = 1;i<=t;i++)
    {
        y = multi(x,x,n);
        if(y == 1 && x != 1 && x != n-1) return 1;
        x = y;
    }
    if(x != 1) return 1;
    return 0;
}
int Miller_Rabin(LL n,int s = 20)
{
    if((n == 1) || (n != 2 && !(n%2))) return 0;
    srand((LL)time(0));
    while(s--)
    {
        LL a = ((LL)rand())%(n-1) + 1;
        if(witness(a,n)) return 0;
    }
    return 1;
}
LL Pollord_rho(LL n,LL c)
{
    srand(time(0));
    LL x = ((LL)rand())%n + 1;
    LL y = x;
    int i = 1;
    int k = 2;
    while(1)
    {
        i++;
        x = (multi(x,x,n) + c) % n;
        LL d = gcd(y - x + n,n);
        if(d != 1  && d != n) return d;
        if(y == x) return n;
        if(i == k) y = x,k = k << 1;
    }
}
void find(LL n,LL c)
{
    if(n <= 1) return;
    if(Miller_Rabin(n))
    {
        if(ans > n) ans = n;
        return;
    }
    LL d = Pollord_rho(n,c--);
    find(n/d,c);
    find(d,c);
}
int main ()
{
    LL n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        ans = n;
        if(Miller_Rabin(n)) printf("Prime\n");
        else
        {
            find(n,91);
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
