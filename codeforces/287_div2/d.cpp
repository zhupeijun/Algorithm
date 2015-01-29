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
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
const int K = 105;

int dp[N][K][10], mod[10];

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < 10; i++) {
        mod[i] = i % k;
        int z = i != 0;
        dp[1][mod[i]][z] = (dp[1][mod[i]][z] + 1) % m;
        mod[i] = (1LL * mod[i] * 10) % k;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            for(int t = 0; t < 10; t++) {
                int ti = i + 1;
                int tj = (mod[t] + j) % k;
                if(j == 0) {
                    if(t != 0) dp[ti][tj][1] = (dp[ti][tj][1] + 1) % m;
                    continue;
                }
                dp[ti][tj][1] = (dp[i][j][1] + dp[ti][tj][1]) % m;
            }
        }
        ll cnt = dp[i][0][1];
        for(int j = 0; j < 10; j++) mod[j] = (1LL * mod[j] * 10) % k;
        for(int j = i + 1; j <= n; j++)
            if(j == n) cnt = (cnt * 9) % m;
            else cnt = (cnt * 10) % m;
        ans = (ans + cnt) % m;
    }
    printf("%d\n", ans);
    return 0;
}

