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

int dp[205][7][7][7];

class SelectFromArrays {
    public:
    int maxSum(vector <int> A, vector <int> B, vector <int> C, int NA, int NB, int NC) {
        int n = sz(A);
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][0] = 0;
        rep(i, n) rep(a,NA+1) rep(b,NB+1) rep(c,NC+1) {
            if (dp[i][a][b][c] < 0) continue;
            maxs(dp[i+1][a][b][c], dp[i][a][b][c]);
            maxs(dp[i+1][a+1][b][c], dp[i][a][b][c]+A[i]);
            maxs(dp[i+1][a][b+1][c], dp[i][a][b][c]+B[i]);
            maxs(dp[i+1][a][b][c+1], dp[i][a][b][c]+C[i]);
        }
        return dp[n][NA][NB][NC];
    }
};

// Powered by FileEdit
