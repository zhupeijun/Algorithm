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
    int N, M, K;
    scanf ("%d %d %d", &N, &M, &K);
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        scanf ("%lld", &a[i]);
    }

    for (int i = 0; i < M; ++i) {
        int x;
        scanf ("%d", &x);
    }

    for (int i = 0; i < N; ++i) {
        ll x = i;
        ll t = ((x * x + x * 3290707 + 198321829)) % K + 1;
        printf ("%lld", a[i] + t);

        if (i == N - 1) printf ("\n");
        else printf (" ");
    }
    return 0;
}
