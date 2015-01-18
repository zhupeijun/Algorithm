#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;
const int M = 1000010;
int L[M],R[M],U[M],D[M];
int C[M],H[M],mark[M];
int S[N],O[N];
int size;
void init(int n,int m)
{
    size = m+1;
    memset(H,-1,sizeof(H));
    memset(mark,0,sizeof(mark));
    for(int i=0;i<=m;i++)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;R[i] = i+1;
    }
    L[0] = m;R[m] = 0;
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
    mark[size] = r;
    size++;
}
void remove(int c)
{
    int i,j;
    R[L[c]] = R[c];
    L[R[c]] = L[c];
    for(i = D[c];i != c;i = D[i])
    {
        for(j = R[i];j != i;j = R[j])
        {
            D[U[j]] = D[j];U[D[j]] = U[j];
            S[C[j]]--;
        }
    }
}
void resume(int c)
{
    int i,j;
    for(i = U[c];i != c;i = U[i])
    {
        for(j = L[i];j != i;j = L[j])
        {
            D[U[j]] = j;U[D[j]] = j;
            S[C[j]]++;
        }
    }
    R[L[c]] = c;
    L[R[c]] = c;
}
int Dance(int k)
{
    int i,j,Min,c;
    if(R[0] == 0)
    {
        printf("%d ",k);
        for(i = 0;i < k; i++)
        {
            printf("%d",mark[O[i]]);
            if(i == k - 1) putchar('\n');
            else putchar(' ');
        }
        return 1;
    }
    for(Min = N,i = R[0]; i ;i = R[i])
        if(Min > S[i]) Min = S[i],c = i;
    remove(c);
    for(i = D[c];i != c;i = D[i])
    {
        O[k] = i;
        for(j = R[i];j != i;j = R[j])
            remove(C[j]);
        if(Dance(k+1)) return 1;
        for(j = L[i];j != i;j = L[j])
            resume(C[j]);
    }
    resume(c);
    return 0;
}
int main()
{
    int n,m,i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(n,m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&j);
                Link(i,j);
            }
        }
        if(!Dance(0)) printf("NO\n");
    }
    return 0;
}
