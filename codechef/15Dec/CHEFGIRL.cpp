#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
const int INF = 10000005;

struct edge {
    int v, l, r;
    edge(int v, int l, int r) : v(v), l(l), r(r) {}
};

vector<edge> adj[N];
int cost[N][35][35], range[35][35], dp[35];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r);
        adj[u].pb(edge(v, l, r));
    }
    for (int i = 0; i <= 32; ++i)
        for (int j = 0; j <= 32; ++j)
            range[i][j] = INF;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int adjn = adj[u].size();
        if (adjn == 0) {
            for (int i = 1; i <= 32; ++i) {
                for (int j = 1; j <= 32; ++j) {
                    range[i][j] = min(range[i][j], cost[u][i][j]);
                }
            }
        }
        for (int k = 0; k < adjn; ++k) {
            int v = adj[u][k].v;
            q.push(v);
            for (int i = 1; i <= 32; ++i) {
                for (int j = i; j <= 32; ++j) {
                    cost[v][i][j] = cost[u][i][j];
                    if (i < adj[u][k].l)
                        cost[v][i][j] += adj[u][k].l - i;
                    if (j > adj[u][k].r)
                        cost[v][i][j] += j - adj[u][k].r;
                }
            }
        }
    }

    //for (int i = 1; i <= 32; ++i) {
    //    for (int j = 1; j <= 32; ++j) {
    //        printf("%2d ", range[i][j]);
    //     }
    //    cout << endl;
    //}
    //cout << endl;

    for (int i = 0; i <= 32; ++i) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i <= 32; ++i) {
        for (int k = i + 1; k <= 32; ++k) {
            dp[k] = min(dp[k], dp[i] + range[i + 1][k]);
        }
        //cout << dp[i] << " ";
    }
    //cout << endl;
    printf("%d\n", dp[32]);
    return 0;
}

