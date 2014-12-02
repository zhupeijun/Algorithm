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

const int N = 300005;
const int MOD = 1000000009;

struct tnode {
    LL a0;
    LL a1;
    LL sum;
} tr[N * 4];

LL fib[N], a[N];

LL get_fib(LL a0, LL a1, LL n) {
    return n == 1 ? a0 :
        ((a0 * fib[n - 2]) % MOD + (a1 * fib[n - 1]) % MOD) % MOD;
}

LL get_sum(LL a0, LL a1, LL n) {
    return ((fib[n] * a0) % MOD + ((fib[n + 1] - 1) * a1) % MOD);
}

void init(LL k, LL L, LL R) {
    LL i = k << 1;
    LL mid = (L + R) / 2;
    if(L == R) tr[k].sum = a[L];
    else {
        init(i, L, mid);
        init(i + 1, mid + 1, R);
        tr[k].sum = (tr[i].sum + tr[i + 1].sum) % MOD;
    }
    tr[k].a0 = tr[k].a1 = 0;
}

void down(LL k, LL L, LL R) {
    if(tr[k].a0 == 0) return ;
    if(L == R) {
        tr[k].sum = (tr[k].sum + tr[k].a0) % MOD;
        tr[k].a0 = tr[k].a1 = 0;
        return ;
    }
    LL i = k << 1;
    LL mid = (L + R) / 2;
    tr[i].a0 = (tr[i].a0 + tr[k].a0) % MOD;
    tr[i].a1 = (tr[i].a1 + tr[k].a1) % MOD;
    LL b0 = get_fib(tr[k].a0, tr[k].a1, (R - L + 2) / 2 + 1);
    LL b1 = get_fib(tr[k].a0, tr[k].a1, (R - L + 2) / 2 + 2);
    tr[i + 1].a0 = (tr[i + 1].a0 + b0) % MOD;
    tr[i + 1].a1 = (tr[i + 1].a1 + b1) % MOD;
    LL sum = get_sum(tr[k].a0, tr[k].a1, R - L + 1);
    tr[k].sum = (tr[k].sum + sum) % MOD;
    tr[k].a0 = tr[k].a1 = 0;
}

void update(LL k, LL L, LL R, LL l, LL r, LL a0, LL a1) {
    if(l > R || r < L) return ;
    down(k, L, R);
    if(l <= L && r >= R) {
        int b0 = get_fib(a0, a1, L - l + 1);
        int b1 = get_fib(a0, a1, L - l + 2);
        tr[k].a0 = (tr[k].a0 + b0) % MOD;
        tr[k].a1 = (tr[k].a1 + b1) % MOD;
        down(k, L, R);
        return ;
    }
    LL i = k << 1;
    LL mid = (L + R) / 2;
    down(i, L, mid);
    down(i + 1, mid + 1, R);
    update(i, L, mid, l, r, a0, a1);
    update(i + 1, mid + 1, R, l, r, a0, a1);
    tr[k].sum = (tr[i].sum + tr[i + 1].sum) % MOD;
}

LL query(LL k, LL L, LL R, LL l, LL r) {
    if(l > R || r < L) return 0;
    down(k, L, R);
    if(l <= L && r >= R) {
        return tr[k].sum;
    }
    LL i = k << 1;
    LL mid = (L + R) / 2;
    down(i, L, mid);
    down(i + 1, mid + 1, R);
    return (query(i, L, mid, l, r) + query(i + 1, mid + 1, R, l, r)) % MOD;
}

void debug(int k, int L, int R) {
    cout << k << " " << L << " "<< R << " " << tr[k].a0 << " " << \
        tr[k].a1 << " " << tr[k].sum << endl;
    if(L == R) return ;
    int i = k << 1;
    int mid = (L + R) / 2;
    debug(i, L, mid);
    debug(i + 1, mid + 1, R);
}


int main() {
    LL i, n, m, l, r, q;
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i < N;i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    scanf("%I64d%I64d", &n, &m);
    for(i = 0;i < n;i ++)
        scanf("%I64d", &a[i]);

    init(1, 0, n - 1);

    for(i = 0; i < m; i++) {
        scanf("%I64d%I64d%I64d", &q, &l, &r);
        if(q == 1) {
            update(1, 0, n - 1, l - 1, r - 1, 1, 1);
        }
        else if(q == 2) {
            int res = query(1, 0, n - 1, l - 1, r - 1);
            printf("%I64d\n", res);
        }
        //debug(1, 0, n -1);
    }
    return 0;
}

