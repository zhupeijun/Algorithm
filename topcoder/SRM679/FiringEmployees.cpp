#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> manager, salary, productivity;
vector<vector<int>> adj;

class FiringEmployees {
public:
    int get_profit(int u) {
        int m = adj[u].size(), total = 0;
        for (int i = 0; i < m; ++i) {
            int v = adj[u][i];
            total += get_profit(v);
        }
        if (u > 0) total += productivity[u - 1] - salary[u - 1];
        return max(total, 0);
    }
    int fire(vector <int> m, vector <int> s, vector <int> p) {
        manager = m; salary = s; productivity = p;
        int n = manager.size();
        adj.resize(n + 1);
        for (int i = 0; i < n; ++i) adj[manager[i]].push_back(i + 1);
        return get_profit(0);
    }
};
