//9*9
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int rN = 729;
const int cN = 324;
const int M = (rN+1)*(cN+1);

int L[M],R[M],U[M],D[M];
int S[cN+1],H[rN+1],O[rN+1];
int C[M],mark[rN+1][2],Ri[M];
int size,rcnt;

char su[81];

void init()
{
    int i;
    memset(H,-1,sizeof(H));
    size = cN + 1;
    rcnt = 0;
    for(i = 0;i <= cN;i++)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;R[i] = i+1;
    }
    R[cN] = 0;
}

void Link(int r,int c)
{
    S[c]++;C[size]=c,Ri[size] = r;
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

void addrow(int i,int x)
{
    rcnt++;
    mark[rcnt][0] = i,mark[rcnt][1] = x;
    int r,c,p;
    r = i/9+1,c = i%9+1,p = (r-1)/3*3+(c-1)/3 + 1;
    Link(rcnt,(r-1)*9+x);
    Link(rcnt,(c-1)*9+x+81);
    Link(rcnt,(p-1)*9+x+162);
    Link(rcnt,i+1+243);
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
    for(i = U[c];i!=c;i=U[i])
    {
        for(j = L[i];j != i;j = L[j])
        {
            D[U[j]] = j;U[D[j]] = j;
            S[C[j]]++;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}

int Dance(int k)
{
    int Min,i,j,c;
    if(R[0] == 0)
    {
        for(i=0;i<k;i++)
            su[mark[O[i]][0]] = mark[O[i]][1] + '0';
        return 1;
    }
    for(Min = rN,i = R[0];i;i = R[i])
        if(Min > S[i]) Min = S[i],c = i;
    remove(c);
    for(i = D[c];i != c;i = D[i])
    {
        O[k] = Ri[i];
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
    int i,j;
    while(scanf("%s",su)!=EOF)
    {
        if(strcmp(su,"end") == 0) break;
        init();
        for(i=0;i<81;i++)
        {
            if(su[i] == '.')
                for(j=1;j<=9;j++)
                    addrow(i,j);
            else addrow(i,su[i]-'0');
        }
        Dance(0);
        printf("%s\n",su);
    }
    return 0;
}

//16*16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int rN = 4096;
const int cN = 1024;
const int M = (rN+1) * (cN + 1);

int L[M],R[M],U[M],D[M];
int S[cN+1],H[rN+1],mark[rN+1][3],O[rN+1];
int C[M],Ri[M];
int size,rcnt,head;

char su[17][17];

void init()
{
    int i;
    rcnt = 0,size = cN + 1;
    memset(H,-1,sizeof(H));
    for(i = 1;i <= cN;i++)
    {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;R[i] = i+1;
    }
    head = 0;
    L[head] = cN;
    R[head] = 1;
    R[cN] = head;
    S[head] = 10000000;
}

void Link(int r,int c)
{
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

void addrow(int i,int j,int x)
{
    rcnt++;
    mark[rcnt][0] = i,mark[rcnt][1] = j,mark[rcnt][2] = x;
    int pal,cel;
    pal = (i-1)/4*4+(j-1)/4 + 1;
    cel = (i-1)*16 + j;
    Link(rcnt,(i-1)*16 + x);
    Link(rcnt,(j-1)*16 + x + 256);
    Link(rcnt,(pal-1)*16 + x + 512);
    Link(rcnt,cel + 768);
}

void remove(int c)
{
    int i,j;
    if(c == head)
    {
        head = R[head];
    }
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(i = D[c];i != c;i = D[i])
    {
        for(j = R[i];j != i;j = R[j])
        {
            S[C[j]]--;
            D[U[j]] = D[j];U[D[j]] = U[j];
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
            S[C[j]]++;
            D[U[j]] = j;U[D[j]] = j;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}
int Dance(int k)
{
    int Min,i,j,c;
    if(R[head] == head)
    {
        for(i=0;i<k;i++)
            su[mark[O[i]][0]-1][mark[O[i]][1]-1] = mark[O[i]][2] + 'A' - 1;
        return 1;
    }

    for(Min = S[head],c = head,i = R[head];i!=head;i= R[i])
        if(Min > S[i]) Min = S[i],c = i;
    remove(c);
    for(i = D[c];i != c;i = D[i])
    {
        O[k] = Ri[i];
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
    freopen("data.txt","r",stdin);
    int i,j,k;
    while(scanf("%s",su[0]) != EOF)
    {
        for(i = 1;i<16;i++)
            scanf("%s",su[i]);
        init();
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++)
            {
                if(su[i][j] == '-')
                    for(k=1;k<=16;k++)
                        addrow(i+1,j+1,k);
                else addrow(i+1,j+1,su[i][j] - 'A' + 1);
            }
        }
        Dance(0);
        for(i=0;i<16;i++)
            printf("%s\n",su[i]);
        putchar('\n');
    }
    return 0;
}

