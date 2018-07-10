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
#define vsort(a) sort(a.begin(), a.end())

typedef long long ll;
typedef pair<int, int> pii;

char at[55][25];

void solve() {
    ll N, K, V;
    scanf ("%lld %lld %lld", &N, &K, &V);
    for (int i = 0; i < N; ++i) {
        scanf ("%s", at[i]);
    }

    ll s = (((V * K) % N) - K + N) % N;
    vector<int> pick;
    for (int i = 0; i < K; ++i) {
        pick.pb((s + i) % N);
    }
    vsort(pick);
    for (int i = 0; i < K; ++i) {
        printf ("%s", at[pick[i]]);
        printf ("%c", i == K - 1 ? '\n' : ' ');
    }
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

