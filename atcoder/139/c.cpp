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
    int N;
    scanf("%d", &N);
    int prev = INT_MAX;
    int max_move = 0, cnt = -1;
    for (int i = 0; i < N; ++i) {
        int h;
        scanf("%d", &h);
        if (h <= prev) {
            ++cnt;
        } else {
            cnt = 0;
        }
        prev = h;
        max_move = max(max_move, cnt);
    }
    printf("%d\n", max_move);
    return 0;
}

