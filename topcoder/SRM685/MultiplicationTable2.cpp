#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

int vis[55];

class MultiplicationTable2 {
public:
    int minimalGoodSet(vector <int> table) {
        int n = sqrt(table.size()), ans = n;
        for (int i = 0; i < n; ++i) {
            CL(vis, 0);
            queue<int> q; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                vis[u] = 1;
                for (int j = 0; j < n; ++j) {
                    if (!vis[j]) continue;
                    int v1 = table[u * n + j];
                    if (!vis[v1]) { q.push(v1); vis[v1] = true; }
                    int v2 = table[j * n + u];
                    if (!vis[v2]) { q.push(v2); vis[v2] = true; }
                }
            }
            int cnt = 0;
            for (int j = 0; j < n; ++j) cnt += vis[j];
            ans = min(ans, cnt);
        }
        return ans;
    }
};
