#include <iostream>
#include <memory>
#include <cstring>
#include <queue>
using namespace std;
const int kind = 26;
struct node
{
    node * fail;//失败指针
    node * next[kind];//k叉字典树的下kind个节点
    int count;//以这个为节点的单词数
    node()//node的构造函数
    {
        fail = NULL;
        count = 0;
        memset(next,0,sizeof(next));
    }
};
char key[51];//单词
char str[1000005];//文章
int insert(char * s,node * root)//向Trie树中插入单词
{
    node * p = root;
    int i=0,index;
    while(s[i])
    {
        index = s[i] - 'a';
        if(p->next[index] == NULL) p->next[index] = new node();
        p = p->next[index];
        i++;
    }
    p->count++;
    return 0;
}
int build_ac_automation(node * root)
{
    int i;
    root->fail = NULL;
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        node * temp = q.front();
        q.pop();
        node * p = NULL;
        for(i=0;i<26;i++)
        {
            if(temp->next[i] != NULL)
            {
                if(temp == root) temp->next[i]->fail = root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;//p指向p的失败指针，也就是和p相等的在离root比较近
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q.push(temp->next[i]);
            }
        }
    }
    return 0;
}
int query(node * root)
{
    int i=0,cnt=0,index;
    node * p = root;
    while(str[i])
    {
        index = str[i] - 'a';
        while(p->next[index] == NULL&&p!=root) p = p->fail;//终止条件是p到了root或者找到下面有一个点可以进行匹配
        p = p->next[index];//将p指向下一个节点
        p=(p==NULL)?root:p;//如果p指向了NULL说明在前面没有可匹配了的从root 重新开始如果不为空，说明找到了可匹配的字符
        node * temp = p;
        while(temp!=root&&temp->count!=-1)//若count为-1则其上面的都已经找过了
        {
            cnt += temp->count;//加上以这个点结尾的单词数
            temp->count = -1;//修改标志，表示这个点的单词已经匹配过
            temp=temp->fail;//找另外一个以这个字母结尾的单词
        }
        i++;
    }
    return cnt;
}
int main()
{
    int n,i,t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    node * root = new node();
    for(i=0;i<n;i++)
    {
        scanf("%s",key);
        insert(key,root);
    }
    build_ac_automation(root);
    scanf("%s",str);
    printf("%d\n",query(root));
    }
    return 0;
}
