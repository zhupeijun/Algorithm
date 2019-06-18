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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int W, H, x, y;
    scanf("%d %d %d %d", &W, &H, &x, &y);
    double area = 1.0 * W * H / 2;
    int multi = 0;
    if (W % 2 == 0 && H % 2 == 0 && x == W / 2 && y == H / 2) {
        multi = 1;
    }
    printf("%lf %d\n", area, multi);
    return 0;
}

