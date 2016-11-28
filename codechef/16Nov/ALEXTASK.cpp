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
#include <climits>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

const int N = 505;
int a[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int g = gcd(a[i], a[j]);
            ans = min(ans, 1LL * a[i] * a[j] / g);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}

