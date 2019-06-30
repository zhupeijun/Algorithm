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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const ll MOD = 1000000007;

char s[1000005];

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    scanf("%s", s);
    ll cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == 'B') ++cnt;
        else --cnt;
        cnt = max(0LL, cnt);

        if (cnt > K) {
            s[i] = '*';
            cnt -= 2;
            cnt = max(0LL, cnt);
        }
    }

    ll sum = 0, base = 1;
    for (int i = 0; i < N; ++i) {
        base = (base << 1) % MOD;
        if (s[i] == '*') {
            sum = (sum + base) % MOD;
        }
    }
    printf("%lld\n", sum);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

