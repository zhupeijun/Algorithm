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

const int N = 100005;
int a[N];

ll sum(int x,int y) {
    if(x > y) return 0;
    return 1LL * (x + y) * (y - x + 1) / 2;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; i++)
            scanf("%d", &a[i]);
        sort(a, a + k);
        ll tot = 0;
        int cur = 0;
        for(int i = 0; i < k; i++) {
            if(a[i] - cur > 1) {
                if(cur > tot) break;
                tot += sum(cur + 1, a[i] - 1);
            }
            cur = a[i];
        }
        if(cur <= tot)
            tot += sum(cur + 1, n);
        if(tot & 1) printf("Mom\n");
        else printf("Chef\n");
    }
    return 0;
}

