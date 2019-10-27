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

int res[200005];
int c[200005];
bool vist[200005];
vector<int> adj[200005];

void bfs(int root, int sum) {
    queue<pii> q;
    q.push(make_pair(root, sum));
    while (!q.empty()) {
        pii e = q.front();
        q.pop();
        int u = e.first;
        int s = e.second;
        int m = adj[u].size();
        s += c[u];
        res[u] = s;
        vist[u] = true;
        for (int k = 0; k < m; ++k) {
            int v = adj[u][k];
            if (!vist[v]) {
                q.push(make_pair(v, s));
            }
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < q; ++i) {
        int p, x;
        scanf("%d %d", &p, &x);
        c[p - 1] += x;
    }

    bfs(0, 0);

    for (int i = 0 ;i < n; ++i) {
        printf("%d", res[i]);
        if (i == n - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}

