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

const int MOD = 1000000000;
const int N = 2005;

ll a[N], b[N][N], f[N][N];

int main() {
    int t;
    scanf("%d" , &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int c = 0; c < m; c++) {
            for(int s = 0; s <= m; s++) {
                if(c == 0) b[c][s] = 1;
                else b[c][s] = b[c - 1][s];
                if(c == m - 1) a[s] = b[c][s];
                if(s > 0) b[c][s] = (b[c][s] + b[c][s - 1]) % MOD;
            }
        }
        for(int r = 0; r < n; r++) {
            for(int s = 0; s <= m; s++) {
                if(r == 0) {
                    f[r][s] = a[s];
                    if(s > 0) f[r][s] = (f[r][s] + f[r][s - 1]) % MOD;
                }
                else {
                    f[r][s] = (f[r - 1][s] * a[s]) % MOD;
                    if(s > 0) f[r][s] = (f[r][s] + f[r][s - 1]) % MOD;
                }
            }
        }
        printf("%lld\n", f[n - 1][m]);
    }
    return 0;
}

