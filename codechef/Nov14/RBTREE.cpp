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

typedef long long LL;

using namespace std;

int father(int x) {
    return x / 2;
}

int level(int x) {
    int cnt = 0;
    while(x) { x >>= 1; cnt ++; }
    return cnt;
}

int color(int lv, int rc) {
    int c;
    if(lv & 1) c = 0;
    else c = 1;
    return (rc == 0 ? c : (c ^ 1));
}

int query(int x, int y, int c, int rc) {
    int ans = 0;
    while(x != y) {
        int lx = level(x);
        int ly = level(y);
        int lv = max(lx, ly);
        if(lx > ly) x = father(x);
        else y = father(y);
        if(color(lv, rc) == c) ans ++;
    }
    return ans + (color(level(x), rc) == c);
}

int main() {
    int q, rc = 0;
    scanf("%d", &q);
    while(q --) {
        char qt[3];
        int x, y, ans = 0;
        scanf("%s", qt);
        if(qt[1] == 'i')
            rc ^= 1;
        else {
            scanf("%d%d", &x, &y);
            if(qt[1] == 'r') printf("%d\n", query(x, y, 1, rc));
            else printf("%d\n", query(x, y, 0, rc));
        }
    }
    return 0;
}

