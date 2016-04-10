#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int case_n, N, J;
    scanf("%d", &case_n);
    scanf("%d %d", &N, &J);
    printf("Case #1:\n");
    int n = 1 << 16;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (!(i & 1) || i < (1 << 15)) continue;
        vector<int> good;
        for (int k = 2; k <= 10; ++k) {
            int x = i;
            ll value = 0, base = 1;
            while(x) {
                value += base * (x & 1);
                x >>= 1;
                base *= k;
            }
            bool valid = false;
            int div = 0;
            int about = min(value, 2000LL);
            for (int j = 2; j < about; ++j) {
                if (value % j == 0) { valid = true; div = j; break; }
            }
            if (valid) {
                good.pb(div);
            }
        }
        if (good.size() == 9) {
            vector<int> bit;
            int x = i;
            while(x) {
                bit.pb(x & 1);
                x >>= 1;
            }
            int sz = bit.size();
            for (int j = sz - 1; j >= 0; --j) {
                printf("%d", bit[j]);
            }
            for (int j = 0; j < 9; ++j) {
                printf(" %d", good[j]);
            }
            printf("\n");
            ++total;
        }
        if (total == 50) break;
    }
    return 0;
}

