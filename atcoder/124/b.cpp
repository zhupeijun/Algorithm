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
    int n;
    scanf ("%d", &n);
    int max_height = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        scanf ("%d", &h);
        if (h >= max_height) {
            ++total;
            max_height = max(max_height, h);
        }
    }
    printf("%d\n", total);
    return 0;
}

