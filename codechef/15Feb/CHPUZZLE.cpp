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

#define fst first
#define sec second
#define mp make_pair
#define pb push_back

int res[1005][1005];

int main() {
    int w, h, k;
    scanf("%d %d %d", &h, &w, &k);
    memset(res, 0, sizeof(res));
    int curx = 1;
    for(int i = 0; i < k; i++) {
        int m;
        scanf("%d", &m);
        vector<pii> fig;
        int minx = w, maxx = -1;
        for(int j = 0; j < m; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            fig.pb(mp(x - 1, y - 1));
            minx = min(x, minx);
            maxx = max(x, maxx);
        }
        if(maxx != -1 && h - curx >= (maxx - minx + 1)) {
            for(int j = 0; j < m; j++) {
                res[fig[j].fst + curx - 1][fig[j].sec] = i + 1;
            }
            curx += (maxx - minx + 1);
        }
    }
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) {
            printf("%d", res[i][j]);
            if (j == w - 1) printf("\n");
            else printf(" ");
        }
    return 0;
}

