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

void solve() {
    ll n, m, z, l, r, b;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &z, &l, &r, &b);
    ll ans = 0;
    if (b <= n) {
        ans = min(z + l + r + b, n * m);
    } else {
        ll tot = 0;
        ll ta = n * (m + 1);
        ll bn = min((m + 1) / 2 * n, b);
        tot += bn;
        ll ra = ta - bn * 2;
        ll lr = l + r;
        ll tmp = min(lr, ra);
        tot += tmp;
        lr -= tmp;
        tot += min(lr / 2, bn);
        tot += z;
        ans = min(tot, n * m);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}

