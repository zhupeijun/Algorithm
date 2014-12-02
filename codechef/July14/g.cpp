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

double f[55][105], tmp[55][105];

int main() {
    //freopen("g.in", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--) {
        int N, C, K, i, j, k, L, R, c;
        scanf("%d %d %d", &N, &C, &K);
        double cc = 1.0 / C;
        memset(f, 0, sizeof(f));
        for(j = 0; j < N; j++) {
            f[j][1] = 1;
        }
        for(i = 0; i < K; i++) {
            scanf("%d %d", &L, &R); L--; R--;
            memset(tmp, 0, sizeof(tmp));
            for(j = 0; j < N; j++) {
                if(j >= L && j <= R) {
                    for(k = 0; k < C; k++) {
                        tmp[j][k] += f[j][k] * 0.5;
                        for(c = 0; c < C; c++) {
                            tmp[j][(k * c) % C] += f[j][k] * 0.5 * cc;
                        }
                    }
                } else {
                    for(k = 0; k < C; k++)
                        tmp[j][k] = f[j][k];
                }
            }
            for(j = 0; j < N; j++)
                for(k = 0; k < C; k++)
                    f[j][k] = tmp[j][k];
        }
        double ans = 0;
        for(j = 0; j < N; j++) {
            for(k = 0; k < C; k++) {
                ans += f[j][k] * k;
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}

