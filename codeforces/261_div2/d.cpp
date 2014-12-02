//Codeforces 261 Div1
//BIT
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

const int N = 1000005;

int fl[N], fr[N], a[N];
LL bit[N];

map<int, int> M;

LL sum(int i) {
    LL res = 0;
    while(i) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

void add(int i, int n, int v) {
    while(i <= n) {
        bit[i] += v;
        i += i & -i;
    }
}


int main() {
    int i, n;
    LL ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if(n == 1) {
        printf("0\n");
        return 0;
    }
    for(i = 0; i < n; i++) {
        M.find(a[i]) == M.end() ? M[a[i]] = 1 : M[a[i]] ++;
        fl[i] = M[a[i]];
    }
    M.clear();
    for(i = n - 1; i >= 0; i--) {
        M.find(a[i]) == M.end() ? M[a[i]] = 1 : M[a[i]] ++;
        fr[i] = M[a[i]];
    }
    memset(bit, 0, sizeof(bit));
    add(fr[n - 1], n, 1);
    for(i = n - 2; i >= 0; i--) {
        ans += fl[i] == 1 ? 0 : sum(fl[i] - 1);
        add(fr[i], n, 1);
    }
    printf("%I64d\n", ans);
    return 0;
}

