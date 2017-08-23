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

typedef long long ll;
typedef pair<int, int> pii;

int a[5000];

void solve () {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &a[i]);
    }

    int m = (n + 1) / 2;
    bool is_rainbow = true;
    for (int i = 0; i < m; ++i) {
        if (i == 0 && a[i] != 1) {
            is_rainbow = false;
            break;
        }

        if (i == m - 1 && a[i] != 7) {
            is_rainbow = false;
            break;
        }

        if (i > 0 && (a[i] - a[i - 1] > 1 || a[i] - a[i - 1] < 0)) {
            is_rainbow = false;
            break;
        }

        if (a[i] != a[n - 1 - i]) {
            is_rainbow = false;
            break;
        }
    }

    printf ("%s\n", is_rainbow ? "yes" : "no");
}

int main() {
    int case_n;
    scanf ("%d", &case_n);
    for (int case_i = 0; case_i < case_n; ++case_i) {
        solve ();
    }
    return 0;
}

