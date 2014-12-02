#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int to[4][2] = { 
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

int vit[305][305];
vector<int> ans[50005];

int main() {
    int n, m, k, x, y, cnt, tot, i, j, to_x, to_y, to_d, ak;
    scanf("%d %d %d", &n, &m, &k);
    memset(vit, 0, sizeof(vit));
    x = 0; y = 0; tot = n * m; cnt = to_d = ak = 0;
    while(cnt < tot) {
        vit[x][y] = 1;
        if(cnt % 2 == 0 && ak < k) ak++;
        ans[ak].push_back(x);
        ans[ak].push_back(y);
        int to_x = to[to_d][0] + x;
        int to_y = to[to_d][1] + y;
        if(to_x < 0 || to_x >= n || to_y < 0 || to_y >= m || 
            vit[to_x][to_y] == 1) {
            to_d = (to_d + 1) % 4;
        }
        x = to[to_d][0] + x;
        y = to[to_d][1] + y;
        cnt++;
    }
    for(i = 1; i <= k;i++) {
        int sz = ans[i].size();
        printf("%d ", sz / 2);
        for(j = 0; j < sz; j++) {
            printf("%d", ans[i][j] + 1);
            if(j == sz - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
