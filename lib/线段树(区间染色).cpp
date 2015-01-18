#include <iostream>

using namespace std;
const int maxn = 100100;
int seg[maxn*4];
int add[maxn*4];
int init(int k,int L,int H)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if(L == H) seg[k] = 1;
    else
    {
        seg[k] = 1;
        init(i,L,mid);
        init(i+1,mid+1,H);
    }
    return 0;
}
int down(int k)
{
    int i = k << 1;
    seg[i] = add[k];
    seg[i+1] = add[k];
    add[i] = add[k];
    add[i+1] = add[k];
    add[k] = 0;
    return 0;
}
int modify(int k,int L,int H,int l,int r,int c)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if(L >= l && H <= r)
    {
        add[k] = (1 << (c-1));
        seg[k] = add[k];
        return 0;
    }
    if(add[k]) down(k);
    if(r <= mid) modify(i,L,mid,l,r,c);
    else if(l > mid) modify(i+1,mid+1,H,l,r,c);
    else
    {
        modify(i,L,mid,l,mid,c);
        modify(i+1,mid+1,H,mid+1,r,c);
    }
    seg[k] = seg[i]|seg[i+1];
    return 0;
}
int getn(int n)
{
    int ans = 0;
    while(n)
    {
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}
int query(int k,int L,int H,int l,int r)
{
    int mid = (L+H) >> 1;
    int i = k << 1;
    if((L == l && H == r)) return seg[k];
    if(add[k]) down(k);
    if(r <= mid) return query(i,L,mid,l,r);
    else if(l > mid) return query(i+1,mid+1,H,l,r);
    else return query(i,L,mid,l,mid)|query(i+1,mid+1,H,mid+1,r);
}
int main ()
{
    int l,t,m,L,H,i,x,y,z;
    char q[2];
    scanf("%d%d%d",&l,&t,&m);
    memset(add,0,sizeof(add));
    L = 1;H = l;
    init(1,L,H);
    for(i=0;i<m;i++)
    {
        scanf("%s",q);
        if(strcmp(q,"P") == 0)
        {
            scanf("%d%d",&x,&y);
            if(x > y) swap(x,y);
            printf("%d\n",getn(query(1,L,H,x,y)));
        }
        else
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x > y) swap(x,y);
            modify(1,L,H,x,y,z);
        }
    }
    return 0;
}
