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
        int n;
        scanf("%d", &n);
        int sum = 0, minv = 100000005;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x < minv) minv = x;
            sum += x;
            if (x == 1) ok = false;
        }
        int ans = 0;
        if (ok) ans = sum - minv + 2;
        else ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

