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

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

ll find2(ll m) {
    if(m < 2) return m;
    ll k = 1;
    while((k << 1) <= m) k <<= 1;
    return k;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        ll w = r - l + 1;
        if (w == 1) { printf("0 1\n"); continue; }
        else if(w == 2) {
            l & 1 ? printf("0 2\n") : printf("1 4\n");
            continue;
        }
        ll m = find2(w);
        ll lr = m - (l % m);
        ll ans1, ans2;
        if (lr + m > w && lr < m) {
            ll tm = m >> 1;
            ll t1 = find2(lr - 1);
            ll d1 = t1 * 2 - 1;
            ll c1 = (((((lr - t1) % MOD) * (t1 % MOD)) % MOD) * (lr == tm ? 4 : 2)) % MOD;
            ll t2 = find2(w - lr - 1);
            ll d2 = t2 * 2 - 1;
            ll c2 = (((((w - lr - t2) % MOD) * (t2 % MOD)) % MOD) * (w - lr == tm ? 4 : 2)) % MOD;
            if (d1 == d2) {
                ans1 = d1;
                ans2 = (c1 + c2) % MOD;
            } else {
                ans1 = max(d1, d2);
                ans2 = d1 > d2 ? c1 : c2;
            }
        } else {
            ll idx = l / m;
            if (idx & 1) {
                ll t1, d1, c1;
                if (lr == m) {
                    t1 = find2(m - 1);
                    d1 = t1 * 2 - 1;
                    c1 = (((((m - t1) % MOD) * (t1 % MOD)) % MOD) * 4) % MOD;
                } else {
                    t1 = find2(lr - 1);
                    d1 = t1 * 2 - 1;
                    c1 = (((((lr - t1) % MOD) * (t1 % MOD)) % MOD) * 2) % MOD;
                }

                ll t2, d2, c2;
                if(w - lr == m) {
                    t2 = find2(m - 1);
                    d2 = t2 * 2 - 1;
                    c2 = (((((m - t2) % MOD) * (t2 % MOD)) % MOD) * 4) % MOD;
                } else {
                    t2 = find2(w - lr - 1);
                    d2 = t2 * 2 - 1;
                    c2 = (((((w - lr - t2) % MOD) * (t2 % MOD)) % MOD) * 2) % MOD;
                }

                if (d1 == d2) {
                    ans1 = d1;
                    ans2 = (c1 + c2) % MOD;
                } else {
                    ans1 = max(d1, d2);
                    ans2 = d1 > d2 ? c1 : c2;
                }
            } else {
                ll t1, d1, c1;
                if (lr == m) {
                    t1 = find2(w - 1);
                    d1 = t1 * 2 - 1;
                    c1 = (((((w - t1) % MOD) * (t1 % MOD)) % MOD) * (w == m ? 4 : 2)) % MOD;
                } else {
                    t1 = find2(lr + m - 1);
                    d1 = t1 * 2 - 1;
                    c1 = (((((lr + m - t1) % MOD) * (t1 % MOD)) % MOD) * 2) % MOD;
                }

                ans1 = d1;
                ans2 = c1;
            }
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}

