#include <bits/stdc++.h>

using namespace std;

void solve() {
    int P; cin >> P;
    vector<int> fac;
    int M = sqrt(P)+1;
    for (int i = 2; i <=M; ++i) {
        while (P%i==0) {
            fac.push_back(i);
            P /= i;
        }
    }
    if (P > 1) fac.push_back(P);

    int sum = 0;
    for (int i = 0; i < fac.size(); ++i) {
        sum += fac[i];
    }

    if (sum > 41) {
        cout << -1 << endl;
    } else {
        int rm = 41 - sum;
        for (int i = 0; i < rm; ++i) fac.push_back(1);
        cout << fac.size();
        for (int i = 0; i < fac.size(); ++i) {
            cout << " " << fac[i];
        }
        cout << endl;
    }
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
