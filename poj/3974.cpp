#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

// manacher algorithm

void solve(string& s) {
    int n = s.size();
    string t = "|"; rep(i, n) { t += s[i]; t += '|'; }
    int m = t.size(), id = 0, mx = 0, ans = 0;
    vi p(m); p[0] = 1;
    rep(i, m) {
        if (i < mx) p[i] = min(p[2*id-i], mx-i);
        else p[i] = 1;

        while (i+p[i]<m && i-p[i]>=0 && t[i+p[i]] == t[i-p[i]]) {
            ++p[i];
        }

        if (i+p[i] > mx) {
            mx = i+p[i];
            id = i;
        }

        maxs(ans, p[i]);
    }
    cout << ans-1 << endl;
}

int main() {
    int t = 1;
    while (true) {
        string s; cin >> s;
        if (s == "END") break;
        cout << "Case " << t++ << ": ";
        solve(s);
    }
    return 0;
}