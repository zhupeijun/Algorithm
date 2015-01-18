#include <iostream>

using namespace std;
int num[200010];
int seg[800010];
int build(int k,int L,int H)
{
    int mid  = (L+H)>>1;
    int i = k<<1;
    if(L == H) seg[k] = num[L];
    else
    {
        build(i,L,mid);
        build(i+1,mid+1,H);
        seg[k] = max(seg[i],seg[i+1]);
    }
    return 0;
}
int update(int k,int L,int H,int id,int v)
{
    int mid = (L+H)>>1;
    int i = k<<1;
    if(L == H) seg[k] = v;
    else
    {
        if(id <= mid)
        update(i,L,mid,id,v);
        else
        update(i+1,mid+1,H,id,v);
        seg[k] = max(seg[i],seg[i+1]);
    }
    return 0;
}
int query(int k,int L,int H,int l,int r)
{
    int mid=(L+H)>>1;
    int i = k<<1;
    if(L == l && H == r) return seg[k];
    else
    {
        if(r <= mid ) return query(i,L,mid,l,r);
        else if(l > mid) return query(i+1,mid+1,H,l,r);
        else return max(query(i,L,mid,l,mid),query(i+1,mid+1,H,mid+1,r));
    }
}
int main()
{
    int n,i,L,H,x,y,m;
    char q[2];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&num[i]);
        L = 0;H = n-1;
        build(1,L,H);
        for(i=0;i<m;i++)
        {
            scanf("%s%d%d",q,&x,&y);
            if(strcmp(q,"Q") == 0) printf("%d\n",query(1,L,H,x-1,y-1));
            else update(1,L,H,x-1,y);
        }
    }
    return 0;
}
