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

char s[100005];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, i, cnt = 0;
        scanf("%d", &n);
        scanf("%s", s);
        for(i = 0; i < n; i++)
            cnt += s[i] - '0';
        LL ans = 1LL * cnt * (cnt - 1) / 2 + cnt;
        printf("%lld\n", ans);
    }
    return 0;
}

