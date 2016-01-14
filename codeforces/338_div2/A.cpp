#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

bool exist[105];

int main() {
    int n, m, cnt = 0;
    CL(exist, false);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            scanf("%d", &y);
            if (!exist[y]) { exist[y] = true; ++cnt; }
        }
    }
    if (cnt == m) printf("YES\n");
    else printf("NO\n");
    return 0;
}
