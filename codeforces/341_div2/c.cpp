#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define CL(a, b) memset(a, b, sizeof(a))

const int N = 100000;
int c1[N], c2[N]; // mod p, not mod p

double got(int idx) {
    return 1.0 * c1[idx] / (c1[idx] + c2[idx]);
}

double not_got(int idx) {
    return 1.0 * c2[idx] / (c1[idx] + c2[idx]);
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        c1[i] = (r / p - (l - 1) / p);
        c2[i] = r - l + 1 - c1[i];
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = (i - 1 + n) % n, r = (i + 1) % n;
        ans += 1000 * got(l) * not_got(i) * not_got(r);
        ans += 1000 *not_got(l) * not_got(i) * got(r);
        ans += 2000 * got(i);
        ans += 2000 * got(l) * not_got(i) * got(r);
    }
    printf("%lf\n", ans);
    return 0;
}
