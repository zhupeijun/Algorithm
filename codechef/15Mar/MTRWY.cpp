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

const int N = 1005;
const int M = 1000005;

int mat[N][N], wr[N][N], wc[N][N], query[M][5];
int par[N * N], size[N * N];

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool has_wall(int x1, int y1, int x2, int y2, int d) {
    if (d == 0)
        return wc[x2][y2];
    else if(d == 1)
        return wr[x1][y1];
    else if(d == 2)
        return wc[x1][y1];
    else
        return wr[x2][y2];
}

void bfs(int x, int y, int s, int n, int m) {
    queue<int> q;
    q.push(x); q.push(y);
    mat[x][y] = s;
    while(!q.empty()) {
        int tx = q.front(); q.pop();
        int ty = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = tx + dir[i][0], ny = ty + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] < 0) {
                if (!has_wall(tx, ty, nx, ny, i)) {
                    mat[nx][ny] = s;
                    q.push(nx); q.push(ny);
                }
            }
        }
    }
}

void init(int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            mat[i][j] = -1;
            wr[i][j] = wc[i][j] = 0;
        }
}

void init_node(int sn) {
    for(int i = 0; i < sn; i++)
        par[i] = i;
}

int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    par[x] = y;
    size[y] = size[x] + size[y];
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int set_size(int x) {
    return size[find(x)];
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        init(n, m);
        for(int i = 0; i < q; i++) {
            int qt;
            scanf("%d", &qt);
            query[i][0] = qt;
            if(qt == 1 || qt == 2) {
                int x, y;
                scanf("%d %d", &x, &y);
                x--; y--;
                query[i][1] = x; query[i][2] = y;
                if (qt == 1) wr[x][y] ++;
                else if (qt == 2) wc[x][y] ++;
            }
            else if(qt == 3) {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1--; y1--; x2--; y2--;
                query[i][1] = x1; query[i][2] = y1;
                query[i][3] = x2; query[i][4] = y2;
            }
        }

        int s = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] < 0) {
                    bfs(i, j, s, n, m);
                    s++;
                }
            }
        }
        for(int i = 0; i < s; i++) size[i] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                size[mat[i][j]]++;
        init_node(s);
        int maxv = 0;
        for(int i = 0; i < s; i++) maxv = max(maxv, size[i]);
        ll ans = 0;
        for(int i = q - 1; i >= 0; i--) {
            if (query[i][0] == 1) {
                int x1 = query[i][1], y1 = query[i][2];
                int x2 = x1, y2 = y1 + 1;
                int s1 = mat[x1][y1], s2 = mat[x2][y2];
                wr[x1][y1] --;
                if(wr[x1][y1] == 0) {
                    unite(s1, s2);
                    maxv = max(set_size(s1), maxv);
                }
            } else if(query[i][0] == 2) {
                int x1 = query[i][1], y1 = query[i][2];
                int x2 = x1 + 1, y2 = y1;
                int s1 = mat[x1][y1], s2 = mat[x2][y2];
                wc[x1][y1] --;
                if(wc[x1][y1] == 0) {
                    unite(s1, s2);
                    maxv = max(set_size(s1), maxv);
                }
            } else if(query[i][0] == 3) {
                int x1 = query[i][1], y1 = query[i][2];
                int x2 = query[i][3], y2 = query[i][4];
                int s1 = mat[x1][y1], s2 = mat[x2][y2];
                if(same(s1, s2)) ans++;
            } else {
                ans = ans + maxv;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

