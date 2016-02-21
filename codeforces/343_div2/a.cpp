#include <iostream>

using namespace std;

char cake[105][105];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", cake[i]);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) cnt += cake[i][j] == 'C';
        if (cnt > 1) ans += cnt * (cnt - 1) / 2;
    }
    for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += cake[i][j] == 'C';
        if (cnt > 1) ans += cnt * (cnt - 1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}
