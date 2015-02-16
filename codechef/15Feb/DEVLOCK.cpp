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

const int MOD = 998244353;
const int M = 15000;
const int P = 55;

int dp[2][M][P];

int main() {
    int n, p, m;
    scanf("%d %d %d", &n, &p, &m);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        int cur = i & 1;
        int nxt = (i + 1) & 1;
        for(int j = 0; j <= m; j++)
            for(int t = 0; t < p; t++)
                dp[nxt][j][t] = 0;
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < 10; k++) {
                if(j + k > m) continue;
                ll add = k;
                for(int it = 1; it < (n - i); it++) add = (add * 10) % p;
                for(int t = 0; t < p; t++) {
                    int rm = (t + add) % p;
                    dp[nxt][j + k][rm] += dp[cur][j][t];
                    dp[nxt][j + k][rm] %= MOD;
                }
            }
        }
    }
    int sum = 0;
    for(int j = 0; j <= m; j++) {
        sum = (sum + dp[n & 1][j][0]) % MOD;
        printf("%d", sum);
        if (j == m) printf("\n");
        else printf(" ");
    }
    return 0;
}

