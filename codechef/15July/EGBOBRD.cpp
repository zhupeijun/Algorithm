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

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n, k, r = 0, ans = 0;
        scanf("%lld %lld", &n, &k);
        for(int i = 0; i < n; i++) {
            ll a;
            scanf("%lld", &a);
            if (r > 0) r--;
            if(a > r) {
                a -= r;
                if (a % k == 0) { ans += a / k; r = 0; }
                else { ans += a / k + 1; r = k - a % k; }
            } else {
                r = r - a;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

