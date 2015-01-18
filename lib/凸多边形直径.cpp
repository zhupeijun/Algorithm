/*求点集直径
先对点集求凸包，要去掉共线的点，
然后对凸包进行旋转卡壳求对踵点
的最大距离,计算叉积的时候必须
是有向面积*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 50005;
const double eps = 1e-8;
struct point
{
    double x,y;
}p[N];
int n,top;
int Stack[N+1];
int dblcmp(double d)
{
    if(fabs(d) < eps) return 0;
    if(d > 0) return 1;
    else return -1;
}
int cmp(point a,point b)
{
    if(dblcmp(a.y - b.y) == 0)
    return (dblcmp(a.x - b.x) < 0);
    else return (dblcmp(a.y - b.y) < 0);
}
double det(double x1,double y1,double x2,double y2)
{
    return x1 * y2 - x2 * y1;
}
double mulc(point a,point b,point c)
{
    return det(b.x - a.x,b.y - a.y,c.x - a.x,c.y - a.y);
}
int Graham_Scan()
{
    int i,len;
    sort(p,p+n,cmp);
    top = -1;
    if(n == 0) return 0;Stack[++top] = 0;
    if(n == 1) return 0;Stack[++top] = 1;
    if(n == 2) return 0;top = 1;
    for(i=2;i<n;i++)
    {
        while(top && dblcmp(mulc(p[Stack[top-1]],p[Stack[top]],p[i])) <= 0) top--;
        Stack[++top] = i;
    }
    len = top;Stack[++top] = n-2;
    for(i=n-3;i>=0;i--)
    {
        while(top != len && dblcmp(mulc(p[Stack[top-1]],p[Stack[top]],p[i])) <= 0) top--;
        Stack[++top] = i;
    }
    return 0;
}
double plen(point a,point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double polygon_d()
{
    int pl,ql,p0,q0;
    double ans,temp;
    ans = 0;
    pl = 0;
    ql = pl+1;
    p0 = top;
    while(dblcmp(mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql+1]])
               - mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql]])) > 0)
    ql = ql + 1;//找到一个对踵点
    q0 = ql;
    while(pl != q0)
    {
        pl = pl+1;
        temp = plen(p[Stack[pl]],p[Stack[ql]]);
        if(dblcmp(ans - temp) < 0) ans = temp;
        while(dblcmp(mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql+1]])
        - mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql]])) > 0)
           {
               ql = ql+1;
               if(pl == q0  && ql == p0) return ans;
               else
               {
                   temp = plen(p[Stack[pl]],p[Stack[ql]]);
                   if(dblcmp(ans - temp) < 0) ans = temp;
               }
           }
        if(dblcmp(mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql+1]])
           - mulc(p[Stack[pl]],p[Stack[pl+1]],p[Stack[ql]])) == 0)
           {
               if(pl == q0 && ql == p0)
               {
                   temp = plen(p[Stack[pl+1]],p[Stack[ql]]);
                   if(dblcmp(ans - temp) < 0) ans = temp;
               }
               else
               {
                   temp = plen(p[Stack[pl]],p[Stack[ql+1]]);
                   if(dblcmp(ans - temp) < 0) ans = temp;
               }
           }
    }
    return ans;
}
int main()
{
    int i;
    double ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
    Graham_Scan();
    ans = polygon_d();
    printf("%.0lf\n",ans*ans);
    return 0;
}
