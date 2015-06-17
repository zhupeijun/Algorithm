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

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll ans = 0;
        int n, cur = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            if(m > cur) ans = ans + (m - cur);
            cur = m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

