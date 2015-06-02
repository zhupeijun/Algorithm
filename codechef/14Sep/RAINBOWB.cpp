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

typedef long long LL;

using namespace std;

const int N = 1000006;
const int MOD = 1000000007;

int dp[N][8];

int main() {
    int n;
    scanf("%d", &n);
    if(n < 13) {
        printf("0\n");
        return 0;
    }
    n = (n + 1) / 2;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 7; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if(j < 7) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    printf("%d\n", dp[n][7]);
    return 0;
}

