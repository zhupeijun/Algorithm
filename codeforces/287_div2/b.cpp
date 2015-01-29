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

#define sqr(x) ((x) * (x))

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int x1, y1, x2, y2, r;
    scanf("%d %d %d %d %d", &r, &x1, &y1, &x2, &y2);
    double dis = sqrt(sqr(1LL * x2 - x1) + sqr(1LL * y2 - y1));
    int d = r * 2;
    int n = ceil((dis - d) / d) + 1;
    printf("%d\n", n);
    return 0;
}

