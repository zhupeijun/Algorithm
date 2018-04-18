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
#include <climits>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

struct Edge {
    int i, j, w;
    Edge (int i, int j, int w) : i(i), j(j), w(w) {}
};

vector<vector<int>> circle;
vector<vector<int>> d_in_circle;
vector<Edge> edges;
vector<int> d_circle;

int min_dis (int c, int u, int v, int n) {
    int dx1 = d_in_circle[c][u] - d_in_circle[c][v];
    int dx2 = d_in_circle[c][v] + d_in_circle[c][n] - d_in_circle[c][u];
    return min(dx1, dx2);
}

void query (int n, int N) {
    int v1, c1, v2, c2;
    scanf ("%d %d %d %d", &v1, &c1, &v2, &c2);

    if (c2 < c1) { swap(v1, v2); swap (c1, c2); }

    int d1 = d_circle[c2 - 1] - d_circle[c1 - 1];
    // v1 -> edges[c1].j
    int u = v1, v = edges[c1].j;
    if (u < v) { swap (u, v); }
    int dis = min_dis (c1, u, v, n);

    int ux2 = v2, vx2 = edges[c2].i;
    if (ux2 < vx2) { swap (ux2, vx2); }
    int dis2 = min_dis(c2, ux2, vx2, n);

    int total_dis1 = d1 + dis + dis2;

    int d2 = d_circle[c1] + d_circle[N] - d_circle[c2];
    int uc2 = v1, vc2 = edges[c1].i;
    if (uc2 < vc2) swap (uc2, vc2);
    int disc2 = min_dis(c1, uc2, vc2, n);

    int uc4 = v2, vc4 = edges[c2].j;
    if (uc4 < vc4) swap (uc4, vc4);
    int disc4 = min_dis (c2, uc4, vc4, n);

    int total_dis2 = d2 + disc2 + disc4;

    printf ("%d\n", min(total_dis1, total_dis2));
}

void solve () {
    int N, Q, n;
    scanf ("%d %d", &N, &Q);
    for (int i = 0; i < N; ++i) {
        scanf ("%d", &n);
        circle.push_back (vector<int> (n));
        for (int j = 0; j < n; ++j) {
            scanf ("%d", &circle[i][j]);
        }

        d_in_circle.pb (vector<int>(n + 1));
        d_in_circle[i][0] = 0;
        for (int j = 1; j <= n; ++j) {
            d_in_circle[i][j] = d_in_circle[i][j - 1] + circle[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        int u, v, w;
        scanf ("%d %d %d", &u, &v, &w);
        edges.pb (Edge (u, v, w));
    }

    d_circle.pb (0);
    for (int i = 1; i <= N; ++i) {
        d_circle.pb(d_circle[i - 1] + edges[i - 1].w);
    }

    for (int i = 0; i < Q; ++i) {
        query (n, N);
    }
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

