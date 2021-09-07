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
using vs = vc<string>;

bool has(const vs& s, string& x) {
    each(s, v) if (v == x) return true;
    return false;
}

int main() {
    vs s(3); rep(i, 3) cin >> s[i];
    vs a = {"ABC", "ARC", "AGC", "AHC"};
    each(a, v) if (!has(s, v)) { 
        cout << v << endl; return 0;
    } 
    return 0;
}