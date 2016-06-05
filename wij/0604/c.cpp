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

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[105];
int vis[105], dist[105];

const int INF = 1000000;

int dijk(int u, int v, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        vis[i] = false; dist[i] = INF;
    }
    q.push(make_pair(0, u));
    for (int i = 0; i < n; ++i) {
        if (q.empty()) break;
        auto top = q.top(); q.pop();
        dist[top.second] = top.first;
        vis[top.second] = true;
        if (top.second == v) return dist[v];
        for (int t : adj[top.second]) {
            if (!vis[t] && (dist[top.second] + 1 < dist[t])) {
                dist[t] = dist[top.second] + 1;
                q.push(make_pair(dist[t], t));
            }
        }
        while (!q.empty() && vis[q.top().second]) q.pop();
    }
    return -1;
}

int main() {
    int V, Q;
    cin >> V >> Q;
    for (int i = 1; i < V; ++i) {
        adj[i - 1].pb(i);
    }
    while (Q--) {
        int u, v;
        cin >> u >> v;
        int res = dijk(u - 1, v - 1, V);
        cout << res << endl;
        adj[u - 1].pb(v - 1);
    }
    return 0;
}

