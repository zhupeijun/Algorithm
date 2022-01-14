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

int main() {
    int N; cin >> N;
    unordered_map<string, int> m;
    rep(i, N) {
        string s; cin >> s;
        ++m[s];
    }
    string ans;
    int maxv = 0;
    for (const auto& it : m) {
        if (it.se > maxv) {
            ans = it.fi;
            maxv = it.se;
        }
    }
    cout << ans << endl;
    return 0;
}

