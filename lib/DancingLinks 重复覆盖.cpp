#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 250;
const int M = N * N;

int L[M],R[M],U[M],D[M],C[M];
int H[N],S[N],has[N];
int size,rcnt,cnt,ans;

int mat[16][16];

void init(int m)
{
    size = m+1;
    memset(H,-1,sizeof(H));
    for(int i=0;i<=m;i++)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;R[i] = i+1;
    }
    R[m] = 0;
}
void Link(int r,int c)
{
    S[c]++;C[size] = c;
    U[size] = U[c];D[U[c]] = size;
    D[size] = c;U[c] = size;
    if(H[r] == -1) H[r] = L[size] = R[size] = size;
    else
    {
        L[size] = L[H[r]];R[L[H[r]]] = size;
        R[size] = H[r];L[H[r]] = size;
    }
    size++;
}
void remove(int c)
{
    for(int i = D[c];i != c;i = D[i])
    {
        L[R[i]] = L[i]; R[L[i]] = R[i];
    }
}
void resume(int c)
{
    for(int i = D[c];i != c;i = D[i])
    {
        L[R[i]] = R[L[i]] = i;
    }
}
int h()
{
    int i,j,k,res = 0;
    memset(has,0,sizeof(has));
    for(i=R[0];i;i=R[i])
        if(!has[i])
        {
            res++;
            for(j = D[i];j != i;j = D[j])
                for(k = R[j];k != j;k = R[k])
                    has[C[k]] = 1;
        }
    return res;
}
void dfs(int k)
{
    int Min,i,j,c;
    if(k + h() >= ans) return ;
    if(R[0] == 0)
    {
        ans = k;
        return ;
    }
    for(Min = rcnt+1,i = R[0];i;i=R[i])
        if(Min > S[i]) Min = S[i],c = i;
    for(i = D[c];i != c;i = D[i])
    {
        remove(i);
        for(j = R[i];j != i;j = R[j])
        {
            remove(j);
            S[C[j]]--;
        }
        dfs(k+1);
        for(j = L[i];j != i;j = L[j])
        {
            resume(j);
            S[C[j]]++;
        }
        resume(i);
    }
}
int main ()
{
    int rn,cn,rm,cm,x,i,j,k,l;
    //freopen("data.txt","r",stdin);
    while(scanf("%d%d",&rn,&cn)!=EOF)
    {
        cnt = rcnt = 0;
        for(i=0;i<rn;i++)
            for(j=0;j<cn;j++)
            {
                scanf("%d",&x);
                if(x == 1) mat[i][j] = ++cnt;
                else mat[i][j] = 0;
            }
        scanf("%d%d",&rm,&cm);
        init(cnt);
        for(i=0;i<rn-rm+1;i++)
            for(j=0;j<cn-cm+1;j++)
            {
                rcnt++;
                for(k = 0;k<rm;k++)
                    for(l = 0;l < cm;l++)
                        if(mat[i+k][j+l] != 0)
                            Link(rcnt,mat[i+k][j+l]);
            }
        ans = rcnt;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
