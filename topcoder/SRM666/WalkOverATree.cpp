#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> g[55];

class WalkOverATree {
public:
    int dfs(int r) {
        int ans = 0;
        for(int k : g[r]) ans = max(ans, dfs(k) + 1);
        return ans;
    }
    int maxNodesVisited(vector <int> p, int L) {
        int n = p.size(), tot = p.size() + 1;
        for(int i = 0; i < n; ++i)
            g[p[i]].push_back(i + 1);
        int d = dfs(0);
        return L <= d ? L + 1 : d + 1 + min((L - d) / 2, tot - d - 1);
    }
};
