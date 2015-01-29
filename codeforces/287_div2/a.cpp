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

struct instrument {
    int t, i;
    bool operator < (const instrument & other) const {
        return t < other.t;
    }
} d[105];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i =0; i < n; i++) {
        scanf("%d", &d[i].t);
        d[i].i = i;
    }
    sort(d, d + n);
    int t, sum = 0;
    for(t = 0; t < n; t++)
        if(sum + d[t].t <= k) sum += d[t].t;
        else break;
    printf("%d\n", t);
    for(int i = 0; i < t; i++) {
        printf("%d", d[i].i + 1);
        if(i == t - 1) printf("\n");
        else printf(" ");
    }
    return 0;
}

