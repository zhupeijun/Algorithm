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
using vvi = vc<vi>;

#define RN(N) int N; cin>>N;
#define RS(S) string S; cin>>S;
#define RA(N, A) int N; cin>>N; vc<string> A(N); rep(i,N) cin>>A[i]; 

int main() {
    RS(T); RN(N);

    vv<string> bags;
    rep(i, N) { RA(A, S); bags.pb(S); }

    int M = sz(T);
    vvi dp(N+2, vi(M+2, -1)); rep(i,N+2) dp[i][0] = 0;
    rep(i, N) rep(j, M+1) {
        if (dp[i][j] == -1) continue;
        each(bags[i], s) {
            int sn = sz(s); 
            if (j+sn <= M && T.substr(j, sn) == s) {
                if (dp[i+1][j+sn] == -1 || dp[i+1][j+sn] > dp[i][j]+1) {
                    dp[i+1][j+sn] = dp[i][j]+1;
                }
            } 
        }
        
        if (dp[i+1][j] == -1 || dp[i+1][j] > dp[i][j]) {
            dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}