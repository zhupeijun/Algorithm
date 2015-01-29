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
    ll h, n;
    scanf("%I64d %I64d", &h, &n);
    ll l = 1, r = 1LL << h, lv = 1, dir = 0, ans = 0;
    h++;
    while(lv < h) {
        ll len = 1LL << (h - lv);
        ll mid = l + len / 2;
        ans++;
        if(n < mid) {
            r = mid - 1;
            if(dir == 1) ans += (1LL << (h - lv)) - 1;
            else dir = 1;
        }
        else {
            l = mid;
            if(dir == 0) ans += (1LL << (h - lv)) - 1;
            else dir = 0;
        }
        lv++;
    }
    printf("%I64d\n", ans);
    return 0;
}

