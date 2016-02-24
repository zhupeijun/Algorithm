#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

#define pc __builtin_popcount
#define CL(a, b) memset(a, b, sizeof(a))

const int M = 1 << 20;
const int INF = 50 * 50 * 55;

int dp[M];

class OrderOfOperations {
public:
    int minTime(vector <string> s) {
        int n = s.size(), m = s[0].size(), ans = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int v = 0;
            for (int j = 0; j < m; ++j) v = (v << 1) + (s[i][j] - '0');
            a[i] = v;
        }

        fill(dp, dp + M, INF); dp[0] = 0;
        for (int i = 0; i < M; ++i) {
            if (dp[i] == INF) continue;
            for (int j = 0; j < n; ++j) {
                int nxt = i | a[j];
                int c = pc((i ^ a[j]) & a[j]);
                dp[nxt] = min(dp[nxt], dp[i] + c * c);
                ans = dp[i];
            }
        }
        return ans;
    }
};
