#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

const int MOD = 1000000007;

int dp[105][205], tmp[205], a[200005], cnt[105];

int main() {
    int ci, cn;
    cin >> cn;
    for(ci = 0; ci < cn; ci++) {
        int i, j, n, ans;
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for(i = 0; i < n;i++)
            cin >> a[i];
        for(i = 0;i < n;i++) {
            for(j = 0; j <= 205; j++) {
                tmp[j] = dp[a[i]][j];
            }
            for(j = 1; j <= 100; j++) {
                int diff = a[i] - j + 100;
                tmp[diff] += cnt[j];
                if(tmp[diff] >= MOD)
                    tmp[diff] -= MOD;
            }
            for(j = 1; j <= 100; j++) {
                int diff = a[i] - j + 100;
                tmp[diff] = tmp[diff] + dp[j][diff];
                if(tmp[diff] >= MOD)
                    tmp[diff] -= MOD;
            }
            for(j = 0; j < 205; j++)
                dp[a[i]][j] = tmp[j];
            cnt[a[i]]++;
        }
        int tot = 1;
        for(i = 0; i < n; i++) {
            tot <<= 1;
            if(tot >= MOD) tot -= MOD;
        }

        tot = (tot - 1 + MOD) % MOD;

        int minus = n;
        for(i = 0; i < 105; i++) {
            for(j = 0; j < 205; j++) {
                minus += dp[i][j];
                if(minus >= MOD) minus -= MOD;
            }
        }
        cout << (tot - minus + MOD) % MOD << endl;
    }
    return 0;
}
