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
#include <list>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 505;
const int HOURS = 24;
const int INF = 1000005;

struct edge {
    int v;
    vector<int> c;
    edge(int v, const vector<int>& c) : v(v), c(c) {}
};

vector<edge> adj[MAXN];
int dist_res[MAXN][HOURS];
int dist[MAXN];
bool vis[MAXN];

struct qnode {
    int v, t, d;
    qnode(int v, int t, int d) : v(v), t(t), d(d) {}
    inline bool operator<(const qnode& r) const {
        return d > r.d;
    }
};

void dijk(int st, int hour) {
    for (int i = 0; i < MAXN; ++i) {
        dist[i] = INF;
        vis[i] = false;
    }
    priority_queue<qnode> q;
    q.push(qnode(st, hour, 0));
    dist[st] = 0;
    while (!q.empty()) {
        auto top = q.top(); q.pop();
        int u = top.v, t = top.t;
        vis[u] = true;
        int m = adj[u].size();
        for (int k = 0; k < m; ++k) {
            int v = adj[u][k].v, c = adj[u][k].c[t];
            int dh = (t + adj[u][k].c[t]) % HOURS;
            if (!vis[v] && dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                q.push(qnode(v, dh, dist[v]));
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
    }
}

void solve() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < MAXN; ++i) adj[i].clear();
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        vector<int> cost = vector<int>(HOURS);
        for (int j = 0; j < HOURS; ++j) {
            scanf("%d", &cost[j]);
        }
        adj[u].push_back(edge(v, cost));
        adj[v].push_back(edge(u, cost));
    }
    for (int i = 0; i < HOURS; ++i) {
        dijk(1, i);
        for (int j = 1; j <= N; ++j) {
            dist_res[j][i] = dist[j];
        }
    }
    for (int i = 0; i < K; ++i) {
        int D, S;
        scanf("%d %d", &D, &S);
        if (i != 0) printf(" ");
        printf("%d", dist_res[D][S] == INF ? -1 : dist_res[D][S]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}

