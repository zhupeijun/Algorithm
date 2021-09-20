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
    int L, Q; cin>>L>>Q;
    set<int> s;
    rep(k, Q) {
        int c, x; cin >> c >> x;
        if (c == 1) s.insert(x);
        else {
            auto it = s.lower_bound(x);
            int right = L, left = 0;
            if (it != s.end()) right = *it;
            if (it != s.begin()) { --it; left = *it;}
            cout << (right - left) << endl;
        }
    }
    return 0;
}