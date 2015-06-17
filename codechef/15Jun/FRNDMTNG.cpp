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

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int T1, T2, t1, t2;
        scanf("%d %d %d %d", &T1, &T2, &t1, &t2);
        int cur = 0;
        double ans = 0;
        const double base = 1.0 * T1 * T2;
        while(cur < T1 && cur - t2 < T2) {
            int cl = cur - t2, cr = cur + t1;
            if(cr < T2) {
                if(cl >= 0) {
                    int x = min(T2 - cr, T1 - cur);
                    int y = cr - cl;
                    ans += (1.0 * x * y) / base;
                    cur += x;
                } else {
                    int x = min(-cl, T2 - cr);
                    x = min(T1 - cur, x);
                    int y = cr;
                    ans += (2.0 * x * y + 1.0 * x * x) / (2.0 * base);
                    cur += x;
                }
            } else {
                if(cl >= 0) {
                    int x = min(T2 - cl, T1 - cur);
                    int y = T2 - cl;
                    ans += (2.0 * x * y - 1.0 * x * x) / (2.0 * base);
                    cur += x;
                } else {
                    int x = min(-cl, T1 - cur);
                    int y = T2;
                    ans += (1.0 * x * y) / base;
                    cur += x;
                }
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}

