#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL gcd(LL a,LL b)
{
    LL t;
    while(b){t = b;b = a % b;a = t;}
    return a;
}
LL ext_gcd(LL a,LL b,LL & x,LL & y)
{
    if(b == 0)
    {
        x = 1,y = 0;
        return a;
    }
    else
    {
        LL g = ext_gcd(b,a%b,x,y);
        LL t = x;
        x = y;
        y = t - a / b * y;
        return g;
    }
}
int main()
{
    LL a,b,x,y,m,n,l,x1,y1,g,z,ta,tb,tc;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&x1,&y1,&m,&n,&l)!=EOF)
    {
        a = m - n;
        b = l;
        z = y1 - x1;
        g = gcd(a,b);
        if(z % g == 0)
        {
            ta = a / g;tb = b / g;tc = z/g;
            ext_gcd(ta,tb,x,y);
            if(b < 0) b = -b;
            x = x * tc;
            if(x >= 0) x = x % b;
            else x = (x % b) + b;
            printf("%I64d\n",x);
        }
        else printf("Impossible\n");
    }
    return 0;
}
