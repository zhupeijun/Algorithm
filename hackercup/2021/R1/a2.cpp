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

const int MOD = 1000000007;

void solve() {
    int N; cin>>N;
    string S; cin>>S;
    int prev = -1;
    ll ans = 0;
    rep(i, N) {
        char c = S[i];
        if (c == 'F') continue;
        if (prev != -1) {
            if (S[prev] != S[i]) {
                ll left = prev+1;
                ll right = N-i;
                ans = (ans + (left * right)%MOD)%MOD;
            }
        }
        prev = i;
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