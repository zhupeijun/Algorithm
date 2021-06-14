#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int ans = 0;
    if (C % 2 == 0) {
        ans = abs(A) - abs(B);
    } else {
        ans = A - B;
    }

    if (ans > 0) cout << ">" << endl;
    else if (ans == 0) cout << "=" << endl;
    else cout << "<" << endl;
    return 0;
}