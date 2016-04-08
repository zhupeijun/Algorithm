#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

const int N = 1005;
const int INF = 1000000005;

int dp[N][N];

class EllysSocks {
public:
  int getDifference(vector <int> S, int P) {
    sort(S.begin(), S.end());
    int n = S.size();
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i + 1 <= n) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
        if (i + 2 <= n) {
          dp[i + 2][j] = min(dp[i + 2][j], dp[i][j]);
          dp[i + 2][j + 1] = min(dp[i + 2][j + 1], max(dp[i][j], abs(S[i + 1] - S[i])));
        }
      }
    }
    return dp[n][P];
  }
};
