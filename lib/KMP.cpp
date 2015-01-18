#include <iostream>
#include <cstring>
using namespace std;
int next[100];
int plen,tlen;
int getnext(char * p)
{
    next[0] = -1;
    int i=0,j=-1;
    while(i<plen)
    {
        while(j==-1 || (i<plen&&p[i] == p[j]))
        {
            i++;
            j++;
            if(p[i] == p[j]) next[i] = next[j];//优化这里的p[i]和p[j]是前后缀后面的一个字符
            else
            next[i] = j;//0到i-1之间前缀和后缀相等最长的长度为j
        }
        j = next[j];//即从next[j]的next[j]开始找
    }
    return 0;
}
int KMP(char * t,char * p)
{
    getnext(p);
    int i=0,j=0;
    while(i<tlen)
    {
        while(j==-1||(j<plen&&t[i] == p[j]))//j==-1表示当前字符与p的开始字符就不匹配
        {
            i++;
            j++;
        }
        if(j == plen) return i-j;//返回匹配成功得时候在t的位置
        j = next[j];
    }
    return -1;
}
int main ()
{
    char t[100] = "ababcdabbabababad";
    char p[100] = "abababa";
    plen = strlen(p);
    tlen = strlen(t);
    cout << KMP(t,p) << endl;
}
