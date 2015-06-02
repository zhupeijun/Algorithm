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

const int N = 10005;
int s[N], best[N], par[N];

int find(int x) {
    if(par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void combine(int x, int y) {
    x = find(x);
    y = find(y);
    if(best[x] > best[y]) {
        par[y] = x;
    } else if(best[x] < best[y]){
        par[x] = y;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, i, qn;
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            best[i] = s[i];
            par[i] = i;
        }
        scanf("%d", &qn);
        while(qn--) {
            int q, x, y;
            scanf("%d ", &q);
            if(q == 0) {
                scanf("%d %d", &x, &y);
                x--; y--;
                int px = find(x);
                int py = find(y);
                if(px == py)
                    printf("Invalid query!\n");
                else
                    combine(x, y);
            } else {
                scanf("%d", &x);
                x--;
                int px = find(x);
                printf("%d\n", px + 1);
            }
        }
    }
    return 0;
}

