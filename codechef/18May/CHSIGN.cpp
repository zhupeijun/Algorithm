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

void solve () {
    int n;
    scanf ("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &a[i]);
    }

    vector<vector<ll>> dp = { {0, 0, 0}, {0, 0, 0}};

    vector<vector<pii>> log;

    int k = 0, prev = -1;
    for (int i = 0; i < n; ++i) {
        if ((i - 1 < 0 || a[i - 1] > a[i]) && (i + 1 >= n || a[i + 1] > a[i])) {
            bool conflict = prev >= 0 && prev + 2 == i && a[i] + a[prev] - a[i - 1] >= 0;
            int nxt = (k + 1) & 1;

            auto t = vector<pii>();
            if (conflict) {
                int idx = dp[k][1] > dp[k][2] ? 1 : 2;
                dp[nxt][0] = dp[k][idx] + a[i];
                dp[nxt][1] = dp[k][0];
                dp[nxt][2] = dp[k][1];

                t.pb(mp(i, idx));
                t.pb(mp(i, 0));
                t.pb(mp(i, 1));
            } else {
                int idx = 0;
                ll maxv = 0;
                for (int j = 0; j < 3; ++j) {
                    if (dp[k][j] > maxv) {
                        maxv = dp[k][j];
                        idx = j;
                    }
                }

                dp[nxt][0] = dp[k][idx] + a[i];
                dp[nxt][1] = dp[k][0];
                dp[nxt][2] = dp[k][1];

                t.pb(mp(i, idx));
                t.pb(mp(i, 0));
                t.pb(mp(i, 1));
            }

            log.pb(t);

            k = nxt;
            prev = i;
        }
    }

    int last = k & 1;

    int max_idx = 0;
    ll max_value = 0;
    for (int i = 0; i < 3; ++i) {
        if (dp[last][i] > max_value) {
            max_idx = i;
            max_value = dp[last][i];
        }
    }

    cout << dp[0][0] << dp[0][1] << dp[0][2] << endl;
    cout << dp[1][0] << dp[1][1] << dp[1][2] << endl;

    cout << last << endl;

    int cur = max_idx;
    int m = log.size();
    for (int i = m - 1; i >= 0; --i) {
        pii x = log[i][cur];
        if (cur == 0) {
            a[x.first] *= -1;
        }

        cur = x.second;
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) printf (" ");
        printf ("%d", a[i]);
    }
    printf ("\n");
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

