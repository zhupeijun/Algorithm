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

const int MOD = 1000000007;

const int N = 5005;

int f[N][N];

int stress_less(int x, int y) {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    int sum = x + y;

    for(int i = 0; i < sum; i++) {
        for(int j = 0; j < sum; j++) {
            if(f[i][j] > 0) {
                int x1 = j;
                int y1 = (i + 1) - j;
                if(x1 > y1)
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;

                int x2 = j + 1;
                int y2 = (i + 1) - (j + 1);
                if(x2 > y2)
                    f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % MOD;
            }
        }
    }
    return f[sum][x];
}

int stressful(int x, int y) {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    int sum = x + y;
    for(int i = 0; i < sum; i++) {
        for(int j = 0; j < sum; j++) {
            if(f[i][j] > 0) {
                int x1 = j;
                int y1 = (i + 1) - j;
                if(x1 <= y1)
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;

                int x2 = j + 1;
                int y2 = (i + 1) - (j + 1);
                if((x2 <= y2) || (x2 > y2 && y2 == y))
                    f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % MOD;
            }
        }
    }
    return f[sum][x];
}

int main() {
    freopen("winning_at_sports.txt", "r", stdin);
    freopen("winning_at_sports_out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 1; ci <= cn; ci++) {
        int x, y;
        scanf("%d-%d", &x, &y);
        int ans1 = stress_less(x, y);
        int ans2 = stressful(x, y);
        printf("Case #%d: %d %d\n", ci, ans1, ans2);
    }
    return 0;
}

