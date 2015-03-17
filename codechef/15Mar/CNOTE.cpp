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
    while (t--) {
        int x, y, k, n;
        scanf("%d %d %d %d", &x, &y, &k, &n);
        int need = x - y;
        bool ans = (need <= 0);
        for (int i = 0; i < n; i++) {
            int pi, ci;
            scanf("%d %d", &pi, &ci);
            if (!ans) {
                if (ci <= k && need <= pi) ans = true;
            }
        }
        if (ans) printf("LuckyChef\n");
        else printf("UnluckyChef\n");
    }
    return 0;
}

