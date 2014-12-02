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

int tb[205], a[405], tmp[405], nxt[405];

int main() {
    int t;
    //freopen("d.in", "r", stdin);
    scanf("%d", &t);
    while(t--) {
        int n, m, i, j, ans = 0;
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        memset(nxt, -1, sizeof(nxt));
        memset(tmp, -1, sizeof(tmp));
        for(i = m - 1; i >= 0; i--) {
            nxt[i] = tmp[a[i]];
            tmp[a[i]] = i;
        }
        memset(tb, -1, sizeof(tb));
        for(i = 0; i < m; i++) {
            // check if has exist
            for(j = 0; j < n; j++)
                if(tb[j] != -1 && a[tb[j]] == a[i]) break;
            if(j < n) {
                tb[j] = i;
                continue;
            }
            // check empty table
            for(j = 0; j < n; j++)
                if(tb[j] == -1) break;
            if(j < n) {
                tb[j] = i;
                ans ++;
                continue;
            }
            // check the one that never back
            for(j = 0; j < n; j++)
                if(nxt[tb[j]] == -1)
                    break;
            if(j < n) {
                tb[j] = i;
                ans ++;
                continue;
            }
            // check the most late one, and replace it
            int tm = nxt[tb[0]], ti = 0;
            for(j = 1; j < n; j++) {
                if(nxt[tb[j]] > tm) {
                    tm = nxt[tb[j]];
                    ti = j;
                }
            }
            ans ++;
            tb[ti] = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}

