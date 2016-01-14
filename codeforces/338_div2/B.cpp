#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

const int N = 100005;
vector<int> edges[N];
int max_dist[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    fill(max_dist, max_dist + N, 1);
    max_dist[1] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int en = edges[i].size();
        ans = max(ans, 1LL * max_dist[i] * en);
        for (int j = 0; j < en; ++j) {
            if (edges[i][j] > i) {
                max_dist[edges[i][j]] = max(max_dist[edges[i][j]], max_dist[i] + 1);
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
