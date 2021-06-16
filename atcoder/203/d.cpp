#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define ms(a) memset(a, 0, sizeof(a)) 

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using pq = priority_queue<int>;

const int M = 805;

int a[M][M];
int s[M][M];
int N, K;

bool check() {
    int half = (K*K+1)/2;
    rep(i, N) rep(j, N) {
        if (i >= K-1 && j >= K-1) {
            int cnt = s[i][j];
            if (i-K >= 0) cnt -= s[i-K][j];
            if (j-K >= 0) cnt -= s[i][j-K];
            if (i-K >= 0 && j-K >= 0) cnt += s[i-K][j-K];
            if (cnt >= half) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    rep(i, N) rep(j, N) cin >> a[i][j];

    int l = 0, r = 1000000009;
    while (l <= r) {
        int mid = (l+r)/2;
        ms(s);
        rep(i, N) rep(j, N) {
            s[i][j] = a[i][j] <= mid;
            if (i > 0) s[i][j] += s[i-1][j];
            if (j > 0) s[i][j] += s[i][j-1];
            if (i > 0 && j > 0) s[i][j] -= s[i-1][j-1];
        }
        
        if (check()) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}