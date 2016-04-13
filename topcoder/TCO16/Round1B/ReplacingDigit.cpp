#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class ReplacingDigit {
public:
    int getMaximumStockWorth(vector <int> A, vector <int> D) {
        vector<vector<int>> d;
        int ans = 0;
        for (auto x : A) { 
            int i = 0;
            ans += x;
            while (x) {
                int t = x % 10;
                if (i >= d.size()) d.push_back({});
                d[i].push_back(t);
                x /= 10; ++i;
            }
        }
        int n = d.size();
        for (int i = 0; i < n; ++i) sort(d[i].begin(), d[i].end());
        int k = 9;
        for (int i = n - 1; i >= 0; --i) {
            int m = d[i].size();
            if (k == 0) break;
            for (int j = 0; j < m; ++j) {
                while (k > 0 && D[k - 1] <= 0) --k;
                if (k == 0) break; 
                if (d[i][j] < k) {
                    ans += (k - d[i][j]) * pow(10, i);
                    --D[k - 1];
                }
            }
        }
        return ans;
    }
};
