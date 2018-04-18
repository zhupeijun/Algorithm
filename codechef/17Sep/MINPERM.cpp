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

void solve ()
{
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x = i & 1 ? i + 1 : i - 1;
        if (n & 1) {
            if (n - i == 1) x = i + 1;
            if (n == i) x = i - 2;
        }
        printf ("%d%c", x, i == n ? '\n' : ' ');
    }
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

