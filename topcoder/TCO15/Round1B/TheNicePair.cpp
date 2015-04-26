#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

int cnt[1005];

class TheNicePair {
public:
    int solve(vector <int> A) {
        int n = A.size(), ans = -1;
        for(int i = 0; i < n; i++) {
            CL(cnt, 0);
            for(int j = i; j < n; j++) {
                for(int k = 2; k <= 1000; k++)
                    if(A[j] % k == 0) cnt[k]++;
                bool ok = false;
                for(int k = 2; k <= 1000; k++) {
                    int tot = (j - i + 1);
                    if(tot & 1) {
                        if(cnt[k] >= tot / 2 + 1) {
                            ok = true; break;
                        }
                    } else {
                        if(cnt[k] >= tot / 2) {
                            ok = true; break;
                        }
                    }
                }
                if(ok) ans = max(ans, j - i);
            }
        }
        return ans;
    }
};
