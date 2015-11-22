#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

class BearCavalry {
public:
    int countAssignments(vector <int> w, vector <int> h) {
        int n = w.size(), ans = 0;
        sort(w.begin() + 1, w.end());
        sort(h.begin(), h.end());
        for (int i = 0; i < n; ++i) {
            int s = w[0] * h[i];
            int cho = 1;
            for (int j = n - 1; j > 0; --j) {
                int opt = 0;
                for (int k = 0; k < n; ++k) {
                    if (k == i) continue;
                    if (h[k] * w[j] < s) ++opt;
                }
                cho = (1LL * cho * (opt - (n - (j + 1)))) % MOD; 
            }
            ans = (ans + cho) % MOD;
        }
        return ans;
    }
};
