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

int a[15][15];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || j == 1) a[i][j] = 1;
            else a[i][j] = a[i - 1][j] + a[i][j - 1];
            ans = max(a[i][j], ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}

