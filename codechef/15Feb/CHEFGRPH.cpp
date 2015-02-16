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

const int MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> pii;

#define mp make_pair

struct edge {
    ll l1, l2, u, v, type;

    edge(ll _l1, ll _l2, ll _u, ll _v, ll _type) {
        l1 = _l1; l2 = _l2; u = _u; v = _v; type = _type;
    }

    bool operator < (const edge & e) const {
        if (l1 == e.l1) {
            if (type == e.type) return u < e.u;
            else return type > e.type;
        }
        return l1 < e.l1;
    }
};

vector<edge> edges;
map<pii, ll> M;

ll qpower(ll x, ll y) {
    ll b = x, ret = 1;
    while(y > 0) {
        if(y & 1) ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        y >>= 1;
    }
    return ret;
}

int main() {
    ll n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        ll l1, l2, u, v;
        scanf("%lld %lld %lld %lld", &l1, &u, &l2, &v);
        edges.push_back(edge(l1, l2, u, v, 0));
        edges.push_back(edge(l2, l1, v, u, 1));
    }
    sort(edges.begin(), edges.end());
    ll cl = 0;
    ll ps = 1, cs = 1;
    int K = k * 2;
    for(int i = 0; i < K; i++) {
        edge e = edges[i];
        //cout << e.l1 << " " << e.u << " " << cs << " " << cl << endl;
        if (e.l1 != cl) {
            ps = cs;
            ps = (ps * qpower(m, e.l1 - cl - 1)) % MOD;
            cl = e.l1;
            cs = ps;
            //cout << cl << " " << cs << endl;
            if(cl < n + 1) cs = (cs * m) % MOD;
            while(i < K && edges[i].l1 == cl && edges[i].type) {
                if (i > 0 && edges[i - 1].l1 == edges[i].l1 && edges[i].u == edges[i - 1].u) {
                    i++;
                    continue;
                }
                pii tp = mp(edges[i].l1, edges[i].u);
                ll tv = M.find(tp) == M.end() ? 0 : M[tp];
                cs = (cs + tv) % MOD;
               // cout << cs << endl;
                i++;
            }
            //cout << cl << " " << cs << endl;
            if(i < K) {
                if(edges[i].l1 != cl) { i--; continue; }
                else e = edges[i];
            } else {
                continue;
            }
        }
        pii lu = mp(e.l1, e.u);
        ll cps = 0;
        if (M.find(lu) != M.end()) { cps = M[lu]; }
        if (cl > 0) cps = (cps + ps) % MOD;
        else cps = 1;
        pii ed = mp(e.l2, e.v);
        if (M.find(ed) == M.end()) M[ed] = 0;
        M[ed] += cps; M[ed] %= MOD;
        //cout << e.l1 << " " << e.u << " " << cl << " " << cs << " " << ps << endl;
    }
    ll ans = cs % MOD;
    ans = (ans * qpower(m, n - cl)) % MOD;
    printf("%lld\n", ans);
    return 0;
}

