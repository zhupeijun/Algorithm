#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

const int rN = 2550;
const int cN = 350;
const int M = rN * cN;

int L[M],R[M],U[M],D[M],C[M],Ri[M];
int S[cN],H[rN],O[rN],mark[rN][2];
int size,rcnt,N;

int mat[cN],ans[55];

void init(int m)
{
    int i;
    size = m+1;rcnt = 0;
    memset(H,-1,sizeof(H));
    for(i=0;i<=m;i++)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;R[i] = i+1;
    }
    R[m] = 0;
}
void Link(int r,int c)
{
    //cout << mark[r][0] << " " << mark[r][1] << "  "<< r << " " << c << endl;
    S[c]++;C[size] = c;Ri[size] = r;
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
    int i,j;
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(i = D[c];i != c;i = D[i])
    {
        for(j = R[i];j != i;j = R[j])
        {
            U[D[j]] = U[j];D[U[j]] = D[j];
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
            U[D[j]] = D[U[j]] = j;
            S[C[j]]++;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}
int DFS(int k)
{
    int Min,i,j,c;
    if(k == N)
    {
        for(i=0;i<k;i++)
            ans[mark[O[i]][0]] = mark[O[i]][1];
        return 1;
    }
    for(Min = INT_MAX,i = R[0];i <= N;i=R[i])
        if(Min > S[i]) Min = S[i],c = i;
    remove(c);
    for(i = D[c];i != c;i = D[i])
    {
        O[k] = Ri[i];
        for(j = R[i];j != i;j = R[j])
            remove(C[j]);
        if(DFS(k+1)) return 1;
        for(j = L[i];j != i;j = L[j])
            resume(C[j]);
    }
    resume(c);
    return 0;
}
void addrow(int x,int y,int n)
{
    rcnt++;
    mark[rcnt][0] = x;mark[rcnt][1] = y;
    Link(rcnt,x+1);
    Link(rcnt,n+y+1);
    Link(rcnt,2*n+x+y+1);
    Link(rcnt,5*n-x+y-1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        init(6*n-2);
        N = n;
        memset(mat,0,sizeof(mat));
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            if(j != 0)
            {
                j--;
                addrow(i,j,n);
                mat[i+1] = mat[n+j+1] = mat[2*n+i+j+1] = mat[5*n-i+j-1] = 1;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(!mat[i+1] && !mat[n+j+1] && !mat[2*n+i+j+1] && !mat[5*n-i+j-1])
                addrow(i,j,n);
        memset(ans,0,sizeof(ans));
        DFS(0);
        for(i=0;i<n;i++)
        {
            printf("%d",ans[i]+1);
            if(i == n-1) putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}
