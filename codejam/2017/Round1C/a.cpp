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
    int N, K;
    scanf ("%d %d", &N, &K);
    vector<pii> pk;
    for (int i = 0; i < N; ++i) {
        int r, h;
        scanf ("%d %d", &r, &h);
        pk.pb (mp(r, h));
    }

    auto cmp = [](pii a, pii b) {
        return a.first > b.first;
    };
    sort (pk.begin(), pk.end(), cmp);

    priority_queue<double, vector<double>, greater<double>> q;
    double side_total = 0, area = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (q.size () >= K) {
            side_total -= q.top (); q.pop ();
        }

        double side = 2 * PI * pk[i].first * pk[i].second;
        q.push (side);
        side_total += side;

        if (q.size() == K) {
            double top = PI * pk[i].first * pk[i].first;
            area = max (area, side_total + top);
        }
    }

    printf ("%.9lf\n", area);
}

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        printf ("Case #%d: ", i);
        solve ();
    }
    return 0;
}

