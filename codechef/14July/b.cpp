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

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x, y, ans;
        scanf("%d %d", &x, &y);
        x = abs(x); y = abs(y);
        if(x > y) {
            ans = x * 2 + (x - y) % 2;
        } else if(y > x) {
            ans = y + y - 1 + (y - 1 - x) % 2;
        } else {
            ans = x + y;
        }
        printf("%d\n", ans);
    }
    return 0;
}

