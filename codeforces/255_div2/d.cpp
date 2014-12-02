#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>

typedef long long LL;

using namespace std;

LL a[1005][1005], sr[1000005], sc[1000005];

int main() {
    LL n, m, k, p, i, j;
    LL sum, ans = -1e18;
    priority_queue<LL> qr, qc;
    cin >> n >> m >> k >> p;
    for(i = 0;i < n; i++)
        for(j = 0; j < m; j++)
            cin >> a[i][j];
    for(i = 0;i < n; i++) {
        sum = 0;
        for(j = 0; j < m;j++)
            sum += a[i][j];
        qr.push(sum);
    }
    for(j = 0; j < m;j++) {
        sum = 0;
        for(i = 0; i < n; i++)
            sum += a[i][j];
        qc.push(sum);
    }
    sr[0] = 0;
    for(i = 1; i <= k; i++) {
        LL v = qr.top(); qr.pop();
        sr[i] = v + sr[i - 1];
        v -= p * m;
        qr.push(v);
    }
    sc[0] = 0;
    for(i = 1; i <= k; i++) {
        LL v = qc.top(); qc.pop();
        sc[i] = v + sc[i - 1];
        v -= p * n;
        qc.push(v);
    }
    for(i = 0; i <= k; i++) {
        LL tot = sr[i] + sc[k - i];
        ans = max(ans, tot - i * (k - i) * p);
    }
    cout << ans << endl;
    return 0;
}

