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

typedef long long LL;

using namespace std;

const int N = 105;
const int MOD = 1000000007;

LL dp[N][N];
int a[N];

LL find(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (j <= i) return 1;
    dp[i][j] = 0;
    dp[i][j] = (dp[i][j] + find(i + 1, j)) % MOD;
    // if is a open bracket
    if (a[i] < 0) {
        for (int k = i + 1; k <= j; k++) {
            if (a[k] == -a[i]) {
                dp[i][j] = (dp[i][j] + find(i + 1, k - 1) * find(k + 1, j)) % MOD;
            }
        }
    }
    return dp[i][j];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    int ans = (int)find(0, n - 1);
    printf("%d\n", ans);
    return 0;
}

