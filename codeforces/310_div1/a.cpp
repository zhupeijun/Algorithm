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

vector<int> a[100005];

int main() {
    int n, k, m1, m2, mi;
    m1 = m2 = 100005;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            a[i].pb(x);
        }
        if(a[i][0] < m1) { mi = i; m2 = m1; m1 = a[i][0]; }
        else if(a[i][0] < m2) { m2 = a[i][0]; }
    }
    if(n == 0) printf("0\n");
    else {
        int m = a[mi].size(), i;
        for(i = 0; i < m; i++) {
            if(a[mi][i] > m2) break;
        }
        int ans = (n - k + 1 - i) + (m - i + n - m);
        printf("%d\n", ans);
    }
    return 0;
}

