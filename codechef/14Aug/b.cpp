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
    int t;
    scanf("%d", &t);
    while(t--) {
        int x, y, ax, ay;
        bool ans = false;
        scanf("%d %d", &x, &y);
        ax = abs(x);
        ay = abs(y);
        if(x > 0 && (ax & 1) == 1) {
            int y1 = 2 + (ax / 2) * 2;
            int y2 = -(ax / 2) * 2;
            if(y >= y2 && y <= y1) ans = true;
        }
        if(x < 0 && (ax & 1) == 0) {
            int y1 = (ax / 2) * 2;
            int y2 = -(ax / 2) * 2;
            if(y >= y2 && y <= y1) ans = true;
        }
        if(y > 0 && (ay & 1) == 0) {
            int x1 = (ay / 2) * 2 - 1;
            int x2 = -(ay / 2) * 2;
            if(x >= x2 && x <= x1) ans = true;
        }
        if(y < 0 && (ay & 1) == 0) {
            int x1 = (ay / 2) * 2 + 1;
            int x2 = -(ay / 2) * 2;
            if(x >= x2 && x <= x1) ans = true;
        }
        if(y == 0 && (x >= 0 && x <= 1)) ans = true;
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

