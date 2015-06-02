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
#include <functional>

typedef long long LL;

using namespace std;

int c[3][105];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int cn[3], m;
        scanf("%d %d %d %d", &cn[0], &cn[1], &cn[2], &m);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < cn[i]; j++)
                scanf("%d", &c[i][j]);
            sort(c[i], c[i] + cn[i], greater<int>());
        }

        for(int k = 0; k < m; k++) {
            int idx = 0, maxv = 0;
            for(int i = 0; i < 3; i++)
                if(c[i][0] > maxv) { maxv = c[i][0]; idx = i; }
            for(int j = 0; j < cn[idx]; j++)
                c[idx][j] /= 2;
        }
        printf("%d\n", max(c[0][0], max(c[1][0], c[2][0])));
    }
    return 0;
}

