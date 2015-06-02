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

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        LL step, tot, base;
        double mdis, x;
        scanf("%lf%lld", &x, &step);
        tot = 0, base = 1, mdis = x;
        while(tot + base < step) {
            tot += base;
            base <<= 1;
            mdis = x / base;
        }
        double ans = (step - tot) * mdis - (mdis / 2);
        printf("%lf\n", ans);
    }
    return 0;
}

