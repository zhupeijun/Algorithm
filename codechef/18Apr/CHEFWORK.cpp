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

int main() {
    int n;
    scanf ("%d", &n);
    vector<int> c(n), t(n);
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &c[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf ("%d", &t[i]);
    }

    int minv[3];
    fill(minv, minv + 3, 1000000);
    for (int i = 0; i < n; ++i) {
        int idx = t[i] - 1;
        minv[idx] = min(minv[idx], c[i]);
    }

    printf ("%d\n", min(minv[0] + minv[1], minv[2]));
    return 0;
}

