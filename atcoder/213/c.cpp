#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int main() {
    int H, W, N; cin>>H>>W>>N;
    vi a(N), b(N);
    rep(i, N) cin>>a[i]>>b[i];

    set<int> sa(rng(a)), sb(rng(b));
    
    int k;
    unordered_map<int,int>ia, ib;
    k = 0; each(sa, v) ia[v] = ++k;
    k = 0; each(sb, v) ib[v] = ++k;
    rep(i, N) cout << ia[a[i]] << " " << ib[b[i]] << endl;
    return 0;
}