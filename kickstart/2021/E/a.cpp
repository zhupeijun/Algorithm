#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define FF(i, a, b) for(int i=(a);i<=(b);++i)
#define FR(i, a, b) for(int i=(a);i>=(b);--i)
#define each(v, i) for (auto& i : v)
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()
#define mp make_pair

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using us = unordered_set<T>;
using vi = vc<int>;
using vvi = vv<int>;

const int M = 26;

inline int id(char c) { return c - 'a'; }

void solve() {
    string s; cin >> s;
    int n = sz(s);

    vc<vc<us<int>>> m(M, vc<us<int>>(M));
    rep(i, n) {
        int c = id(s[i]);
        m[c][c].insert(i);
    }

    string t = s;
    rep(i, n) {
        if (s[i] == t[i]) {
            bool ok = false;
            int c = id(s[i]);
            rep(j, M) {
                if (j == c) continue;
                rep(k, M) {
                    if (k == c) continue;
                    if (sz(m[j][k])) {
                        int p = *(m[j][k].begin());
                        m[id(s[i])][id(t[i])].erase(i);
                        m[id(s[p])][id(t[p])].erase(p);
                        swap(t[i], t[p]);
                        m[id(s[i])][id(t[i])].insert(i);
                        m[id(s[p])][id(t[p])].insert(p);
                        ok = true; break;
                    }
                }
                if (ok) break;
            }
            if (!ok) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    cout << t << endl;
}

int main() {
    int T; cin >> T;
    rep(i, T) {
        cout << "Case #"<< (i+1) <<": ";
        solve();
    }
    return 0;
}