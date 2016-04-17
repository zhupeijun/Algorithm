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
    int cn;
    scanf("%d", &cn);
    for (int ci = 1; ci <= cn; ++ci) {
        int n;
        scanf("%d", &n);
        map<int, int> M;
        int m = n * 2 - 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                scanf("%d", &x);
                ++M[x];
            }
        }
        vector<int> ans;
        for (auto kv : M) {
            if (kv.second & 1) ans.pb(kv.first);
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d:", ci);
        int ans_count = ans.size();
        for (int i = 0; i < ans_count; ++i) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

