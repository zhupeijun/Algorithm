#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int to[MAXN], vit[MAXN], fac[MAXN];
vector<int> prime;
bool isprime[505];

void get_prime() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(int i = 2; i < 505; i++)
        if(isprime[i]) {
            prime.push_back(i);
            for(int j = 2; j * i < 505; j++)
                isprime[i * j] = false;
        }
}

int main() {
    get_prime();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, i, j;
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &to[i]);
            to[i] = to[i] - 1;
        }
        memset(vit, 0, sizeof(vit));
        vector<int> sn;
        for(i = 0; i < n; i++) {
            if(vit[i] == 1) continue;
            int k = i, cnt = 0;
            while(vit[k] == 0) {
                vit[k] = 1; cnt++;
                k = to[k];
            }
            sn.push_back(cnt);
        }
        memset(fac, 0, sizeof(fac));
        int snn = sn.size();
        for(i = 0; i < snn; i++) {
            int x = sn[i];
            int m = prime.size();
            for(j = 0; j < m; j++) {
                int cnt = 0;
                while(x % prime[j] == 0) { x /= prime[j]; cnt++; }
                fac[prime[j]] = max(fac[prime[j]], cnt);
                if(x == 1) break;
            }
            if(x != 1) fac[x] = max(fac[x], 1);
        }
        LL ans = 1;
        for(i = 0; i < MAXN; i++) {
            int m = fac[i];
            for(j = 0; j < m; j++)
                ans = (ans * i) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

