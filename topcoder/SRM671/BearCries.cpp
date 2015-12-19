#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

#define CL(a, b) memset(a, 0, sizeof(a))

const int MOD = 1000000007;
const int N = 205;

long long dp[N][N][N];

class BearCries {
public:
    int count(string message) {
        int n = message.size();
        CL(dp, 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (message[i] == ';') {
                        if (k > 0) {
                            dp[i + 1][j][k - 1] = (dp[i + 1][j][k - 1] + dp[i][j][k] * k) % MOD;
                        }
                        dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % MOD;
                    } else {
                        if (j > 0) {
                            dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + dp[i][j][k] * j) % MOD;
                        }
                        if (k > 0) {
                            dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k] * k) % MOD;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
