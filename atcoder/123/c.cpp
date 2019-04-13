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
    scanf ("%lld", &n);
    ll botneck = LLONG_MAX;
    for (int i = 0; i < 5; ++i) {
        ll t;
        scanf("%lld", &t);
        botneck = min(t, botneck);
    }

    printf("%lld\n", 4 + n / botneck + (n % botneck != 0));
    return 0;
}

