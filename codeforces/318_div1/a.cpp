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

const int N = 100005;

int a[N];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int g = a[0];
    for(int i = 1; i < n; ++i)
        g = gcd(g, a[i]);

    bool ans = true;
    for(int i = 0; i < n; ++i) {
        int r = a[i] / g;
        while(r % 3 == 0) r /= 3;
        while(r % 2 == 0) r /= 2;
        if (r != 1) { ans = false; break; }
    }

    printf("%s\n", ans ? "Yes" : "No");
    return 0;
}

