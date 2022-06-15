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
    int N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int k = i;
        for (int d = 2; d*d <= i; ++d) {
            while (k%(d*d)==0) k/=d*d;
        }

        for (int d = 1; d*d <= N; ++d) {
            if (k*d*d <= N) ++ans;
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}