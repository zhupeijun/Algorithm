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

typedef long long LL;

using namespace std;

const int N = 2005;

LL d1[N * 2], d2[N * 2], ans[2];
pair<int, int> cells[2];
int a[N][N];

int main() {
    int n;
    scanf("%d", &n);
    int m = n * 2;
    for(int i = 0; i < m; i++) d1[i] = d2[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            d1[i + j] += a[i][j];
            d2[n - i + j - 1] += a[i][j];
        }

    ans[0] = ans[1] = 0;
    cells[0] = make_pair(1, 1);
    cells[1] = make_pair(2, 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            LL sum = d1[i + j] + d2[n - i + j - 1] - a[i][j];
            if((i + j) & 1) {
                if(sum > ans[0]) {
                    ans[0] = sum;
                    cells[0] = make_pair(i + 1, j + 1);
                }
            } else {
                if(sum > ans[1]) {
                    ans[1] = sum;
                    cells[1] = make_pair(i + 1, j + 1);
                }
            }
        }

    printf("%I64d\n", ans[0] + ans[1]);
    printf("%d %d %d %d\n", cells[0].first, cells[0].second, cells[1].first,
        cells[1].second);
    return 0;
}

