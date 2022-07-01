#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class CastleGuard {
public:
    vector<long long> walk(int N, int R, vector <int> c) {
        int C = c.size();
        ll tot = 0;
        for (int i = 0; i < C; ++i) tot += c[i];

        vector<ll> cnt(N);
        ll cur = 0;
        for (int i = 0; i < R; ++i) {
            ++cnt[cur];
            cur = ((cur+tot)%N+N)%N;
        }

        vector<ll> ans(N); ans[0] = 1;
        for (int i = 0; i < N; ++i) {
            int cur = i;
            for (int j = 0; j < C; ++j) {
                int v = abs(c[j]), s = c[j]/v, R = v%N, T = v/N;
                for (int k = 0; k < N; ++k) ans[((cur+s*(k+1))%N+N)%N]+=T*cnt[i];
                for (int k = 0; k < R; ++k) ans[((cur+s*(k+1))%N+N)%N]+=cnt[i];
                cur = ((cur+c[j])%N+N)%N;
            }
       }
        return ans;
    }
};
