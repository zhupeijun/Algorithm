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

int main() {
    int n, s, i, x, y, ans = -1;
    scanf("%d %d", &n, &s);
    s *= 100;
    for(i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        int pr = x * 100 + y;
        if(s >= pr) {
            ans = max(ans, (s - pr) % 100);
        }
    }
    printf("%d\n", ans);
    return 0;
}

