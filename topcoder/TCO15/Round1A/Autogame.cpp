#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;

int dis[55], cnt[55];

class Autogame {
public:
    int wayscnt(vector <int> a, int K) {
        int n = a.size();
        CL(cnt, 0);
        for(int i = 0; i < n; i++) {
            CL(dis, -1);
            int cur = i, len = 0;
            while(dis[cur] == -1 && len != K) {
                dis[cur] = len;
                len ++;
                cur = a[cur] - 1;
            }
            if(len == K) {
                cnt[cur]++;
            } else {
                int left = (K - len) % (len - dis[cur]);
                for(int k = 0; k < left; k++) cur = a[cur] - 1;
                cnt[cur]++;
            }
        }
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(cnt[i] > 0) ans = (int)((1LL * (cnt[i] + 1) * ans) % MOD);
        }
        return ans;
    }
};
