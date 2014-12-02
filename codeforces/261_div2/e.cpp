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

typedef long long LL;

using namespace std;

const int M = 300005;

struct edge {
    int u, v, w;
    bool operator < (const edge r) const {
        return w < r.w;
    }
} e[M];

int dp[M];

int main() {
    int n, m, i, ans, st, j;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    sort(e, e + m);
    memset(dp, 0, sizeof(dp));
    ans = 0;
    vector<int> buf;
    for(st = i = 0; i < m; i++) {
        int maxv = max(dp[e[i].u] + 1, dp[e[i].v]);
        buf.push_back(maxv);
        if(i == m - 1 || e[i].w != e[i + 1].w) {
            int bs = buf.size();
            for(j = 0; j < bs; j++) {
                int k = st + j;
                dp[e[k].v] = max(dp[e[k].v], buf[j]);
                ans = max(dp[e[k].v], ans);
            }
            st = i + 1;
            buf.clear();
        }
    }
    printf("%d\n", ans);
    return 0;
}

