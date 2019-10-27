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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Edge {
    int v, d;
    Edge(int v, int d) : v(v), d(d) {}
};

struct Node {
    int u, t, r;
    Node(int u, int t, int r) : u(u), t(t), r(r) {}

    bool operator < (Node o) const {
        if (t == o.t) {
            return r < o.r;
        } else {
            return t > o.t;
        }
    }
};

int N, M, L, Q;
vector<vector<Edge>> adj;
int maxR[305][305];
bool vis[305];
int memo[305][305];

int find(int s, int t) {
    memset(vis, false, sizeof(vis));
    memset(maxR, 0, sizeof(maxR));
    priority_queue<Node> q;
    q.push(Node(s, 0, L));
    while (!q.empty()) {
        Node node = q.top(); q.pop();
        int u = node.u;
        if (u == t) {
            return node.t;
        }

        if (vis[u]) {
            continue;
        }

        memo[s][u] = node.t;
        memo[u][s] = node.t;

        vis[u] = true;
        int m = adj[u].size();
        for (int k = 0; k < m; ++k) {
            int v = adj[u][k].v;
            int d = adj[u][k].d;

            if (vis[v]) {
                continue;
            }

            if (node.r >= d) {
                if (node.r - d >= maxR[node.t][v]) {
                    maxR[node.t][v] = node.r - d;
                    q.push(Node(v, node.t, node.r - d));
                }
            } else {
                if (L - d >= maxR[node.t + 1][v]) {
                    maxR[node.t + 1][v] = L - d;
                    q.push(Node(v, node.t + 1, L - d));
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &M, &L);
    for (int i = 0; i <= N; ++i) {
        adj.push_back(vector<Edge>());
    }

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(Edge(b, c));
        adj[b].push_back(Edge(a, c));
    }

    scanf("%d", &Q);
    memset(memo, -1, sizeof(memo));
    for (int q = 0; q < Q; ++q) {
        int s, t;
        scanf("%d %d", &s, &t);
        int ans = memo[s][t];
        if (ans == -1) {
            ans = find(s, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}

