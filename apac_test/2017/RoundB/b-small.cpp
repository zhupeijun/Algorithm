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
#include <list>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

ll iA[1000005], jB[1000005];

void solve() {
    ll a, b, n, k;
    scanf("%lld %lld %lld %lld", &a, &b, &n, &k);
    for (int i = 1; i <= n; ++i) {
        ll bi = i, ta = a, ans_i = 1;
        while (ta) {
            if (ta & 1) {
                ans_i = (bi * ans_i) % k;
            }
            bi = (bi * bi) % k;
            ta >>= 1;
        }
        iA[i] = ans_i;

        ll bj = i, tb = b, ans_j = 1;
        while (tb) {
            if (tb & 1) {
                ans_j = (bj * ans_j) % k;
            }
            bj = (bj * bj) % k;
            tb >>= 1;
        }
        jB[i] = ans_j;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if ((iA[i] + jB[j]) % k == 0) ++ans;
        }
    }
    printf("%lld", ans);
}

int main() {
    int cn;
    scanf("%d", &cn);
    for (int ci = 1; ci <= cn; ++ci) {
        printf("Case #%d: ", ci);
        solve();
        printf("\n");
    }
    return 0;
}

