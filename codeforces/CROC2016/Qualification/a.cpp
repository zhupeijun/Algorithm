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
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

int res[105][105];

int main() {
    int a, b, n;
    scanf("%d %d %d", &n, &a, &b);
    if (n > a * b) printf("-1\n");
    else {
        CL(res, 0);
        int delta = 1;
        for (int i = 1, j = 0, k = 0; i <= n; ++i) {
            res[j][k] = i;
            if ((delta == 1 && k == b - 1) || (delta == -1 && k == 0)) { ++j, delta = -delta; }
            else k += delta;
        }
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                printf("%d", res[i][j]);
                printf(j == b - 1 ? "\n" : " ");
            }
        }
    }
    return 0;
}

