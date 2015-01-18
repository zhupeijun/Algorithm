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
            if(p[i] == p[j]) next[i] = next[j];//�Ż������p[i]��p[j]��ǰ��׺�����һ���ַ�
            else
            next[i] = j;//0��i-1֮��ǰ׺�ͺ�׺�����ĳ���Ϊj
        }
        j = next[j];//����next[j]��next[j]��ʼ��
    }
    return 0;
}
int KMP(char * t,char * p)
{
    getnext(p);
    int i=0,j=0;
    while(i<tlen)
    {
        while(j==-1||(j<plen&&t[i] == p[j]))//j==-1��ʾ��ǰ�ַ���p�Ŀ�ʼ�ַ��Ͳ�ƥ��
        {
            i++;
            j++;
        }
        if(j == plen) return i-j;//����ƥ��ɹ���ʱ����t��λ��
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
