#include <iostream>

using namespace std;
const int maxn = 100100;
struct point
{
    int lv,rv,mv;
}seg[maxn*4];
int a[maxn];
int init(int k,int L,int H)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if(L == H)
    {
        seg[k].lv = 1;
        seg[k].rv = 1;
        seg[k].mv = 1;
    }
    else
    {
        init(i,L,mid);
        init(i+1,mid+1,H);
        seg[k].lv = seg[i].lv;
        seg[k].rv = seg[i+1].rv;
        if(a[mid] < a[mid+1])
        {
            if(seg[i].lv == (mid-L+1)) seg[k].lv += seg[i+1].lv;
            if(seg[i+1].rv == (H-mid)) seg[k].rv += seg[i].rv;
            seg[k].mv = seg[i].rv + seg[i+1].lv;
            seg[k].mv = max(seg[k].mv,max(seg[i].mv,seg[i+1].mv));
        }
        else
        seg[k].mv = max(seg[i].mv,seg[i+1].mv);
    }
    return 0;
}
int modify(int k,int L,int H,int id)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if(L == H) return 0;
    else
    {
        if(id <= mid) modify(i,L,mid,id);
        else modify(i+1,mid+1,H,id);
        seg[k].lv = seg[i].lv;
        seg[k].rv = seg[i+1].rv;
        if(a[mid] < a[mid+1])
        {
            if(seg[i].lv == (mid-L+1)) seg[k].lv += seg[i+1].lv;
            if(seg[i+1].rv == (H-mid)) seg[k].rv += seg[i].rv;
            seg[k].mv = seg[i].rv + seg[i+1].lv;
            seg[k].mv = max(seg[k].mv,max(seg[i].mv,seg[i+1].mv));
        }
        else
        seg[k].mv = max(seg[i].mv,seg[i+1].mv);
    }
    return 0;
}
int query(int k,int L,int H,int l,int r)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if(L == l && r == H) return seg[k].mv;
    else
    {
        if(r <= mid) return query(i,L,mid,l,r);
        else if(l > mid) return query(i+1,mid+1,H,l,r);
        else
        {
            if(a[mid] < a[mid+1])
            {
                int temp =  min(mid-l+1,seg[i].rv) + min(r-mid,seg[i+1].lv);
                return max(temp,max(query(i,L,mid,l,mid),query(i+1,mid+1,H,mid+1,r)));
            }
            return max(query(i,L,mid,l,mid),query(i+1,mid+1,H,mid+1,r));
        }
    }
}
int main()
{
    int n,m,x,y,L,H,i,t;
    char q[2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        L = 0;H = n-1;
        init(1,L,H);
        for(i=0;i<m;i++)
        {
            scanf("%s%d%d",q,&x,&y);
            if(strcmp(q,"Q") == 0) printf("%d\n",query(1,L,H,x,y));
            else
            {
                a[x] = y;
                modify(1,L,H,x);
            }
        }
    }
    return 0;
}
