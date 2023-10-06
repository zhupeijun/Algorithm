#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    sort(X.begin(), X.end());
    double ans;
    if (N == 4 || N > 5) {
        ans = (X[N-1]+X[N-2])*0.5 - (X[1]+X[0])*0.5;
    } else {
        double l = (X[N-1]+X[N-2])*0.5 - (X[2]+X[0])*0.5;
        double r = (X[N-1]+X[N-3])*0.5 - (X[1]+X[0])*0.5;
        ans = max(l, r);
    }
    cout << fixed << setprecision(7) << ans << endl;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
