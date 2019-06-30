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

const int MAX_V = 55;
const ll INF = 10000000005LL;

struct Ladder {
    int x, a, b;

    bool operator < (const Ladder& o) const {
        return x < o.x;
    }
};

struct Edge {
    int to;
    ll cap, rev;
};

vector<Edge> g[MAX_V];
bool used[MAX_V];

ll dfs(int v, int t, ll f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        Edge &e = g[v][i];
        if (!used[e.to] && e.cap > 0) {
            ll d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll maxFlow(int s, int t) {
    ll flow = 0;
    while (true) {
        memset(used, 0, sizeof(used));
        ll f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
    return 0;
}

void addEdge(int from, int to, ll cap) {
    g[from].push_back((Edge){to, cap, (int)(g[to].size())});
    g[to].push_back((Edge){from, 0, (int)(g[from].size() - 1)});
}

void solve() {
    int N, H;
    scanf("%d %d", &N, &H);
    vector<Ladder> l(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &l[i].x, &l[i].a, &l[i].b);
    }

    sort(l.begin(), l.end());

    for (int i = 0; i < MAX_V; ++i) {
        g[i].clear();
        used[i] = false;
    }

    vector<int> a(H + 1, -1);
    for (int i = 0; i < N; ++i) {
        vector<int> cnt(N, 0);
        for (int j = l[i].a; j < l[i].b; ++j) {
            if (a[j] != -1) {
                ++cnt[a[j]];
            }
            a[j] = i;
        }
        for (int k = 0; k < N; ++k) {
            if (cnt[k] > 0) {
                addEdge(i, k, cnt[k]);
                addEdge(k, i, cnt[k]);
            }
        }
    }

    int s = N, t = N + 1;
    for (int i = 0; i < N; ++i) {
        if (l[i].a == 0) {
            addEdge(s, i, INF);
        }
        if (l[i].b == H) {
            addEdge(i, t, INF);
        }
    }

    ll f = maxFlow(s, t);
    if (f >= INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", f);
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

