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

int v[55];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v, v + N);
    long long base = 2;
    double result = 0;
    for (int i = N - 1; i >= 0; --i) {
        result += 1.0 * v[i] / base;
        if (i > 1) {
            base *= 2;
        }
    }
    printf("%lf\n", result);
    return 0;
}

