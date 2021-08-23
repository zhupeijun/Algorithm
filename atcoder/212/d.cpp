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
using pq = priority_queue<ll, vc<ll>, greater<>>;

int main() {
    int Q; cin >>Q;
    pq q;
    ll add = 0;
    rep(i, Q) {
        int P; cin >> P;
        if (P == 1) {
            int X; cin >> X;
            q.push(X-add);
        } else if (P == 2) {
            int X; cin >> X;
            add += X;
        } else {
            ll t = q.top(); q.pop();
            cout << (t+add) << endl;
        }
    }
    return 0;
}