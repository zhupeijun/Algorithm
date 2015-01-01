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

const int N = 55;
int l[N], r[N];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);

    int cur = 1, ans = 0;
    for(int i = 0; i < n; i++) {
        int rm = l[i] - cur;
        rm = rm % x;
        cur = r[i] + 1;
        ans += rm + r[i] - l[i] + 1;
    }
    printf("%d\n", ans);
    return 0;
}

