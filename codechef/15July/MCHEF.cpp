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

struct cost {
    int l, r, c;
    bool operator < (const cost &other) const {
        return c > other.c;
    }
};

bool cmp(cost c1, cost c2) {
    return c1.l < c2.l;
}

const int N = 100005;
const int M = 505;

ll r[N], f[M];
int c[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, m;
        scanf("%d %d %d", &n, &k, &m);
        for(int i = 0; i < n; i++)
            scanf("%lld", &r[i]);

        vector<cost> a;
        for(int i = 0; i < m; i++) {
            cost c;
            scanf("%d %d %d", &c.l, &c.r, &c.c);
            a.pb(c);
        }
        fill(c, c + n, -1);
        sort(a.begin(), a.end(), cmp);
        priority_queue<cost> q;
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && a[j].l - 1 <= i) { q.push(a[j]); j++; }
            while(!q.empty()) {
                cost t = q.top();
                if(t.r - 1 >= i) { c[i] = t.c; break; }
                else q.pop();
            }
        }

        const ll MINF = -10000000000000000L;
        fill(f, f + k + 1, MINF); f[0] = 0;
        for(int i = 0; i < n; i++) f[0] += r[i];
        for(int i = 0; i < n; i++) {
            if(r[i] >= 0 || c[i] == -1) continue;
            for(int j = k - c[i]; j >= 0; j--) {
                int t = j + c[i];
                if (f[j] == MINF) continue;
                f[t] = max(f[j] - r[i], f[t]);
            }
        }
        ll ans = *max_element(f, f + k + 1);
        printf("%lld\n", ans);
    }
    return 0;
}

