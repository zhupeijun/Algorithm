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

const int N = 100005;

char s[N];
ll c0[N], c1[N], sum[N], dist[N];

void init(int n, int k) {
    for(int i = 0; i < n; i++) {
        c0[i] = c1[i] = 0;
        if(s[i] == '0') c0[i]++;
        if(s[i] == '1') c1[i]++;
        if (i > 0) {
            c0[i] += c0[i - 1];
            c1[i] += c1[i - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        int l = i, r = n - 1, m;
        while(l <= r) {
            m = (l + r) / 2;
            int h0 = i > 0 ? c0[i - 1] : 0;
            int h1 = i > 0 ? c1[i - 1] : 0;
            if (c0[m] - h0 > k || c1[m] - h1 > k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        dist[i] = l - i;
        sum[i] = dist[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, q;
        scanf("%d %d %d", &n, &k, &q);
        scanf("%s", s);
        init(n, k);
        while(q--) {
            int L, R;
            scanf("%d %d", &L, &R);
            L--, R--;
            int l = L, r = R, m;
            while(l <= r) {
                m = (l + r) / 2;
                if (dist[m] + m > R) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ll ans = 0;
            if (l > L) ans += sum[l - 1] - (L > 0 ? sum[L - 1] : 0);
            if (l <= R) ans += (R - l + 1LL) * (1LL + R - l + 1LL) / 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

