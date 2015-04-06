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

ll dp[35][2][2][2]; // 0 -> < , 1 -> ==

int check(int st, int cb, int nb) {
    if(st == 0) return 0;
    if (nb == cb) return 1;
    else if(nb > cb) return -1;
    else return 0;
}

int main() {
    freopen("out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 1; ci <= cn; ci++) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);
        memset(dp, 0, sizeof(dp));
        dp[31][1][1][1] = 1;
        for(int lv = 31; lv > 0; lv--) {
            for(int r = 0; r < 8; r++) {
                for(int t = 0; t < 4; t++) {
                    int r1 = r & 1, r2 = (r >> 1) & 1, r3 = (r >> 2) & 1;
                    int a = t & 1, b = (t >> 1) & 1, k = a & b;
                    int sft = lv - 1;
                    int na = check(r1, (A >> sft) & 1, a);
                    int nb = check(r2, (B >> sft) & 1, b);
                    int nk = check(r3, (K >> sft) & 1, k);
                    if(na != -1 && nb != -1 && nk != -1)
                        dp[lv - 1][na][nb][nk] += dp[lv][r1][r2][r3];
                }
            }
        }
        ll ans = dp[0][0][0][0];
        printf("Case #%d: %lld\n", ci, ans);
    }
    return 0;
}

