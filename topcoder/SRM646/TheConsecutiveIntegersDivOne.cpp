#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

const int INF = 1000000005;

class TheConsecutiveIntegersDivOne {
public:
    int find(vi num, int k) {
        sort(num.begin(), num.end());
        int n = num.size();
        int ans = INF;
        for(int i = 0; i < n; i++) {
            int st = max(0, i - k + 1);
            int ed = st + k - 1;
            while(st <= i && ed < n) {
                int tot = 0;
                for(int j = st; j < st + k; j++)
                    if(j <= i) tot += num[i] - (i - j) - num[j];
                    else tot += num[j] - (j - i) - num[i];
                ans = min(ans, tot);
                st++; ed++;
            }
        }
        return ans;
    }
};