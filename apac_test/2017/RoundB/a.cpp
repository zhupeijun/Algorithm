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

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    long long n = min(l, r);
    printf("%lld", n * (n + 1) / 2);
}

int main() {
    int cn;
    scanf("%d", &cn);
    for (int ci = 1; ci <= cn; ++ci) {
        printf("Case #%d: ", ci);
        solve();
        printf("\n");
    }
    return 0;
}

