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

const int N = 300005;
const int M = 5005;
const ll INF = 1LL << 62;

int a[N];
ll f[M][M], sum[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int l = 0, n1 = 0, n2 = 0;
    for(int i = 0; i < k; ++i) {
        int t = 0;
        for(int j = i; j < n; j += k) t++;
        if (i == 0) { n1 = 1; l = t; }
        else if(t == l) n1++;
        else n2++;
    }
    //cout << n1  << " " << n2 << " " << l << endl;
    sort(a, a + n); k++; sum[0] = 0;
    for(int i = 1; i < n; ++i) sum[i] = sum[i - 1] + abs(a[i] - a[i - 1]);
    for(int i = 0; i < M; ++i) for(int j = 0; j < M; ++j) f[i][j] = INF;
    f[0][0] = 0;
    for(int i = 0; i <= n1; ++i) {
        for(int j = 0; j <= n2; ++j) {
            if (i == 0 && j == 0) {
                f[i + 1][j] = sum[l - 1];
                f[i][j + 1] = sum[l - 2];
                continue;
            }
            int nxt = max(0, i * l + j * (l - 1));
            int space = abs(a[nxt] - a[nxt - 1]);
      //      cout << i << "," << j << " : " << space << " " << f[i][j] << " " << l << " " << nxt  << " " << nxt + l - 2 << " : ";
            if (i < n1) {
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + sum[nxt + l - 1] - sum[nxt]);
        //        cout << nxt + l - 1 << " " << nxt  << " " << sum[nxt + l - 1] - sum[nxt];
            }
            if (j < n2) {
                f[i][j + 1] = min(f[i][j + 1], f[i][j] + sum[nxt + l - 2] - sum[nxt]);
        //        cout << nxt + l - 2 << " " << nxt << " " << sum[nxt + l - 2] - sum[nxt];
            }
        //    cout << endl;
        }
    }
    printf("%I64d\n", f[n1][n2]);
    return 0;
}

