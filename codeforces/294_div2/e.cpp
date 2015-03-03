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

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
const int M = 30;

vector<int> adj[N];

int parent[M][N];
int depth[N], cnt[N];

int dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    int m = adj[v].size();
    cnt[v] = 1;
    for (int i = 0; i < m; i++) {
        if (adj[v][i] != p) cnt[v] += dfs(adj[v][i], v, d + 1);
    }
    return cnt[v];
}

void init() {
    dfs(0, -1, 0);
    for (int k = 0; k + 1 < M; k++) {
        for (int v = 0; v < N; v++) {
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = 0; k < M; k++) {
        if((depth[u] - depth[v]) >> k & 1) {
            u = parent[k][u];
        }
    }

    if (u == v) return u;
    for (int k = M - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int get_anc(int u, int dist) {
    for (int k = 0; k < M; k++) {
        if (dist >> k & 1) {
            u = parent[k][u];
        }
    }
    return u;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    init();

    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v, ans;
        scanf("%d %d", &u, &v);
        u--; v--;
        if (u == v) ans = n;
        else {
            int anc = lca(u, v);
            int dist = depth[u] - depth[anc] + depth[v] - depth[anc];
            if (dist & 1) ans = 0;
            else {
                if(depth[u] == depth[v]) {
                    int pu = get_anc(u, depth[u] - depth[anc] - 1);
                    int pv = get_anc(v, depth[v] - depth[anc] - 1);
                    ans = n - cnt[pu] - cnt[pv];
                } else {
                    if (depth[u] < depth[v]) swap(u, v);
                    int pu = get_anc(u, dist / 2);
                    int pud = get_anc(u, dist / 2 - 1);
                    ans = cnt[pu] - cnt[pud];
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

