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

const string V = "AEIOU";

inline bool isV(char c) { return V.find(c) != string::npos; }

void solve() {
    string s; cin >> s;
    int ans = INT_MAX;
    rep(i, 26) {
        char t = (char)(i+'A');
        int cnt = 0;
        each(s, c) {
            if (c != t) {
                ++cnt;
                if(isV(t) == isV(c)) ++cnt;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    int T; cin >>T;
    rep(i, T) { 
        cout << "Case #"<< (i+1) << ": ";
        solve();
    }
    return 0;
}