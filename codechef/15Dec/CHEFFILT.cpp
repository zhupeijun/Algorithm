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

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int M = 1024;
const int N = 100005;
const int MOD = 1000000007;

int dp[2][M], filters[N];

void solve() {
    char pix[15];
    scanf("%s", pix);
    int org = 0, pn = strlen(pix);
    for (int i = 0; i < pn; ++i) {
        org <<= 1; org |= (pix[i] == 'w');
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char filter_str[15];
        scanf("%s", filter_str);
        int f = 0, fsn = strlen(filter_str);
        for (int j = 0; j < fsn; ++j) {
            f <<= 1; f |= (filter_str[j] == '+');
        }
        filters[i] = f;
    }
    CL(dp, 0);
    dp[0][org] = 1;
    for (int i = 0; i < n; ++i) {
        int cur = (i & 1), nxt = ((i + 1) & 1);
        CL(dp[nxt], 0);
        for (int k = 0; k < M; ++k) {
            int value = k ^ filters[i];
            dp[nxt][value] += dp[cur][k];
            if (dp[nxt][value] >= MOD) dp[nxt][value] -= MOD;

            dp[nxt][k] += dp[cur][k];
            if (dp[nxt][k] >= MOD) dp[nxt][k] -= MOD;
        }
    }
    printf("%d\n", dp[n & 1][0]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

