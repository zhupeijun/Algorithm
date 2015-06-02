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

typedef long long ll;

using namespace std;

const int N = 100005;

int a[N], b[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll p = 1LL * k / a[i] * b[i];
            ans = max(ans, p);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

