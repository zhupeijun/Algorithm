#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;

using namespace std;

const int MAXN = 100005;

struct Pt {
    int i, p;
    bool operator < (const Pt & a) const {
        return p < a.p;
    }
} fg[MAXN];

int st[MAXN];

int main() {
    int N, K, P, i, p, k;
    scanf("%d %d %d", &N, &K, &P);
    for(i = 0; i < N; i++) {
        scanf("%d", &p);
        fg[i].i = i; fg[i].p = p;
    }
    sort(fg, fg + N);
    k = 0; st[0] = 0;
    for(i = 1; i < N; i++) {
        if(fg[i].p - fg[i - 1].p > K) {
            k++;
        }
        st[fg[i].i] = k;
    }
    for(i = 0; i < P; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(st[a - 1] != st[b - 1]) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

