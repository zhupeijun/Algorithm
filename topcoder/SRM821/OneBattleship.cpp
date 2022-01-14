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

const int DIR[4][2] = {{-1,0},{0,-1}};

class OneBattleship {
public:

    vector<string> hit(vector<string> g) {
        int n = sz(g), m = sz(g[0]);
        vector<int> c(3);
        rep(i, n) rep(j, m) {
            if (g[i][j] == '.') ++c[(i+j)%3];
        }

        int minv = INT_MAX, mink = 0;
        rep(i, 3) if (minv > c[i]) {
            minv = c[i];
            mink = i;
        }

        rep(i, n) rep(j, m) {
            if (g[i][j] == '.' && (i+j)%3 == mink) {
                g[i][j] = '*';
            }
        }
        return g;
    }
};


// Powered by FileEdit


// Powered by FileEdit
