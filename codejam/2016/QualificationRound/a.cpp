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

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

int solve() {
    int N;
    scanf("%d", &N);
    if (N == 0) return -1;
    int vis[10] = { 0 };
    int k = 1;
    while (true) {
        int x = N * k;
        while (x) {
            vis[x % 10] = 1;
            x /= 10;
        }
        bool all_visited = true;
        for (int i = 0; i < 10; ++i) {
            if (vis[i] == 0) { all_visited = false; break; }
        }
        if (all_visited) return N * k;
        ++k;
    }
    return -1;
}

int main() {
    int case_i, case_n;
    scanf("%d", &case_n);
    for (int case_i = 1; case_i <= case_n; ++case_i) {
        int ans = solve();
        printf("Case #%d: ", case_i);
        if (ans == -1) printf("INSOMNIA");
        else printf("%d", ans);
        printf("\n");
    }
    return 0;
}

