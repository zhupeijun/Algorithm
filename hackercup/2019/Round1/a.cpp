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

struct Node {
    int v, w;
    Node(int v, int w) : v(v), w(w) {
    }
};

struct QNode {
    int u, d;
    QNode(int u, int d) : u(u), d(d) {
    }

    bool operator < (const QNode& o) const {
        return d > o.d;
    }
};

int dijkstra(int u, int target, vector<vector<Node>>& adj, int N) {
    static const int MAX_D = 100000000;
    priority_queue<QNode> q;
    int dist[N];
    bool vist[N];
    for (int i = 0; i < N; ++i) {
        dist[i] = MAX_D;
        vist[i] = false;
    }

    q.push(QNode(u, 0));
    dist[u] = 0;
    while (!q.empty()) {
        QNode t = q.top(); q.pop();
        if (vist[t.u]) {
            continue;
        }
        if (t.u == target) {
            return dist[target];
        }
        vist[t.u] = true;
        int child_count = adj[t.u].size();
        for (int i = 0; i < child_count; ++i) {
            int v = adj[t.u][i].v;
            int w = adj[t.u][i].w;

            if (!vist[v] && dist[t.u] + w < dist[v]) {
                dist[v] = dist[t.u] + w;
                q.push(QNode(v, dist[v]));
            }
        }
    }
    return MAX_D;
}

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<Node>> adj(N);
    vector<vector<int>> req;
    for (int i = 0; i < M; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        --x; --y;
        adj[x].push_back(Node(y, z));
        adj[y].push_back(Node(x, z));

        req.push_back({x, y, z});
    }

    bool possiable = true;
    for (int i = 0; i < M; ++i) {
        int min_dis = dijkstra(req[i][0], req[i][1], adj, N);
        if (min_dis != req[i][2]) {
            possiable = false;
            break;
        }
    }

    if (possiable) {
        printf("%d\n", (int)req.size());
        for (int i = 0; i < M; ++i) {
            printf("%d %d %d\n", req[i][0] + 1, req[i][1] + 1, req[i][2]);
        }
    } else {
        printf("Impossible\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

