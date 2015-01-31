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

const int N = 305;
const int M = 505;

int a[N], ans[N][M];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++) {
        int x = a[i], k = 0;
        if(i == 0) {
            while(x > 9) { ans[i][k++] = 9; x -= 9;}
            if(x > 0) ans[i][k++] = x;
        } else {
            if(a[i] > a[i - 1]) {
                int rm = a[i] - a[i - 1], j = 0;
                for(int j = 0; j < M; j++) {
                    ans[i][j] = ans[i - 1][j] + rm;
                    if(ans[i][j] > 9) { rm = ans[i][j] - 9; ans[i][j] = 9; }
                    else rm = 0;
                }
            } else {
                int dt = a[i - 1] - a[i];
                for(int j = 0; j < M; j++) ans[i][j] = ans[i - 1][j];
                for(int j = 0; j < M; j++) {
                    if(ans[i][j] > 0) {
                        dt -= (ans[i][j] - 1);
                        ans[i][j] = 0;
                        ans[i][j + 1] += 1;
                        if(dt <= 0) break;
                    }
                }
                for(int j = 0; j < M; j++) {
                    if(ans[i][j] > 9) {
                        ans[i][j + 1] += ans[i][j] / 10;
                        ans[i][j] = ans[i][j] % 10;
                    }
                }
                int sum = 0;
                for(int j = 0; j < M; j++) sum += ans[i][j];
                int rm = a[i] - sum;
                for(int j = 0; j < M; j++) {
                    ans[i][j] = ans[i][j] + rm;
                    if(ans[i][j] > 9) { rm = ans[i][j] - 9; ans[i][j] = 9; }
                    else rm = 0;
                }
            }
        }
        int m = M - 1;
        while(m >= 0 && ans[i][m] == 0) m--;
        for(int j = m; j >= 0; j--)
            printf("%d", ans[i][j]);
        printf("\n");
    }
    return 0;
}

