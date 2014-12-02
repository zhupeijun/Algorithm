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

const int N = 1005;
const int M = 5;

int a[M][N], dp[N], p[M][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            p[i][a[i][j]] = j;
        }

    dp[0] = 1;

    int ans = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            int t;
            for(t = 1; t < k; t++)
                if(p[t][a[0][j]] > p[t][a[0][i]])
                    break;
            if(t == k) {
                dp[i] = max(dp[j] + 1, dp[i]);
                ans = max(ans, dp[i]);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

