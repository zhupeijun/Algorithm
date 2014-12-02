#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;

using namespace std;

int a[100005];

int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if(n <= 2) printf("%d\n", n);
    else {
        vector<int> seg;
        int l = 0, r = 0;
        for(i = 0; i < n; i++) {
            r = i;
            if(i == n - 1 || a[i + 1] <= a[i]) {
                seg.push_back(l);
                seg.push_back(r);
                l = r = i + 1;
            }
        }
        int m = seg.size();
        if(m == 2) {
            printf("%d\n", min(n, seg[1] - seg[0] + 2));
        } else {
            int ans = 0;
            for(i = 0; i < m; i += 2) {
                ans = max(seg[i + 1] - seg[i] + 2, ans);
            }
            for(i = 2; i < m; i += 2) {
                if((seg[i] - seg[i - 1] == 2 &&
                        a[seg[i]] - a[seg[i - 1]] >= 2) || (
                        seg[i] - seg[i - 1] == 1 &&
                        seg[i + 1] - seg[i] >= 1 &&
                        a[seg[i] + 1] - a[seg[i - 1]] >= 2) || (
                        seg[i] - seg[i - 1] == 1 &&
                        seg[i - 1] - seg[i - 2] >= 1 &&
                        a[seg[i]] - a[seg[i - 1] - 1] >= 2)) {
                    ans = max(seg[i + 1] - seg[i - 2] + 1, ans);
                }
            }
            printf("%d\n", ans);
        }

    }
    return 0;
}

