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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N, K;
ll a[200005];
ll f[200005];

ll getMinK(ll s) {
    ll total = 0;
    for (ll i = 0; i < N; ++i) {
        ll need = s / f[i];
        total += max(0LL, a[i] - need);
    }
    return total;
}

int main() {
    scanf("%lld %lld", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &f[i]);
    }

    sort(a, a + N);
    sort(f, f + N);
    ll m = N / 2;
    for (ll i = 0; i < m; ++i) {
        swap(f[i], f[N - i - 1]);
    }

    ll left = 0, right = 1000000000005LL;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll minK = getMinK(mid);
        //cout << left << " " << right << " " << mid << " " << minK << endl;
        if (minK <= K) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%lld\n", left);
    return 0;
}

