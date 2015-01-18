#include <stdio.h>
#include <memory.h>
#include <string.h>
typedef long long LL;
LL seg[5000050];
LL num[1000010];
LL add[5000050];
int build(int k,int L,int H)
{
    int mid = (L+H)>>1;
    int i = k<<1;
    if(L == H) seg[k] = num[L];
    else
    {
        build(i,L,mid);
        build(i+1,mid+1,H);
        seg[k] = seg[i] + seg[i+1];
    }
    return 0;
}
int update(int k,int L,int H,int l,int r,int v)
{
    int mid = (L+H)>>1;
    int i = k<<1;
    if(l <= L && r >= H)
    {
        add[k] += v;
        seg[k] += (H-L+1) * v;
        return 0;
    }
    if(add[k] != 0)
    {
        seg[i] += (mid-L+1) * add[k];
        seg[i+1] += (H-mid) * add[k];
        add[i] += add[k];
        add[i+1] += add[k];
        add[k] = 0;
    }
    if(r <= mid) update(i,L,mid,l,r,v);
    else if(l > mid) update(i+1,mid+1,H,l,r,v);
    else
    {
        update(i,L,mid,l,mid,v);
        update(i+1,mid+1,H,mid+1,r,v);
    }
    seg[k] = seg[i] + seg[i+1];
    return 0;
}
LL query(int k,int L,int H,int l,int r)
{
    int i = k<<1;
    int mid = (L+H) >> 1;
    if(L == l && r == H) return seg[k];
    if(add[k] != 0)
    {
        seg[i] += (mid-L+1) * add[k];
        seg[i+1] += (H-mid) * add[k];
        add[i] += add[k];
        add[i+1] += add[k];
        add[k] = 0;
    }
    if(r <= mid) return query(i,L,mid,l,r);
    else if(l > mid) return query(i+1,mid+1,H,l,r);
    else return query(i,L,mid,l,mid) + query(i+1,mid+1,H,mid+1,r);
}
int main ()
{
    int n,m,x,y,z,i;
    char q[2];
    memset(add,0,sizeof(add));
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    scanf("%lld",&num[i]);
    build(1,0,n-1);
    for(i=0;i<m;i++)
    {
        scanf("%s",q);
        if(strcmp(q,"Q") == 0)
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,0,n-1,x-1,y-1));
        }
        else
        {
            scanf("%d%d%d",&x,&y,&z);
            update(1,0,n-1,x-1,y-1,z);
        }
    }
    return 0;
}

