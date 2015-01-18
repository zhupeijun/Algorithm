#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

using namespace std;

const int rN = 55;
const int cN = 55;
const int M = rN * cN;
const int head = 0;

int L[M],R[M],U[M],D[M],Ci[M],Ri[M];
int Col[rN],Row[cN];
int SC[cN],SR[rN],has[rN];
int size,res;
int MAXSTEP;

int mat[30][5][30][5];
int ext[M],Map[30][5],vis[55];

void init()
{
    memset(Col,-1,sizeof(Col));
    memset(Row,-1,sizeof(Row));
    memset(Ri,-1,sizeof(Ri));
    memset(Ci,-1,sizeof(Ci));
    L[head] = R[head] = U[head] = D[head] = head;
    size = 1;
}
void insRow(int r)
{
    D[size] = D[head];
    U[D[head]] = size;
    U[size] = head;
    D[head] = size;
    L[size] = R[size] = size;
    Row[r] = size;
    Ri[size] = r;
    SR[r] = 0;
    size++;
}
void insColumn(int c)
{
    R[size] = R[head];
    L[R[head]] = size;
    L[size] = head;
    R[head] = size;
    U[size] = D[size] = size;
    Col[c] = size;
    Ci[size] = c;
    SC[c]++;
    size++;
}
void insElement(int r,int c)
{
    int rid = Row[r];
    int cid = Col[c];
    D[size] = D[cid];
    U[D[cid]] = size;
    U[size] = cid;
    D[cid] = size;
    R[size] = R[rid];
    L[R[rid]] = size;
    L[size] = rid;
    R[rid] = size;
    SC[c]++;
    SR[r]++;
    Ri[size] = r;
    Ci[size] = c;
    size++;
}
void insert(int r,int c)
{
    if(Row[r] == -1)
        insRow(r);
    if(Col[c] == -1)
        insColumn(c);
    insElement(r,c);
}
void remove(int c)
{
    int i;
    for(i = D[c];i  != c;i = D[i])
    {
        L[R[i]] = L[i];
        R[L[i]] = R[i];
    }
}
void resume(int c)
{
    int i;
    for(i = U[c];i != c;i = U[i])
    {
        L[R[i]] = R[L[i]] = i;
    }
}
int h()
{
    int i,j,k,ans = 0;
    memset(has,0,sizeof(has));
    for(i = R[head];i !=head;i = R[i])
        if(has[Ci[D[i]]] == 0)
        {
            ans++;
            for(j = D[i];j != i;j = D[j])
            {
                if(Ci[j] == -1) continue;
                for(k = R[j];k != j;k = R[k])
                {
                    if(Ci[k] == -1) continue;
                    has[Ci[k]] = 1;
                }
            }
        }
    return ans;
}
bool dfs(int k)
{
    int Min,c,i,j;
    if(k + h() >= MAXSTEP) return false;
    if(R[head] == head)
    {
        res = k;
        return true;
    }
    for(Min = INT_MAX,i = R[head];i != head;i = R[i])
        if(Min > SC[Ci[D[i]]]) Min = SC[Ci[D[i]]],c = i;
    for(i = D[c];i != c;i = D[i])
    {
        if(ext[Ri[i]] != -1 && vis[ext[Ri[i]]] == 1) continue;
        vis[Ri[i]] = 1;

        remove(i);
        for(j = R[i];j != i;j = R[j])
        {
            if(Ci[j] == -1) continue;
            remove(j);
            if(ext[Ri[j]] == -1) SC[Ci[j]] -= 1;
            else SC[Ci[j]] -= 2;
        }
        if(dfs(k+1)) return true;
        for(j = L[i];j != i;j = L[j])
        {
            if(Ci[j] == -1) continue;
            resume(j);
            if(ext[Ri[j]] == -1) SC[Ci[j]] += 1;
            else SC[Ci[j]] += 2;
        }
        resume(i);
        vis[Ri[i]] = 0;
    }
    return false;
}
int main()
{
    int n,m,K,i,j,k,rol,mod,cn,cas,cnt,l;
    int s[26];
    scanf("%d",&cas);
    for(cn = 1;cn <= cas;cn++)
    {
        scanf("%d",&n);
        cnt = 0;
        memset(mat,0,sizeof(mat));
        memset(ext,-1,sizeof(ext));
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        {
            mat[i][0][i][0] = mat[i][0][i][1] = 1;
            mat[i][1][i][0] = mat[i][1][i][1] = 1;
            scanf("%d",&m);
            s[i] = m;
            for(j=0;j<m;j++)
            {
                Map[i][j] = ++cnt;
                scanf("%d",&K);
                for(k=0;k<K;k++)
                {
                    scanf("%d%d",&rol,&mod);
                    mat[i][j][rol][mod] = 1;
                }
            }
            if(m == 2)
            {
                ext[Map[i][0]] = Map[i][1];
                ext[Map[i][1]] = Map[i][0];
            }
        }
        init();
        for(i=0;i<n;i++)
        {
            for(j=0;j<s[i];j++)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<s[k];l++)
                    {
                        if(mat[i][j][k][l] == 1)
                        {
                            insert(Map[i][j],Map[k][l]);
                        }
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        res = rN;
        MAXSTEP = 0;
        while(!dfs(0))
        {
            memset(vis,0,sizeof(vis));
            MAXSTEP ++;
        }
        printf("Case %d: ",cn);
        printf("%d\n",res);
    }
    return 0;
}
