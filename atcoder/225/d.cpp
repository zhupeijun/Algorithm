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
    int N, Q; cin >> N >> Q;
    unordered_map<int, int> prev, next;
    rep(i, Q) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            prev[y] = x; next[x] = y;
        } else if (op == 2) {
            int x, y; cin >> x >> y;
            prev.erase(y); next.erase(x);
        } else {
            int x; cin >> x;
            while (prev.find(x) != prev.end()) {
                x = prev[x];
            }
            vi l; l.pb(x);
            while (next.find(x) != next.end()) {
                x = next[x]; l.pb(x);
            }
            cout << sz(l);
            each(l, x) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}