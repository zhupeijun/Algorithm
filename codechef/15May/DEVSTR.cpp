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

typedef long long ll;
typedef pair<int, int> pii;

char s[100005];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);

        // solve the case when k = 1
        if(k == 1) {
            int b0 = 0, b1 = 1, c0 = 0, c1 = 0;
            for(int i = 0; i < n; i++) {
                int cur = s[i] - '0';
                if(b0 != cur) c0++;
                if(b1 != cur) c1++;
                b0 ^= 1;
                b1 ^= 1;
            }
            int b = c0 > c1;
            int ans = min(c0, c1);
            for(int i = 0; i < n; i++) { s[i] = b + '0'; b ^= 1; }
            printf("%d\n", ans);
            printf("%s\n", s);
            continue;
        }

        // solve other cases
        int ans = 0;
        for(int i = 0; i < n;) {
            int cur = s[i] - '0';
            int nxt = (cur ^ 1) + '0';
            int j = i + 1;
            while(j < n && s[i] == s[j]) j++;
            for(int p = i; p < j; p += k) {
                int rm = j - p;
                if (rm <= k) break;
                if (rm <= 2 * k) {
                    s[p + rm / 2] = nxt;
                } else {
                    s[p + k] = nxt;
                }
                p++;
                ans++;
            }
            i = j;
        }
        printf("%d\n", ans);
        printf("%s\n", s);
    }
    return 0;
}

