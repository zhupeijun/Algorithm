#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ANewHope {
public:
    int count(vector <int> fw, vector <int> lw, int D) {
        int n = fw.size();
        vector<int> h(n + 1);
        for (int i = 0; i < n; ++i) h[lw[i]] = i;
        int delta = n - D;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int p = h[fw[i]];
            if (i - p > 0) ans = max(ans, (i - p) / delta + ((i - p) % delta != 0) + 1);
        }
        return ans;
    }
};
