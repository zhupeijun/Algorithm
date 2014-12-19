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

LL a[25], dp[10][5000000];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        LL tot = 0, x;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n;i++) {
            scanf("%lld", &a[i]);
            tot += a[i];
        }

        if(n < k || tot % k) {
            printf("no\n");
            continue;
        }

        if(tot == 0) {
            printf("yes\n");
            continue;
        }
        x = tot / k;

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i <= k; i++) {
            int m = 1 << n;
            for(int j = 0; j < m; j++) {
                if(dp[i][j] == 0) continue;
                LL sum = 0;
                for(int t = 0; t < n; t++)
                    if(j & (1 << t)) sum += a[t];
                sum -= i * x;
                for(int t = 0; t < n; t++) {
                    if(j & (1 << t)) continue;
                    if(sum + a[t] == x)
                        dp[i + 1][j | (1 << t)] = 1;
                    else if(sum + a[t] < x)
                        dp[i][j | (1 << t)] = 1;
                }
            }
        }
        if(dp[k][(1 << n) - 1]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

