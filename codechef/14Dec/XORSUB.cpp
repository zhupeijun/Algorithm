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

const int MAXV = 1050;
const int MAXN = 1005;
int a[MAXN], dp[MAXN][MAXV];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][a[0]] = 1; dp[0][0] = 1;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < MAXV; j++) {
                if(dp[i][j]) {
                    dp[i + 1][j ^ a[i + 1]] = 1;
                    dp[i + 1][j] = 1;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < MAXV; j++)
            if(dp[n - 1][j])
                ans = max(ans, k ^ j);
        printf("%d\n", ans);
    }
    return 0;
}

