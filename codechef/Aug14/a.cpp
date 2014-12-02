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

typedef long long LL;

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, i, a, cnt = 0;
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++) {
            scanf("%d", &a);
            if((a & 1) == 0) cnt++;
        }
        if(cnt < k || (cnt == n && k == 0)) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

