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

const int N = 1000005;
const int T = 4;

ll bn[N][T], an[N][T][T], cnt[N][T];
char str[N];

int index(char a) {
    if(a == 'c') return 0;
    else if(a == 'h') return 1;
    else if(a == 'e') return 2;
    else return 3;
}

void init(int n) {
    for(int i = n - 1; i >= 0; i--) {
        for(int k = 0; k < T; k++)
            bn[i][k] = i < n - 1 ? bn[i + 1][k] : 0;
        int idx = index(str[i]);
        bn[i][idx]++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < T; j++)
            for(int k = 0; k < T; k++)
                an[i][j][k] = i > 0 ? an[i - 1][j][k] : 0;
        int idx = index(str[i]);
        for(int j = 0; j < T; j++) {
            an[i][idx][j] += bn[i][j];
            cnt[i][j] = i > 0 ? cnt[i - 1][j] : 0;
        }
        cnt[i][idx]++;
    }
}

int main() {
    int m, n;
    scanf("%s", str);
    scanf("%d", &m);
    n = strlen(str);
    init(n);
    for(int q = 0; q < m; q++) {
        char a[2], b[2];
        int l, r;
        scanf("%s %s %d %d", a, b, &l, &r);
        l--; r--;
        int ai = index(a[0]), bi = index(b[0]);
        ll t1 = an[r][ai][bi], t2 = cnt[r][ai];
        if (l - 1 >= 0) {
            t1 -= an[l - 1][ai][bi];
            t2 -= cnt[l - 1][ai];
        }
        ll t3 = r + 1 < n ? t3 = bn[r + 1][bi] : 0;
        ll ans = t1 - t2 * t3;
        printf("%lld\n", ans);
    }
    return 0;
}

