#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int f[105][105];

class YetAnotherCardGame {
public:
    int maxCards(vector <int> p, vector <int> s) {
        int n = p.size();

        sort(p.begin(), p.end());
        sort(s.begin(), s.end());

        memset(f, 0, sizeof(f));

        int m = n * 2;
        for(int t = 1; t <= m; t++) {
            vector<int>& c = t & 1 ? p : s;
            copy(f[t - 1], f[t - 1] + 101, f[t]);
            for(int k = 0; k <= 100; k++) {
                int p = upper_bound(c.begin(), c.end(), k) - c.begin();
                for(int i = p; i < n; i++) {
                    f[t][c[i]] = max(f[t][c[i]], f[t - 1][k] + 1);
                }
            }
        }
        return *max_element(f[m], f[m] + 101);
    }
};
