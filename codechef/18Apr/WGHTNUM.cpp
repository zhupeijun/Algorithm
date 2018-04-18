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
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

ll exp_by_square (ll a, ll n) {
    ll b = a, r = 1;
    while (n) {
        if (n & 1) r = ((r % MOD) * (b % MOD)) % MOD;
        b = ((b % MOD) * (b % MOD)) % MOD;
        n >>= 1;
    }
    return r;
}

void solve () {
    ll n, w;
    scanf ("%lld %lld", &n, &w);
    map<int, int> M;
    ll t = exp_by_square(10, n - 2);
    ll b = w >= 0 ? max(0LL, 9 - w) : max (0LL, w + 10);
    printf ("%lld\n", (t * b) % MOD);
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

