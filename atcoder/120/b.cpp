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
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int max_value = min(a, b);
    for (int i = max_value; i >= 1; --i) {
        if ((a % i == 0) && (b % i == 0)) {
            --k;
        }
        if (k == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

