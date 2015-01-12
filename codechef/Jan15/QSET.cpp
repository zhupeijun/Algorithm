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

const int N = 100005;

struct tnode {
    ll h[3];
    ll t[3];
    ll rem;
    ll ans;

    tnode() { init(); }
    void init() {
        for(int i = 0; i < 3; i++) h[i] = t[i] =0;
        rem = ans = 0;
    }
} tr[N * 4];

char a[N];

void debug(int k, int L, int R) {
    cout << L << "," << R << " " << tr[k].ans << ",";
    for(int i = 0; i < 3; i++) cout << tr[k].h[i] << ",";
    for(int i = 0; i < 3; i++) cout << tr[k].t[i] << ",";
    cout << tr[k].rem << endl;
}

tnode merge(tnode n1, tnode n2) {
    tnode rn;
    //head
    for(int t = 0; t < 3; t++) {
        int rem = (n1.rem + t) % 3;
        rn.h[rem] += n2.h[t];
        rn.h[t] += n1.h[t];
    }

    //tail
    for(int t = 0; t < 3; t++) {
        int rem = (n2.rem + t) % 3;
        rn.t[rem] += n1.t[t];
        rn.t[t] += n2.t[t];
    }

    //ans
    rn.ans = n1.ans + n2.ans;
    for(int t = 0; t < 3; t++) {
        rn.ans += 1LL * n1.t[t] * n2.h[(3 - t) % 3];
    }

    //rem
    rn.rem = (n1.rem + n2.rem) % 3;
    return rn;
}

void cal(int k, int L, int R) {
    int i = k << 1;
    if(L == R) {
        int v = a[L] - '0';
        int r = v % 3;
        tr[k].init();
        tr[k].h[r] = 1;
        tr[k].t[r] = 1;
        if(r == 0) tr[k].ans = 1;
        tr[k].rem = r;
    } else {
        tr[k] = merge(tr[i], tr[i + 1]);
    }
}

void init(int k, int L, int R) {
    int i = k << 1;
    int mid = (L + R) / 2;
    if(L != R) {
        init(i, L, mid);
        init(i + 1, mid + 1, R);
    }
    cal(k, L, R);
    //debug(k, L, R);
}

void update(int k, int L, int R, int p) {
    int i = k << 1;
    int mid = (L + R) / 2;
    if(L != R) {
        if(p > mid) update(i + 1, mid + 1, R, p);
        else update(i, L, mid, p);
    }
    cal(k, L, R);
    //debug(k, L, R);
}

tnode query(int k, int L, int R, int l, int r) {
    int i = k << 1;
    int mid = (L + R) / 2;
    if(l <= L && r >= R) return tr[k];
    else if(r <= mid) return query(i, L, mid, l, r);
    else if(l > mid) return query(i + 1, mid + 1, R, l, r);
    else {
        tnode n1 = query(i, L, mid, l, r);
        tnode n2 = query(i + 1, mid + 1, R, l, r);
        return merge(n1, n2);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", a);
    init(1, 0, n - 1);
    int q, x, y;
    for(int k = 0; k < m; k++) {
        scanf("%d %d %d", &q, &x, &y);
        if(q == 1) {
            a[x - 1] = y + '0';
            //cout << a << endl;
            update(1, 0, n - 1, x - 1);
        } else {
            tnode r = query(1, 0, n - 1, x - 1, y - 1);
            printf("%lld\n", r.ans);
        }
    }
    return 0;
}

