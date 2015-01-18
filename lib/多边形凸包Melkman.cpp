#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
struct point
{
    double x,y;
}p[1002];
int Stack[2010];
int top,bot;
double dblcmp(double d)
{
    if(fabs(d) < eps) return 0;
    if(d > 0) return 1;
    else return -1;
}
double det(double x1,double y1,double x2,double y2)
{
    return x1 * y2 - x2 * y1;
}
double mulc(point a,point b,point c)
{
    return det(b.x - a.x,b.y - a.y,c.x - a.x,c.y - a.y);
}
double plen(point a,point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double melkman(int n)
{
    int i;
    Stack[n] = 0;
    top = n;bot = n+1;
    //开始三个点不能共线
    for(i=1;i<n;i++)
    {
        Stack[n+1] = i;
        if(dblcmp(mulc(p[Stack[n]],p[Stack[n+1]],p[i+1]))) break;
        //else Stack[++bot] = i+1;
        //包含共线的点
    }
    Stack[--top] = Stack[++bot] = i+1;

    //使栈中的点成为右手方向
    if(dblcmp(mulc(p[Stack[top]],p[Stack[top+1]],p[Stack[top+2]])) < 0)
    swap(Stack[top+1],Stack[top+2]);

    for(i=i+2;i<n;i++)
    {
        //如果是在栈顶的右手方向在栈底的左手方向则在凸包内部
        if(dblcmp(mulc(p[Stack[top+1]],p[Stack[top]],p[i])) < 0 &&
           dblcmp(mulc(p[Stack[bot-1]],p[Stack[bot]],p[i])) > 0)
           continue;

        //对两端进行Graham-Scan维护，>=不包含共线点 > 包含共线点
        while(dblcmp(mulc(p[Stack[top+1]],p[Stack[top]],p[i])) >= 0) top++;
        Stack[--top] = i;
        while(dblcmp(mulc(p[Stack[bot-1]],p[Stack[bot]],p[i])) <= 0) bot--;
        Stack[++bot] = i;
    }
    return 0;
}
int main()
{
    int n,i;
    double r,ans;
    scanf("%d%lf",&n,&r);
    for(i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
    melkman(n);
    ans = 0;
    for(i=top;i<bot;i++)
    ans += plen(p[Stack[i]],p[Stack[i+1]]);
    ans += 2*r*PI;
    printf("%.0lf\n",ans);
    return 0;
}
