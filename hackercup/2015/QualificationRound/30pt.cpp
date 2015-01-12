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

const int N = 25;

int p[N], c[N], f[N];

int main() {
    freopen("30pt.in", "r", stdin);
    freopen("30pt.out", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 0; ci < cn; ci++) {
        int gp, gc, gf, n;
        scanf("%d %d %d", &gp, &gc, &gf);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d %d", &p[i], &c[i], &f[i]);
        int m = 1 << n;
        bool ans = false;
        for(int k = 0; k < m; k++) {
            int j = 0, x = k, sp, sc, sf;
            sp = sc = sf = 0;
            while(x) {
                if(x & 1) {
                    sp += p[j]; sc += c[j]; sf +=f[j];
                }
                j++; x >>= 1;
            }
            if(sp == gp && sc == gc && sf == gf) { ans = true; break; }
        }
        printf("Case #%d: ", ci + 1);
        if(ans) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

