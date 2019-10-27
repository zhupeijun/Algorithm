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
    long double res = 0;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int a;
        long double value = 1;
        scanf("%d", &a);
        value = value / a;
        res += value;
    }
    printf("%Lf\n", 1 / res);
    return 0;
}

