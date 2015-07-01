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

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define fst first
#define sec second
#define mp make_pair

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 200005;

ll il[N], ir[N];

struct require {
    ll m1, m2;
    int id;
    require(ll _m1, ll _m2, int _id) { m1 = _m1; m2 = _m2; id = _id; }
    bool operator < (const require &other) const {
        if(m1 == other.m1) return m2 < other.m2;
        else return m1 < other.m1;
    }
};

set<pli> s;
vector<require> r;
int ans[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &il[i], &ir[i]);
    }

    for(int i = 1; i < n; i++) {
        r.pb(require(ir[i] - il[i - 1], il[i] - ir[i - 1], i - 1));
    }
    sort(r.begin(), r.end());

    for(int i = 0; i < m; i++) {
        pli bridge;
        scanf("%I64d", &bridge.fst);
        bridge.sec = i;
        s.insert(bridge);
    }

    for(int i = 0; i < n - 1; i++) {
        auto it = s.lower_bound(mp(r[i].m2, -1));
        if(it == s.end() || it->fst > r[i].m1) {
            printf("No\n");
            return 0;
        } else {
            ans[r[i].id] = it->sec;
            s.erase(it);
        }
    }
    printf("Yes\n");
    for(int i = 0; i < n - 1; i++) {
        printf("%d", ans[i] + 1);
        if(i == n - 2) printf("\n");
        else printf(" ");
    }
    return 0;
}

