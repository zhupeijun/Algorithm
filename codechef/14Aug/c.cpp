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

typedef long long LL;

using namespace std;

const int N = 100005;
const int INF = 10000005;

struct edge {
    int v;
    int w;
    edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

struct node {
    int v, c;
    node(int _v, int _c) {
        v = _v;
        c = _c;
    }
    bool operator < (const node & r) const {
        return c > r.c;
    }
};

vector<edge> adj[N];
bool vis[N];
int dis[N];

int dijkstra(int s, int t, int n) {
    priority_queue<node> q;
    for(int i = 0; i < n; i++) {
        vis[i] = false;
        dis[i] = INF;
    }
    q.push(node(s, 0));
    dis[s] = 0;
    while(!q.empty()) {
        node qu = q.top(); q.pop();
        int u = qu.v;
        if(vis[u]) continue;
        vis[u] = true;
        int m = adj[u].size();
        for(int i = 0; i < m; i++) {
            edge e = adj[u][i];
            int v = e.v;
            if(!vis[v] && dis[u] + e.w < dis[v]) {
                dis[v] = dis[u] + e.w;
                q.push(node(v, dis[v]));
            }
        }
    }
    return dis[t];
}

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(edge(v - 1, 0));
        adj[v - 1].push_back(edge(u - 1, 1));
    }
    int ans = dijkstra(0, n - 1, n);
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}

