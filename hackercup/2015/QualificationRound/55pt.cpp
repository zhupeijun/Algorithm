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

const int N = 105;
const int INF = 1000005;
char maze[N][N];
bool valid[4][N][N];
const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int dis[4][N][N];

int get_dir(char c) {
    if(c == '^') return 0;
    else if(c == '>') return 1;
    else if(c == 'v') return 2;
    else if(c == '<') return 3;
    else return -1;
}

bool good(int x,int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void init(int n, int m) {
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                valid[k][i][j] = (maze[i][j] == '.');
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int d = get_dir(maze[i][j]);
                if(d == -1) continue;
                d = (d + k) % 4;
                int dx = dir[d][0], dy = dir[d][1], x = i + dx, y = j + dy;
                while(good(x, y, n, m) && maze[x][y] == '.') {
                    valid[k][x][y] = false;
                    x += dx;
                    y += dy;
                }
            }
        }
    }

    for(int k = 0; k < 4; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dis[k][i][j] = INF;
}

int bfs(int sx, int sy, int tx, int ty, int n, int m) {
    queue<int> q;
    q.push(sx); q.push(sy); q.push(0);
    dis[0][sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int s = q.front(); q.pop();

        for(int k = 0; k < 4; k++) {
            int dx = dir[k][0], dy = dir[k][1];
            int cx = x + dx, cy = y + dy, cs = (s + 1) % 4;
            if(good(cx, cy, n, m) && valid[cs][cx][cy] && dis[cs][cx][cy] > dis[s][x][y] + 1) {
                dis[cs][cx][cy] = dis[s][x][y] + 1;
                q.push(cx); q.push(cy); q.push(cs);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 4; i++)
        ans = min(ans, dis[i][tx][ty]);
    return ans;
}

int main() {
    freopen("55pt_in.txt", "r", stdin);
    freopen("55pt_out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 0; ci < cn; ci++) {
        int n, m, sx, sy, tx, ty;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == 'S') {
                    sx = i; sy = j;
                    maze[i][j] = '.';
                } else if(maze[i][j] == 'G') {
                    tx = i; ty = j;
                    maze[i][j] = '.';
                }
            }
        }
        init(n, m);
        int ans = bfs(sx, sy, tx, ty, n, m);
        printf("Case #%d: ", ci + 1);
        if(ans == INF)
            printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}

