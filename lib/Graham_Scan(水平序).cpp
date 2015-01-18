/*poj1228*/
/*��һ��͹������ȥ��һЩ��֮���ж�ʣ�µĵ��Ƿ����Ψһȷ��ԭ����͹��
���ҽ���ÿ�������������ϵĵ��ʱ�����ȷ������Ϊ�������ֻ���������
��������������һ����Ϳ����γ�һ���µ�͹��������е�Ļ����ӵ����ʹ
����͹���ϵĵ����͹���ڲ�*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
struct point
{
    double x,y;
}p[1002];
int top;
int Stack[1002];
int cmph(point a,point b)
{
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}
int dblcmp(double d)
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
//�������е������� < ���������ߵ������� <=
int Graham_scan(int n)
{
    int i,len;
    top = 1;
    Stack[0] = 0;Stack[1] = 1;
    for(i=2;i<n;i++)
    {
        while(top && dblcmp(mulc(p[Stack[top-1]],p[Stack[top]],p[i])) < 0) top--;
        Stack[++top] = i;
    }
    len = top;Stack[++top] = n-2;
    for(i=n-3;i>=0;i--)
    {
        while(top != len && dblcmp(mulc(p[Stack[top-1]],p[Stack[top]],p[i])) < 0) top--;
        Stack[++top] = i;
    }
    return 0;
}
int jud()
{
    int i,cnt;
    i = 0;
    //�ж����е��Ƿ���
    while(i<=top-2&&dblcmp(mulc(p[Stack[i]],p[Stack[i+1]],p[Stack[i+2]])) == 0) i++;
    if(i > top-2) return 0;
    for(++i;i<=top-2;i++)
    {
        cnt = 0;
        while(i<=top-2&&dblcmp(mulc(p[Stack[i]],p[Stack[i+1]],p[Stack[i+2]])) == 0) {i++;cnt++;}
        if(cnt == 0) return 0;
    }
    return 1;
}
int main()
{
    int n,i,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(n<=5) {printf("NO\n");continue;}
        sort(p,p+n,cmph);
        Graham_scan(n);
        if(jud()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
