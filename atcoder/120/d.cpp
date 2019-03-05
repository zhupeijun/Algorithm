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

const int N = 100005;

int parent[N];
int rk[N];
int ct[N];

void make(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rk[i] = 0;
        ct[i] = 1;
    }
}

int find(int u) {
    if (u == parent[u]) {
        return u;
    } else {
        return parent[u] = find(parent[u]);
    }
}

void union_(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return;
    }

    if (rk[u] < rk[v]) {
        parent[u] = v;
        ct[v] = ct[u] + ct[v];
    } else {
        parent[v] = u;
        ct[u] = ct[u] + ct[v];
        if (rk[u] == rk[v]) {
            ++rk[u];
        }
    }
}

int main() {
    int n, m;
    scanf ("%d %d", &n, &m);
    vector<pii> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf ("%d %d", &u, &v);
        edges.push_back(make_pair(u, v));
    }

    make(n);
    vector<ll> result;
    result.push_back(1LL * n * (n - 1) / 2);
    for (int i = m - 1; i >= 0; --i) {
        int u = find(edges[i].first);
        int v = find(edges[i].second);

        ll last = result.back();
        if (u == v) {
            result.push_back(last);
        } else {
            result.push_back(last - 1LL * ct[u] * ct[v]);
            union_(u, v);
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        printf("%lld\n", result[i]);
    }
    return 0;
}

