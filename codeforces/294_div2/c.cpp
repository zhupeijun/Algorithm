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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int tot = n + m;
    int maxt = tot / 3;
    int ans = 0;
    for(int i = 0; i <= maxt; i++) {
        if (n - i < 0) continue;
        int t1 = (n - i) / 2;
        if(m - 2 * i < 0) continue;
        int t2 = m - 2 * i;
        int t = min(t1, t2);
        if(i + t > ans) ans = i + t;
    }
    printf("%d\n", ans);
    return 0;
}

