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

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int S, C, K;
        scanf("%d %d %d", &S, &C, &K);
        int maxn = max(S, C);
        ll ans = 0;
        if (C > 0) {
            int sk = 1;
            if (S >= K) {
                sk = S - K + 1;
                ans += (1LL << sk) + 1;
            }
            for (int i = sk; i <= C; i++) {
                int tot = 1;
                if (i <= S) tot += S - i;
                if (tot >= K) ans += (1LL << i);
            }
        } else {
            if (S >= K) {
                int sk = S - K + 1;
                ans = (1LL << sk) + 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

