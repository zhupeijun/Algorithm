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

int main() {
    ll n;
    scanf("%lld", &n);
    ll m = (ll)sqrt(n);
    ll min_move = n * 2;
    for (ll i = 1; i <= m; ++i) {
        if (n % i == 0) {
            ll j = n / i;
            min_move = min(min_move, i + j - 2);
        }
    }
    printf("%lld\n", min_move);
    return 0;
}

