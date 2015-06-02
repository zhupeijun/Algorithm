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

const int N = 100005;

int a[N];

int main() {
    int n, m, i, x1, x2, i1, i2;
    scanf("%d", &n);
    m = n / 2;
    x1 = -1; x2 = 1e9 + 5;
    i1 = i2 = -1;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(i < m) {
            if(x1 < a[i]) {
                x1 = a[i];
                i1 = i;
            }
        }
    }
    if(a[i1] <= a[m])
        printf("0\n");
    else {
        printf("1\n");
        printf("%d %d\n", i1 + 1, m + 1);
    }
    return 0;
}

