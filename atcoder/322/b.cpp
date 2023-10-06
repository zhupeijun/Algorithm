#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;
    bool pre = T.starts_with(S);
    bool suf = T.ends_with(S);
    int ans = 0;
    if (pre && suf) ans = 0;
    else if (pre) ans = 1;
    else if (suf) ans = 2;
    else ans = 3;
    cout << ans << endl;
    return 0;
}
