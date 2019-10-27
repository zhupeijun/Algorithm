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
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = -1;
    if (a >= 1 && a <= 9 && b >= 1 && b <= 9) {
        ans = a * b;
    }
    printf("%d\n", ans);
    return 0;
}

