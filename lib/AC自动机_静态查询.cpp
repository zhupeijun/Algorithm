#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int kind = 26;
const int N = 510100;

int root,tot;
int q[N],head,tail;
char str[1000005];

struct node
{
    int child[26];
    int fail;
    int cnt;
    void init()
    {
        memset(child,-1,sizeof(child));
        fail = -1;cnt = 0;
    }
}tr[N];
void init()
{
    root = 0;tot = 0;
    tr[root].init();
}
void insert(char * s)
{
    int index,p;
    p = root;
    while(*s)
    {
        index = *s - 'a';
        if(tr[p].child[index] == -1)
        {
            tr[++tot].init();
            tr[p].child[index] = tot;
        }
        p = tr[p].child[index];
        s++;
    }
    tr[p].cnt++;
}
void build_ac_auto()
{
    int p,u,v,i;
    head = tail = 0;
    p = root;
    q[tail++] = p;
    while(head < tail)
    {
        u = q[head++];
        for(i = 0;i<kind;i++)
        {
            if(tr[u].child[i] != -1)
            {
                v = tr[u].child[i];
                p = tr[u].fail;
                if(u == root) tr[v].fail = root;
                else tr[v].fail = tr[p].child[i];
                q[tail++] = v;
            }
            else
            {
                p = tr[u].fail;
                if(u == root) tr[u].child[i] = root;
                else tr[u].child[i] = tr[p].child[i];
            }
        }
    }
}
int query(char * str)
{
    int index,p,temp,ans;
    p = root;
    ans = 0;
    while(*str)
    {
        index = *str - 'a';
        //tr[p].child[index] 要么是虚拟节点，要么是真实节点
        //匹配的话就继续，没有匹配就从失败指针处继续找，直到到了root,说明这个字符无法匹配
        while(tr[p].child[index] == root && p != root) p = tr[p].fail;
        p = tr[p].child[index];
        temp = p;
        while(temp != root && tr[temp].cnt != -1)
        {
            ans += tr[temp].cnt;
            tr[temp].cnt = -1;
            temp = tr[temp].fail;
        }
        str++;
    }
    return ans;
}
int main ()
{
    int n,i,ans,cn,cas;
    char s[50];
    scanf("%d",&cas);
    for(cn=1;cn<=cas;cn++)
    {
        scanf("%d",&n);
        init();
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        scanf("%s",str);
        build_ac_auto();
        ans = query(str);
        printf("%d\n",ans);
    }
    return 0;
}
