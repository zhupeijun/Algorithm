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
#define pc __builtin_popcount
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

struct Edge {
    int v, c, idx;
    bool mark;
    Edge(int v, int c, int idx, bool mark) : v(v), c(c), idx(idx), mark(mark) { }
};

const int MAXN = 105;
vector<Edge> adj[MAXN];
bool vis[MAXN];
int dist[MAXN];
pii state[MAXN];

void dijk(int st, int ed) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < MAXN; ++i) {
        vis[i] = false, dist[i] = 1000000005;
        state[i].first = state[i].second = -1;
    }
    q.push(mp(0, st)); dist[st] = 0;
    while (!q.empty()) {
        auto top = q.top(); q.pop();
        int u = top.second, d = top.first;
        vis[u] = true;
        if (state[u].first != -1 && state[u].second != -1) {
            adj[state[u].first][state[u].second].mark = true;
        }
        if (u == ed) break;
        int m = adj[u].size();
        for (int k = 0; k < m; ++k) {
            int v = adj[u][k].v;
            if (!vis[v] && adj[u][k].c + dist[u] < dist[v]) {
                dist[v] = adj[u][k].c + dist[u];
                state[v].first = u; state[v].second = k;
                q.push(mp(dist[v], v));
            }
        }
        while (!q.empty() && vis[q.top().second]) q.pop();
    }
}

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) adj[i].clear();
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c, i, false));
        adj[v].push_back(Edge(u, c, i, false));
    }

    for (int u = 0; u < N; ++u) {
        for (int v = u + 1; v < N; ++v) {
            dijk(u, v);
        }
    }

    set<int> marked;
    map<pii, int> same;
    for (int i = 0; i < N; ++i) {
        int m = adj[i].size();
        for (int j = 0; j < m; ++j) {
            if (adj[i][j].mark) {
                same[mp(i, adj[i][j].v)] = adj[i][j].c;
                marked.insert(adj[i][j].idx);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        int m = adj[i].size();
        for (int j = 0; j < m; ++j) {
            if (marked.find(adj[i][j].idx) == marked.end()) {
                auto a = mp(i, adj[i][j].v);
                if (same.find(a) != same.end() && same[a] == adj[i][j].c) {
                    marked.insert(adj[i][j].idx);
                }
                auto b = mp(adj[i][j].v, i);
                if (same.find(b) != same.end() && same[b] == adj[i][j].c) {
                    marked.insert(adj[i][j].idx);
                }
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        if(marked.find(i) == marked.end()) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

