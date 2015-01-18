/*
*POJ1151
*矩形面积并
*由于mid的原因，数组得开5倍
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int st,ed,c;
    double m;
}seg[1202];
struct line
{
    double x,y1,y2;
    int s;
}l[205];
double y[205],ty[205];
int cmp(line a,line b)
{
    return a.x < b.x;
}
int search(double x,int n)
{
    int l,r,mid;
    l = 0,r = n-1;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(x > y[mid]) l = mid + 1;
        else if(x < y[mid]) r = mid - 1;
        else return mid;
    }
    return 0;
}
int build(int root,int st,int ed)
{
    seg[root].st = st;
    seg[root].ed = ed;
    seg[root].c = 0;
    seg[root].m = 0;
    if(ed - st > 1)
    {
        int mid = (st + ed) >> 1;
        build(root*2,st,mid);
        build(root*2+1,mid,ed);
    }
    return 0;
}
int update(int root)
{
    if(seg[root].c > 0)
    seg[root].m = y[seg[root].ed] - y[seg[root].st];
    else if(seg[root].st - seg[root].ed == 1)
    seg[root].m = 0;
    else seg[root].m = seg[root*2].m + seg[root*2+1].m;
    return 0;
}
int modify(int root,int st,int ed,int v)
{
    if(st <= seg[root].st && ed >= seg[root].ed)
    {
        seg[root].c += v;
        update(root);
        return 0;
    }
    int mid = (seg[root].st + seg[root].ed) >> 1;
    if(st < mid) modify(root*2,st,ed,v);
    if(ed > mid) modify(root*2+1,st,ed,v);
    update(root);
    return 0;
}
int main()
{
    int n,i,tot,k;
    double area;
    k = 1;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0) break;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&l[2*i].x,&l[2*i].y1,&l[2*i+1].x,&l[2*i].y2);
            l[2*i+1].y2 = l[2*i].y2;
            l[2*i+1].y1 = l[2*i].y1;
            l[2*i].s = 1;
            l[2*i+1].s = -1;
            ty[i*2] = l[2*i].y1;
            ty[i*2+1] = l[2*i].y2;
        }
        n <<= 1;
        sort(l,l+n,cmp);
        sort(ty,ty+n);
        y[0] = ty[0];tot = 1;
        for(i=1;i<n;i++)
        if(ty[i] != ty[i-1]) y[tot++] = ty[i];
        build(1,0,tot-1);
        area = 0;
        for(i=0;i<n;i++)
        {
            if(i > 0) area += seg[1].m * (l[i].x - l[i-1].x);
            modify(1,search(l[i].y1,tot),search(l[i].y2,tot),l[i].s);
        }
        printf("Test case #%d\n",k++);
        printf("Total explored area: %.2lf\n\n",area);
    }
    return 0;
}
