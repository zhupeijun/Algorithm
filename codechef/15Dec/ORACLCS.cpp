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

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 105;

void solve() {
    int n, m;
    scanf("%d", &n);
    int min_an = MAXN, min_bn = MAXN;
    for (int i = 0; i < n; ++i) {
        char str[105];
        scanf("%s", str);
        int an = 0, m = strlen(str);
        for (int j = 0; j < m; ++j) an += (str[j] == 'a');
        min_an = min(min_an, an);
        min_bn = min(min_bn, m - an);
    }
    printf("%d\n", min(min_an, min_bn));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

