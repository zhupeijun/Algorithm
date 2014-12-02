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

const int N = 100005;

int d[N];

int next_v(int cur, int n) {
    while(cur < n && d[cur] < 0) cur++;
    return cur;
}

int next_d(int cur, int n) {
    while(cur < n && d[cur] > 0) cur++;
    return cur;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &d[i]);
        int vi = -1, di = -1;
        LL r = 0, ans = 0;
        while(1) {
            if(r < 0) {
                vi = next_v(vi + 1, n);
                ans += 1LL * abs(vi - di) * min(abs(r), 1LL * d[vi]);
                r += d[vi];
            } else {
                di = next_d(di + 1, n);
                ans += 1LL * abs(vi - di) * min(abs(r), 1LL * abs(d[di]));
                r += d[di];
            }
            //cout << vi << " " << di << " " << r << endl;
            if(r == 0 && (vi == n || di == n)) break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

