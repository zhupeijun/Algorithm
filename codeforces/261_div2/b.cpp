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

typedef long long LL;

using namespace std;

#define OUTS "%I64d %I64d\n"

const int N = 200005;

int a[N];

int main() {
    int n, i, m1, m2;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    m1 = m2 = 0;
    for(i = 0; i < n; i++)
        if(a[i] == a[0]) m1 ++;
        else break;
    if(i == n) {
        printf(OUTS, 0LL, (1LL * n * (n - 1)) / 2);
        return 0;
    }
    for(i = n - 1; i >= 0; i--)
        if(a[i] == a[n - 1]) m2++;
        else break;
    printf(OUTS, 0LL + a[n - 1] - a[0], 1LL * m1 * m2);
    return 0;
}

