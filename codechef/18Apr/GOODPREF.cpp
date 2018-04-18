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
#include <list>
#include <climits>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
char s[N];

void solve () {
    int n;
    scanf ("%s %d", s, &n);
    int m = strlen(s);
    ll ab = 0;
    for (int i = 0, an = 0, bn = 0; i < m; ++i) {
        s[i] == 'a' ? ++an : ++bn;
        if (an > bn) ++ab;
    }

    int ln = min(m, n);
    ll c[2]; CL(c, 0);
    ll total = 0;
    for (int i = 0; i < ln; ++i) {
        for (int j = 0; j < m; ++j) {
            ++c[s[j] - 'a'];
            if (c[0] > c[1]) {
                ++total;
            }
        }
    }
    if (ln < n) {
        ll diff = n - ln;
        if (c[0] == c[1]) {
            total += diff * ab;
        } else if (c[0] > c[1]) {
            total += diff * m;
        }
    }

    printf ("%lld\n", total);
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

