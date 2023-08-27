#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;

int chain(int v) {
    if (v == 1 || v == 89) return v;
    int ans = 0;
    while (v) {
        int t = v % 10;
        ans += t * t;
        v /= 10;
    }
    return chain(ans);
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000000; ++i) {
        if (chain(i) == 89) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}