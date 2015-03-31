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

#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;

vector<int> adj[N], dp[N];

int dfs(int cur, int par) {
    int m = adj[cur].size(), pi = -1;
    for(int i = 0; i < m; i++) if(adj[cur][i] == par) { pi = i; break; }
    if(pi != -1 && dp[cur][pi] != -1) return dp[cur][pi];
    int max1 = -1, max2 = -1;
    for(int i = 0; i < m; i++) {
        if(i == pi) continue;
        int depth = dfs(adj[cur][i], cur);
        if(depth > max1) { max2 = max1; max1 = depth; }
        else if(depth > max2) max2 = depth;
    }
    int ans = 1;
    if(max1 != -1 && max2 != -1) ans += (max1 + max2);
    if(pi != -1) dp[cur][pi] = ans;
    return ans;
}

int main() {
    freopen("b-large.out", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 1; ci <= cn; ci++) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < N; i++) { dp[i].clear(); adj[i].clear(); }
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].pb(v); adj[v].pb(u);
            dp[u].pb(-1); dp[v].pb(-1);
        }
        int tot = 0, ans = 0;
        for(int u = 1; u <= n; u++) {
            tot = max(dfs(u, -1), tot);
            ans = n - tot;
        }
        printf("Case #%d: %d\n", ci, ans);
    }
    return 0;
}

