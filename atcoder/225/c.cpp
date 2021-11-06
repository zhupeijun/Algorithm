#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0;i<(n);++i)

template<typename T> using vc = vector<T>;
using vi = vc<int>;
using vvi = vc<vi>;

bool solve(const vvi& a, int N, int M) {
    rep(i, N) rep(j, M) {
        if (i == 0) {
            if (j > 0) {
                if (a[i][j] != a[i][j-1]+1) return false;
                if ((a[i][j]-1)%7 != (a[i][j-1]-1)%7+1) return false;
            }
        } else {
            if (a[i][j] != a[i-1][j]+7) return false;
        }
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    vvi a(N,vi(M)); rep(i, N) rep(j, M) cin >> a[i][j];
    if (solve(a, N, M)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
