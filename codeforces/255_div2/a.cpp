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

int h[505];

int main() {
    int p, n, ans = -1, i, x;
    scanf("%d %d", &p, &n);
    memset(h, 0, sizeof(h));
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        if(ans != -1) continue;
        int k = x % p;
        if(h[k] == 0) h[k] = 1;
        else {
            h[k] = 1;
            ans = i + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

