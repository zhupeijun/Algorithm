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
    string s; cin >> s;
    vi a(4); rep(i, 4) a[i] = s[i] - '0'; 

    bool weak = false;
    int i = 1;
    while (i < 4) {
        if (a[i] != a[i-1]) break;
        ++i;
    }

    if (i == 4) { 
        cout << "Weak" << endl;
        return 0;
    }

    i = 1;
    while (i < 4) {
        if (a[i] != (a[i-1]+1) % 10) break;
        ++i;
    }

    if (i == 4) {
        cout << "Weak" << endl;
        return 0;
    }

    cout << "Strong" << endl;
    return 0;
}