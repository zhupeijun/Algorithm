#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 10005;
const int MOD = 1000000007;

LL a[N];
LL rt[70];
LL P[1000005][65];

void ppow() {
    for(int i = 1; i < 1000005; i++) {
        for(int j = 0; j < 65; j++) {
            if(j == 0) P[i][j] = 1;
            else {
                if(P[i][j - 1] == -1 || (1.0 * P[i][j - 1] * i) > (1e18 + 5)) 
                    P[i][j] = -1;
                else {
                    P[i][j] = P[i][j - 1] * i;
                }
            }
        }
    }
}

LL root(LL a, int k) {
    if(k == 1) return a;
    if(k == 2) return (LL)sqrt(a);
    LL l = 1, r = 1000004, mid;
    while(l <= r) {
        mid = (l + r) / 2LL;
        if(P[mid][k] == -1 || P[mid][k]  > a) 
            r = mid - 1;
        else l = mid + 1;
    }
    return r;
}

int main() {
    //freopen("f.in", "r", stdin);
    int cn, ci;
    ppow();
    scanf("%d", &cn);
    for(ci = 0; ci < cn; ci ++) {
        int n, q, i, k;
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        LL tail = 0;
        for(i = 61; i < n; i++)
            tail = (tail + a[i]) % MOD;
        for(k = 0; k < q; k++) {
            LL x, t, ans = 0;
            int m = min(61, n);
            scanf("%lld", &x);
            for(i = 0; i < m; i++) {
                t = root(x, i + 1);
                ans = (ans + (((t % MOD) * (a[i] % MOD)) % MOD)) % MOD;
            }
            printf("%lld", (((ans + tail) % MOD) + MOD) % MOD);
            if(k == q - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
