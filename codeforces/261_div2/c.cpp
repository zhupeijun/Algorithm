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

typedef long long LL;

using namespace std;

int ans[1005][1005];

int main() {
    int n, k, d, i, j;
    scanf("%d %d %d", &n, &k, &d);
    int x = 1;
    bool ok = false;
    for(i = 0; i < d; i++) {
        x *= k;
        if(x >= n) { ok = true; break; }
    }
    if(!ok) {
        printf("-1\n");
    } else {
        for(i = 0; i < n; i++) {
            int a = i;
            for(j = 0; j < d; j++) {
                ans[j][i] = (a % k) + 1;
                a /= k;
            }
        }
        for(i = 0; i < d; i++) {
            for(j = 0; j < n; j++) {
                printf("%d", ans[i][j]);
                if(j == n - 1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}

