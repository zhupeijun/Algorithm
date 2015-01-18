#include <iostream>
#include <memory>
#include <cstring>
#include <queue>
using namespace std;
const int kind = 26;
struct node
{
    node * fail;//ʧ��ָ��
    node * next[kind];//k���ֵ�������kind���ڵ�
    int count;//�����Ϊ�ڵ�ĵ�����
    node()//node�Ĺ��캯��
    {
        fail = NULL;
        count = 0;
        memset(next,0,sizeof(next));
    }
};
char key[51];//����
char str[1000005];//����
int insert(char * s,node * root)//��Trie���в��뵥��
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
                        p = p->fail;//pָ��p��ʧ��ָ�룬Ҳ���Ǻ�p��ȵ�����root�ȽϽ�
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
        while(p->next[index] == NULL&&p!=root) p = p->fail;//��ֹ������p����root�����ҵ�������һ������Խ���ƥ��
        p = p->next[index];//��pָ����һ���ڵ�
        p=(p==NULL)?root:p;//���pָ����NULL˵����ǰ��û�п�ƥ���˵Ĵ�root ���¿�ʼ�����Ϊ�գ�˵���ҵ��˿�ƥ����ַ�
        node * temp = p;
        while(temp!=root&&temp->count!=-1)//��countΪ-1��������Ķ��Ѿ��ҹ���
        {
            cnt += temp->count;//������������β�ĵ�����
            temp->count = -1;//�޸ı�־����ʾ�����ĵ����Ѿ�ƥ���
            temp=temp->fail;//������һ���������ĸ��β�ĵ���
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
