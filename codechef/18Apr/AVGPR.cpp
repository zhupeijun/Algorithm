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

const int MAXN = 2005;
const int BASE = 1000;
ll M[2005];

void solve () {
    int n;
    scanf ("%d", &n);

    CL(M, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf ("%d", &x);
        ++M[BASE + x];
    }

    ll total = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (M[i] > 1) {
            total += M[i] * (M[i] - 1) / 2;
        }
        for (int j = i + 1; j < MAXN; ++j) {
            if (((i + j) & 1) == 0 && M[(i + j) / 2] > 0) {
                total += M[i] * M[j];
            }
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

