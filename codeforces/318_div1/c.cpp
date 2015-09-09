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
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;

vector<int> tr[N], tmp[N];
int cnt3[N], cnt2[N];
bool vis[N];
map<pii, bool> shrinked;

int shrink(int u) {
    vis[u] = true;
    int m = tr[u].size();
    vector<int> child;
    for(int i = 0; i < m; i++)
        if (!vis[tr[u][i]])
            child.pb(tr[u][i]);
    if(child.size() == 1) return shrink(child[0]);
    else {
        for(int v : child) {
            int t = shrink(v);
            shrinked[mp(u, t)] = (t != v);
            shrinked[mp(t, u)] = (t != v);
            tmp[u].pb(t);
            tmp[t].pb(u);
        }
        return u;
    }
}

void solve(int n) {
    CL(cnt3, 0); CL(cnt2, 0);
    for(int u = 1; u <= n; ++u) {
        int m = tr[u].size();
        for(int k = 0; k < m; ++k) {
            int v = tr[u][k];
            if(m == 3) {
                if (shrinked[mp(v, u)]) cnt3[v]++;
                else {
                    bool ok = true;
                    for(int j = 0; j < m; ++j) {
                        if(j != k && tr[tr[u][j]].size() != 1) {
                            ok = false; break;
                        }
                    }
 //                   if(!ok)cout << v << ", " << u << endl;
                    if(!ok) cnt3[v]++;
                    else cnt2[v]++;
                }
            } else if (m > 3) cnt3[v]++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        tr[u].pb(v);
        tr[v].pb(u);
    }
    int root = 1;
    for(int u = 1; u <= n; u++) {
        if(tr[u].size() > 2) {
            root = u; break;
        }
    }
    CL(vis, false);
    shrink(root);
    for(int u = 1; u <= n; ++u) tr[u] = tmp[u];
    solve(n);
    int ans = true;
    //for(int u = 1; u <= n; ++u) {
    //    cout << u << ": ";
    //    for(int x : tr[u]) cout << x << " ";
    //    cout << "," << cnt3[u];
    //    cout << endl;
    //}
    for(int u = 1; u <= n; ++u) {
        if(cnt3[u] > 2) { ans = false; break; }
    }
    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}

