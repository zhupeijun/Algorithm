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

const int N = 200005;
int a[N], l[N], r[N];

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; ++i) {
        int j = n - 1 - i;
        l[i] = i == 0 ? a[i] : a[i] | l[i - 1];
        r[j] = j == n - 1 ? a[j] : a[j] | r[j + 1];
    }

    ll tot = 1;
    for(int i = 0; i < k; ++i) tot *= x;

    ll ans = a[0] * tot;
    for(int i = 0; i < n; ++i) {
        ll res = tot * a[i];
        if (i > 0) res |= l[i - 1];
        if (i < n - 1) res |= r[i + 1];
        ans = max(ans, res);
    }

    printf("%I64d\n", ans);
    return 0;
}

