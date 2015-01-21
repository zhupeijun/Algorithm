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

const int N = 200005;
const int M = 25;
const int INF = 10000005;

vector<int> adj[N];
int pri[N][M], upri[N][M];
vector<int> order;

void bfs() {
    queue<int> q;
    q.push(1);
    order.push_back(1);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        int m = adj[u].size();
        for(int k = 0; k < m; k++) {
            q.push(adj[u][k]);
            order.push_back(adj[u][k]);
        }
    }
}

void solve(int u, int n) {
    int m = adj[u].size();
    if(m == 0) {
        for(int i = 1; i <= n; i++) {
            pri[u][i] = i;
            if(i == 1) upri[u][i] = 2;
            else upri[u][i] = 1;
        }
        return ;
    }
    for(int i = 1; i <= n; i++) pri[u][i] = i;
    for(int k = 0; k < m; k++) {
        int v = adj[u][k];
        for(int i = 1; i <= n; i++)
            pri[u][i] += upri[v][i];
    }
    vector<int> hm, tm;
    for(int i = 1; i <= n; i++) {
        if(i == 1) hm.push_back(pri[u][i]);
        else hm.push_back(min(pri[u][i], hm[i - 2]));
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) tm.push_back(pri[u][n - i + 1]);
        else tm.push_back(min(pri[u][n - i + 1], tm[i - 2]));
    }
    for(int i = 1; i <= n; i++) {
        int hmin = i > 1 ? hm[i - 2] : INF;
        int tmin = i < n ? tm[n - i - 1] : INF;
        upri[u][i] = min(hmin, tmin);
    }
}

int main() {
    freopen("corporate_gifting.txt", "r", stdin);
    freopen("corporate_gifting_out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int n, m = M - 5;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 0; i < n; i++) {
            int f;
            scanf("%d", &f);
            if(i == 0) continue;
            adj[f].push_back(i + 1);
        }
        bfs();
        int sz = order.size();
        for(int k = sz - 1; k >= 0; k--)
            solve(order[k], m);
        int ans = INF;
        for(int i = 1; i <= m; i++) {
            ans = min(ans, pri[1][i]);
        }
        printf("Case #%d: %d\n", ci, ans);
    }
    return 0;
}

