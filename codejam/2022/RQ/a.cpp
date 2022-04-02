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

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

void solve() {
    int R, C; cin>>R>>C;
    int n = R*2+1, m = C*2+1;
    rep(i, n) {
        rep(j, m) {
            if (i <= 1 && j <= 1) {
                cout << ".";
                continue;
            }

            if (i%2) {
                if (j%2) cout << ".";
                else cout << "|";
            } else {
                if (j%2) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }
}

int main() {
    int T; cin >> T;
    rep(i, T) {
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }
    return 0;
}