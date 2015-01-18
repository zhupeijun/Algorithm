#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1000002;
const double eps = 1e-8;
int Stack[N+2],top;
int n;
int dblcmp(double d)
{
    if(fabs(d) < eps) return 0;
    else if(d > 0) return 1;
    else return -1;
}
struct point
{
    double x,y;
}p[N];
double det(double x1,double y1,double x2,double y2)
{
    return x1 * y2 - x2 * y1;
}
double mulc(point a,point b,point c)
{
    return det(b.x - a.x,b.y - a.y,c.x - a.x,c.y - a.y);
}
int cmp(point a,point b)
{
    if(dblcmp(a.x - b.x) == 0) return dblcmp(a.y - b.y) < 0;
    else return dblcmp(a.x - b.x) < 0;
}
int Graham_scan()
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
    len = top; Stack[++top] = n-2;
    for(i=n-3;i>=0;i--)
    {
        while(top != len && dblcmp(mulc(p[Stack[top-1]],p[Stack[top]],p[i])) <= 0) top --;
        Stack[++top] =  i;
    }
    return 0;
}
double polygon_d()
{
    int p0,p1,p2;
    p0 = 0;
    p1 = p2 = 1;
    double area = 0;
    bool flag;
    while(1)
    {
        flag = false;
        while(dblcmp(mulc(p[Stack[p0]],p[Stack[p1]],p[Stack[p2]]) - mulc(p[Stack[p0]],p[Stack[p1]],p[Stack[p2+1]])) < 0)
        {
            area = max(area,mulc(p[Stack[p0]],p[Stack[p1]],p[Stack[p2+1]]));
            p2 = (p2 + 1)%top;flag = true;
        }
        while(dblcmp(mulc(p[Stack[p0]],p[Stack[p1]],p[Stack[p2]]) - mulc(p[Stack[p0]],p[Stack[p1+1]],p[Stack[p2]])) < 0)
        {
            area = max(area,mulc(p[Stack[p0]],p[Stack[p1+1]],p[Stack[p2]]));
            p1 = (p1 + 1)%top;flag = true;
        }
        while(dblcmp(mulc(p[Stack[p0]],p[Stack[p1]],p[Stack[p2]]) - mulc(p[Stack[p0+1]],p[Stack[p1]],p[Stack[p2]])) < 0)
        {
            area = max(area,mulc(p[Stack[p0+1]],p[Stack[p1]],p[Stack[p2]]));
            p0 = (p0 + 1)%top;flag = true;
        }
        if(flag == false) p2 = (p2 + 1)%top;
        if(p2 == 0) break;
    }
    return area;
}
int main()
{
    int i;
    double ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        Graham_scan();
        if(top >= 3) ans = polygon_d();
        else ans = 0;
        printf("%.2lf\n",ans/2.0);
    }
    return 0;
}
