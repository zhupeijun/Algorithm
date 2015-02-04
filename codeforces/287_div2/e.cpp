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

const int INF = 10000005;
const int N = 100005;

struct qnode {
    int v, d, rp;
    qnode(int _v, int _d, int _rp) {
        v = _v; d = _d; rp = _rp;
    }
    bool operator < (const qnode & o) const {
        if(d == o.d) return rp > o.rp;
        else return d > o.d;
    }
};

struct edge {
    int v, w, vis, ui, vi;
    edge(int _v, int _w, int _ui, int _vi) {
        v = _v; w = _w; ui = _ui, vi = _vi;
        vis = false;
    }
};

int nw[N], dis[N], rp[N], vis[N], fe[N], fn[N];
vector<edge> adj[N];

void dijkstra(int s) {
    dis[s] = rp[s] = 0;
    priority_queue<qnode> q;
    q.push(qnode(s, dis[s], rp[s]));
    while(!q.empty()) {
        qnode p = q.top(); q.pop();
        int u = p.v, m = adj[u].size();
        vis[u] = 1;
        for(int k = 0; k < m; k++) {
            int v = adj[u][k].v, w = adj[u][k].w;
            if(vis[v]) continue;
            int to_d, to_rp;
            to_d = dis[u] + 1;
            to_rp = rp[u];
            if(!w) to_rp++;
            if(to_d < dis[v] || (to_d == dis[v] && to_rp < rp[v])) {
                dis[v] = to_d;
                rp[v] = to_rp;
                q.push(qnode(v, to_d, to_rp));
                fn[v] = u;
                fe[v] = k;
            }
        }
        while(!q.empty() && vis[q.top().v]) q.pop();
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        nw[i] = 0;
        dis[i] = rp[i] = INF;
        vis[i] = 0;
        fe[i] = fn[i] = -1;
    }
    int good = 0, bad = 0;
    for(int i = 0; i < m; i++) {
        int u, v, st;
        scanf("%d %d %d", &u, &v, &st);
        u--; v--;
        int ui = adj[u].size();
        int vi = adj[v].size();
        adj[u].push_back(edge(v, st, ui, vi));
        adj[v].push_back(edge(u, st, vi, ui));
        if(!st) { nw[u]++; nw[v]++; bad++; }
        else { good++; }
    }
    int s = 0, t = n - 1;
    dijkstra(s);
    memset(vis, 0, sizeof(vis));
    int p = t, path_bad = 0;
    while(p != -1) {
        if(fn[p] != -1) {
            adj[fn[p]][fe[p]].vis = true;
            adj[p][adj[fn[p]][fe[p]].vi].vis = true;
            if(!adj[fn[p]][fe[p]].w) {
                path_bad++;
            }
        }
        p = fn[p];
    }
    printf("%d\n", good - dis[t] + path_bad * 2);
    memset(vis, 0, sizeof(vis));
    for(int u = 0; u < n; u++) {
        int sz = adj[u].size();
        vis[u] = true;
        for(int k = 0; k < sz; k++) {
            if(vis[adj[u][k].v]) continue;
            if(adj[u][k].w && !adj[u][k].vis) {
                printf("%d %d %d\n", u + 1, adj[u][k].v + 1, 0);
            }
            if(!adj[u][k].w && adj[u][k].vis) {
                printf("%d %d %d\n", u + 1, adj[u][k].v + 1, 1);
            }
        }
    }
    return 0;
}

