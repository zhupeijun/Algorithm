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

typedef vector<vector<int>> mat;
#define READ(n, a) for (int i = 0; i < (n); ++i) scanf ("%d", &(a[i]))

const int MOD = 1000000007;

void mul (mat a, mat b, mat& c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                ll t = (1LL * a[i][k] * b[k][j]) % MOD;
                c[i][j] = (c[i][j] + t) % MOD;
            }
        }
    }
}

void solve () {
    mat a = { {1, 0}, {0, 1} };
    mat b = { {0, 1}, {1, 1} };

    int M, N;
    scanf ("%d %d", &M, &N);

    FOR (i, 2, N) {
        mul(a, b, a, 2);
    }

    vector<int> A(M), B(M);
    READ (M, A);
    READ (M, B);

    int x = a[0][1], y = a[1][1];
    if (N == 1) {
        x = 1; y = 0;
    } else if (N == 2){
        x = 0; y = 1;
    }

    ll ans = 0;
    FOR (i, 0, M) {
        ans = (ans + ((1LL * x * A[i]) % MOD)) % MOD;
        ans = (ans + ((1LL * y * B[i]) % MOD)) % MOD;
    }

    ans = (ans * M) % MOD;

    printf ("%lld\n", ans);
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

