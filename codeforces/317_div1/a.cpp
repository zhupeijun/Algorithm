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

ll solve(ll a, ll b, ll c, ll l) {
    ll res = 0;
    for(ll k = 0; k <= l; k++) {
        ll s = min(l - k, a + k - b - c);
        if (s >= 0) res += (s + 2) * (s + 1) / 2;
    }
    return res;
}

int main() {
    ll a, b, c, l;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &l);
    ll ans = (l + 3) * (l + 2) * (l + 1) / 6;
    ans -= solve(a, b, c, l);
    ans -= solve(b, a, c, l);
    ans -= solve(c, a, b, l);
    printf("%I64d\n", ans);
    return 0;
}

