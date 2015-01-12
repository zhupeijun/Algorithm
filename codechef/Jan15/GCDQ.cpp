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

typedef long long ll;

using namespace std;

const int N = 100005;

int a[N], gh[N], gt[N];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        gh[0] = a[0];
        for(int i = 1; i < n; i++)
            gh[i] = gcd(gh[i - 1], a[i]);
        gt[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            gt[i] = gcd(gt[i + 1], a[i]);
        for(int k = 0; k < q; k++) {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans;
            if(l > 1 && r < n)
                ans = gcd(gh[l - 2], gt[r]);
            else if(l > 1)
                ans = gh[l - 2];
            else
                ans = gt[r];
            printf("%d\n", ans);
        }
    }
    return 0;
}

