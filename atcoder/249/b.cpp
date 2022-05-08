#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
#define pb push_back
#define eb emplace_back
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
using vvi = vv<int>;

int main() {
    string s; cin >> s; 
    int n = sz(s);
    bool up = false, lo = false, dt = false;
    each(s, c) {
        if (isupper(c)) up = true;
        if (islower(c)) lo = true; 
    }

    unordered_set<char> st(s.begin(), s.end());
    if (sz(st) == n) dt = true;
    if (up&&lo&&dt) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}