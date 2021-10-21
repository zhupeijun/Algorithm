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
    string s; cin >> s;
    int n = sz(s);
    string mx = s, mi = s;
    rep(i, n) {
        string t = s.substr(i, n-i) + s.substr(0, i);
        maxs(mx, t); mins(mi, t);
    }
    cout << mi << endl;
    cout << mx << endl; 
    return 0;
}