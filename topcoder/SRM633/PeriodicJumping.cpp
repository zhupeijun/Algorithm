#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> sum;

class PeriodicJumping {
public:
    int minimalTime(int x, vector <int> len) {
        if(x == 0) return 0;
        x = abs(x);
        int n = len.size(), i, m = n * 2;
        LL tmp = 0;
        for(i = 0; i < m; i++) {
            tmp += len[i % n];
            sum.push_back(tmp);
        }
        int ans = 0;
        if(x >= sum[n - 1]) {
            ans = (x / sum[n - 1]) * n;
            x = x % sum[n - 1];
            if(x == 0) return ans;
            for(i = 0; i < n; i++)
                if(sum[i] >= x) break;
            return ans + i + 1;
        }
        if(x == len[0]) return 1;
        LL l = len[0], r = len[0];
        for(i = 1; i < m; i++) {
            int y = len[i % n];
            if (y <= l) l = l - y;
            else if (y >= r) l = y - r;
            else l = 0;
            r = r + y;
            if(x >= l && x <= r) return i + 1;
        }
        return -1;
    }
};