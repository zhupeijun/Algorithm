#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

double dp[2][4][305];

class Bitwisdom {
public:
    double expectedActions(vector <int> p) {
        int n = p.size();
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0][0] = 0.01 * (100 - p[0]);
        dp[0][3][0] = 0.01 * p[0];
        for(int i = 0; i < n - 1; ++i) {
            int cur = i & 1, nxt = (i + 1) & 1;
            memset(dp[nxt], 0, sizeof(dp[nxt]));
            for(int c = 0; c < 4; ++c) {
                int sec = c & 1;
                for(int k = 0; k < n; ++k) {
                    if(dp[cur][c][k] == 0) continue;
                    if(sec == 0) {
                        dp[nxt][c | 1][k + 1] += dp[cur][c][k] * 0.01 * p[i + 1];
                        dp[nxt][c][k] += dp[cur][c][k] * 0.01 * (100 - p[i + 1]);
                    } else {
                        dp[nxt][c][k] += dp[cur][c][k] * 0.01 * p[i + 1];
                        dp[nxt][c - 1][k] += dp[cur][c][k] * 0.01 * (100 - p[i + 1]);
                    }
                }
            }
        }
        double ans = 0;
        int last = (n - 1) & 1;
        for(int k = 0; k < n; ++k) {
            ans += dp[last][0][k] * 2 * k;
            ans += dp[last][1][k] * (k * 2 - 1);
            ans += dp[last][2][k] * (k * 2 + 1);
            ans += dp[last][3][k] * (k == 0 ? 1 : k * 2);
        }
        return ans;
    }
};
