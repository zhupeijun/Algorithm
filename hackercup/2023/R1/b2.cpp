#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int, vector<int>> memo;

void dfs(int sum, ll prod, vector<int>& ans) {
    vector<int> t = ans;
    for (int i = 0; i < sum; ++i) t.push_back(1);
    if (memo.find(prod) == memo.end() || memo[prod].size() > t.size()) {
        memo[prod] = t;
    }

    int start = 2, n = ans.size();
    if (n > 0) start = ans[n-1];
    for (int i = start; i <= sum; ++i) {
        ans.push_back(i);
        dfs(sum - i, prod * i, ans);
        ans.pop_back();
    }
}

void solve() {
    int P; cin >> P;
    if (memo.find(P) == memo.end()) {
        cout << -1 << endl;
    } else {
        auto t = memo[P];
        int n = t.size(); cout << n;
        for (int i = 0; i < n; ++i) cout << " " << t[i];
        cout << endl;
    }
}

int main() {
    vector<int> t;
    dfs(41, 1, t);

    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #"<<i<<": ";
        solve();
    }

    return 0;
}
