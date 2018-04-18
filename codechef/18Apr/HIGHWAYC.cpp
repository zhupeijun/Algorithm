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
#include <cfloat>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)
#define PI 3.14159265358979323846
#define EPS 0.000001

typedef long long ll;
typedef pair<int, int> pii;

void read(vector<double>& ar, int n) {
    for (int i = 0; i < n; ++i) {
        double x;
        scanf ("%lf", &x);
        ar.pb(x);
    }
}

void solve () {
    int N, S, Y;
    scanf ("%d %d %d", &N, &S, &Y);

    vector<double> v, d, p, c;
    read(v, N);
    read(d, N);
    read(p, N);
    read(c, N);

    double t = 0;
    const double pt = 1.0 * Y / S;
    for (int i = 0; i < N; ++i) {
        if (d[i] == 1) {
            double st = p[i] - c[i] + v[i] * t;
            double ed = p[i] + v[i] * (t + pt);

            if (st < 0 && (ed > 0 || abs(ed) < EPS)) {
                double wt = (c[i] - p[i]) / v[i] - t;
                t += wt;
            }
        } else {
            double st = p[i] - v[i] * (t + pt);
            double ed = p[i] + c[i] - v[i] * t;
            if ((st < 0 || abs(st) < EPS) && ed > 0) {
                double wt = (p[i] + c[i]) / v[i] - t;
                t += wt;
            }
        }
        t += pt;
    }

    printf ("%lf\n", t);
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

