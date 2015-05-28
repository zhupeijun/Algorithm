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

const int N = 100005;
const int MOD = 1000000007;

int a[N];

ll q_pow(ll a, ll b) {
    ll base = a, ans = 1;
    while(b) {
        if(b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ll m = 0, lev = 0, ans = 0, fir = 0, pv = a[0];
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            while(i + 1 < n && a[i + 1] == a[i]) { cnt++; i++; }
            ll cur = q_pow(2, cnt);
            ans = (ans + ((fir + m * (a[i] - pv)) % MOD) * (cur - 1)) % MOD;
            fir = (((fir + m * (a[i] - pv)) % MOD) * cur) % MOD;
            pv = a[i];
            m = (m * cur) % MOD;
            m = (m + cur - 1) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

