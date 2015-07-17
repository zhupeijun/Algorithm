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
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ll ans = a;
        int c5 = 0, c2 = 0;
        while(a % 5 == 0) { c5++; a /= 5; }
        while(a % 2 == 0) { c2++; a /= 2; }
        if(c5 > c2) {
            int need = ((c5 - c2) + 1) / 2;
            while(need--) ans *= 4;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

