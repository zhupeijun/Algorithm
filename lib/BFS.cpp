#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct edge
{
    int a;
    int b;
};
stack <edge> E;
queue <int> P;
int map[100][100];
int num[100];
int flag;
int n = 7;
int breadFirstSearch()
{
    int i,j;
    for(i=0;i<n;i++)
    num[i] = 0;
    flag = 1;
    for(i=0;i<n;i++)
    {
        if(num[i] != 0) continue;
        num[i] = flag++;
        P.push(i);
        while(!P.empty())
        {
            int v = P.front();
            P.pop();
            for(j=0;j<n;j++)
            {
                if(map[v][j] == 1)
                {
                    if(num[j] == 0)
                    {
                        num[j] = flag++;
                        P.push(j);
                        edge x;
                        x.a = v;
                        x.b = j;
                        E.push(x);
                    }
                }
            }
        }
    }
    while(!E.empty())
    {
        cout << E.top().a << " "<< E.top().b << endl;
        E.pop();
    }
    return 0;
}
int main()
{
    int i,j;
    freopen("in1.txt","r",stdin);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin >> map[i][j];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout << map[i][j] << " ";
        cout << endl;
    }
    breadFirstSearch();
    return 0;
}
