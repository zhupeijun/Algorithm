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

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

int M[55][55], W[55][55];
int D[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
int vis[55][55];

bool check(int x, int y, int h) {
    if (M[x][y] == 0) return false;
    vis[x][y] = true;
    if (M[x][y] >= h) return true;
    for (int k = 0; k < 4; ++k) {
        int dx = x + D[k][0];
        int dy = y + D[k][1];
        if (!vis[dx][dy]) {
            bool res = check(dx, dy, h);
            if (!res) return false;
        }
    }
    return true;
}

int fill(int x, int y, int h) {
    if (vis[x][y]) return 0;
    vis[x][y] = true;
    int total = 0;
    if (M[x][y] < h) {
        total += h - M[x][y];
        M[x][y] = h;
        for (int k = 0; k < 4; ++k) {
            int dx = D[k][0] + x;
            int dy = D[k][1] + y;
            total += fill(dx, dy, h);
        }
    }
    return total;
}

void solve() {
    for (int i = 0; i < 55; ++i) {
        for (int j = 0; j < 55; ++j) {
            M[i][j] = 0;
            W[i][j] = 0;
        }
    }
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf("%d", &M[i][j]);
        }
    }

    int total = 0;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            for (int t = 0; t < 1000; ++t) {
                CL(vis, false);
                if (check(i, j, M[i][j] + 1)) {
                    CL(vis, false);
                    total += fill(i, j, M[i][j] + 1);
                } else {
                    break;
                }
            }
        }
    }
    printf("%d", total);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}

